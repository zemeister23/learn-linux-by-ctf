#!/bin/bash

# Define an associative array to store questions and their corresponding correct answers


declare -A questions=(
    ["What is Linux?"]="kernel"
    ["What is the Linux operating system known for? <few words>"]="open source"
    ["What is Kali Linux primarily used for? <few words>"]="penetration testing"
    ["How do you navigate directories in the command line?"]="cd"
    ["What command is used to list files in a directory?"]="ls"
    ["How do you display the contents of a file in the command line?"]="cat"
    ["What are manuals in Linux?"]="documentation"
    ["How do you use the 'man' command to get help for a command_example?"]="man command_example"
    ["What does '-h' option typically do in Linux commands?"]="help"
    ["What does FHS stand for in the context of Linux filesystem <few words>"]="filesystem hierarchy standard"
    ["How do you display system information using variables in Linux?"]="echo"
    ["Create a new file in Linux with name examplefile? <few words>"]="touch examplefile"
    ["Remove a examplefile in Linux? <few words>"]="rm examplefile"
    ["How do you use wildcards to match filenames in Linux? <few words>"]="* ?"
    ["How do you find files in Kali Linux?"]="find"
    ["How do you redirect output from a command to a file in Linux?"]=">"
)

# Initialize a variable to track the number of correct answers
correct_answers=0

# Loop through the questions and ask each one
for question in "${!questions[@]}"; do
    read -p "$question " answer
    
    # Check if the answer is correct
    if [ "$answer" = "${questions[$question]}" ]; then
        ((correct_answers++))
    else
        echo "Incorrect answer: Answer is ${questions[$question]}"
    fi
done

# Check if at least 15 answers are correct
if [ $correct_answers -ge 15 ]; then
    # Create the .flag.txt file with "{{flag}}" content
    
    echo "Neo its done. Find the flag in e world!"
else
    echo "You did not answer at least 15 questions correctly. No flag file created."
fi
