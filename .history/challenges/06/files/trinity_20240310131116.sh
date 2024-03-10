#!/bin/bash

# Prompt the user with the question
echo "Only lower cases for answers!" 
read -p "What is Linux? " answer

# Check if the user's answer is "kernel"
if [ "$answer" = "kernel" ]; then
    # Display the flag
    echo "Congratulations! Here is your flag location: /home/"
else
    echo "Incorrect answer. Keep exploring!"
fi
