#!/bin/bash

# Prompt the user with the question
echo "Only lower cases for answers!" 
read -p "What is Linux? " answer

# Check if the user's answer is "kernel"
if [ "$answer" = "kernel" ]; then
    # Display the flag
    echo "Congratulations! Here is the flag: FLAG_L1NUX_K3RNEL"
else
    echo "Incorrect answer. Keep exploring!"
fi
