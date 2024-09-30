#!/bin/bash

# Note: made with help from chatgpt

# Compile
g++ encode.cpp -o encode
g++ decode.cpp -o decode

# Check for the correct number of arguments
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <message>"
    exit 1
fi

MESSAGE=$1

# Check if the executables exist
if [ ! -x "./encode" ] || [ ! -x "./decode" ]; then
    echo "One or both executables do not exist or are not executable."
    exit 1
fi

MIDDLE=$(echo "$MESSAGE" | "./encode")
# Feed the message into exe1, pipe its output into exe2, and capture the final output
FINAL_OUTPUT=$(echo "$MESSAGE" | "./encode" | "./decode")

# Check if the initial message and final output are the same
if [ "$MESSAGE" == "$FINAL_OUTPUT" ]; then
    echo "Success! \"Link\" level message was: $MIDDLE"
else
    echo "Failure."
    echo "Initial message: $MESSAGE"
    echo "Link Level message: $MIDDLE"
    echo "Final output: $FINAL_OUTPUT"
fi
