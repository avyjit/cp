#!/bin/env/bash
ls cpp/*.cpp inputs/*.txt | entr ./runner.sh
ls py/*.py inputs/*.txt | entr ./runnerpy.sh
