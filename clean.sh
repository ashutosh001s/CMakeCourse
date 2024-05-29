#!/bin/bash

# List of files and directories to remove
to_remove=(CMakeCache.txt CMakeFiles Makefile *.sln *.vcxproj *.xcodeproj build *.ninja *.cmake)

# Function to recursively delete items
delete_recursive() {
    for item in "${to_remove[@]}"; do
        find "$1" -name "$item" -exec rm -rf {} +
    done
}

# Start from the current directory
delete_recursive .
