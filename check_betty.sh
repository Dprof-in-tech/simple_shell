#!/bin/bash

# Run Betay on all C files in the current directory
for file in *.c; do
    betty $file
done
