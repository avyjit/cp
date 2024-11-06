#!/bin/bash

# Define a function to compile and run a source file
function compile_and_run {
    num="$1"
    echo Running...
    timeout 2 pypy3 "py/cp${num}.py" < "inputs/input${num}.txt" 2>&1 | head -500 > "outputs/output${num}.log" 
}

# Define an array of source files
nums=("1" "2" "3" "4")

# Loop through the source files
for num in "${nums[@]}"; do
    compile_and_run "$num" &
done

# Wait for all background processes to finish
wait