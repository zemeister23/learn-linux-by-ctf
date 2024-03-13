#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_QUESTIONS 16

// Structure to hold a question and its corresponding answer
struct Question {
    char *question;
    char *answer;
};

// Function to initialize questions and answers
void initializeQuestions(struct Question questions[]) {
    questions[0].question = "What is Linux?";
    questions[0].answer = "kernel";
    questions[1].question = "What is the Linux operating system known for? <few words>";
    questions[1].answer = "open source";
    questions[2].question = "What is Kali Linux primarily used for? <few words>";
    questions[2].answer = "penetration testing";
    questions[3].question = "How do you navigate directories in the command line?";
    questions[3].answer = "cd";
    questions[4].question = "What command is used to list files in a directory?";
    questions[4].answer = "ls";
    questions[5].question = "How do you display the contents of a file in the command line?";
    questions[5].answer = "cat";
    questions[6].question = "What are manuals in Linux?";
    questions[6].answer = "documentation";
    questions[7].question = "How do you use the 'man' command to get help for a command_example?";
    questions[7].answer = "man command_example";
    questions[8].question = "What does '-h' option typically do in Linux commands?";
    questions[8].answer = "help";
    questions[9].question = "What does FHS stand for in the context of Linux filesystem <few words>";
    questions[9].answer = "filesystem hierarchy standard";
    questions[10].question = "How do you display system information using variables in Linux?";
    questions[10].answer = "echo";
    questions[11].question = "Create a new file in Linux with name examplefile? <few words>";
    questions[11].answer = "touch examplefile";
    questions[12].question = "Remove a examplefile in Linux? <few words>";
    questions[12].answer = "rm examplefile";
    questions[13].question = "How do you use wildcards to match filenames in Linux? <few words>";
    questions[13].answer = "* ?";
    questions[14].question = "How do you find files in Kali Linux?";
    questions[14].answer = "find";
    questions[15].question = "How do you redirect output from a command to a file in Linux?";
    questions[15].answer = ">";
}

// Function to swap two questions in the array
void swap(struct Question *q1, struct Question *q2) {
    struct Question temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}

// Function to shuffle the questions array
void shuffleQuestions(struct Question questions[]) {
    srand(time(NULL));
    for (int i = NUM_QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&questions[i], &questions[j]);
    }
}

int main() {
    printf("Im sorry Neo, but you have to answer some questions to prove your knowledge. Are you ready?\n");

    struct Question questions[NUM_QUESTIONS];
    initializeQuestions(questions);
    shuffleQuestions(questions);

    int correct_answers = 0;
    char input[100];

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s ", questions[i].question);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
        if (strcmp(input, questions[i].answer) == 0) {
            correct_answers++;
        } else {
            printf("Incorrect answer: Answer is %s\n", questions[i].answer);
        }
    }

    if (correct_answers == NUM_QUESTIONS) {
        printf("Please enter the keyword to proceed: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
        if (strcmp(input, "neo_your_key_is_reality") == 0) {
            printf("Congratulations Neo! You have proven your knowledge.\n");
            printf("The truth is within your reach. Take your flag: {{flag}}\n");
        } else {
            printf("Incorrect keyword. Access denied. Repeat\n");
        }
    } else {
        printf("You did not answer all questions correctly. Access denied.\n");
    }

    return 0;
}
