#!/bin/bash

# Define a function to compile and run a source file
function compile_and_run {
    num="$1"
    echo "Compiling $num..."
    executable="build/cp${num}"  # Extract the executable name

    rm $executable  # Remove the executable if it exists
    
    # Compile the source file
    g++ -std=c++17 -fsanitize=undefined -fsanitize=address "cpp/cp${num}.cpp" -o "$executable" &> "outputs/output${num}.log"

    # Run only if compilation was successful
    if [ -f "$executable" ]; then
        echo "Running $executable..."
        timeout 2 $executable < "inputs/input${num}.txt" 2>&1 | head -500 > "outputs/output${num}.log"
    else
        echo "Compilation failed for cp$num"
    fi
}

# Define an array of source files
nums=("1" "2" "3" "4")

# Loop through the source files
for num in "${nums[@]}"; do
    compile_and_run "$num" &
done

# Wait for all background processes to finish
wait