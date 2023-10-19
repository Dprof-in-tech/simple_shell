#!/bin/bash

# Initialize a variable to track whether strtok was found
strtok_found=0

# Use the find command to locate all C source code files
# in the current directory and its subdirectories
find "$(pwd)" -type f -name "*.c" | while read -r file; do
    # Use grep to search for the "strtok" string in each file
    if grep -q "strtok" "$file"; then
        echo "File: $file uses strtok"
        strtok_found=1
    fi
done

# Check whether strtok was found and display a message
if [ "$strtok_found" -eq 0 ]; then
    echo "No code in this directory uses strtok."
fi
