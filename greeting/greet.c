#include <stdio.h>
#include <stdlib.h>

int main() {
    // Command to execute
    const char* command = "ls /dev/pts/ | wc -l";

    // Open a pipe to execute the command and capture its output
    FILE* pipe = popen(command, "r");
    if (pipe == NULL) {
        perror("popen");
        return 1;
    }

    // Read the output from the pipe and convert it to an integer
    char buffer[128];
    fgets(buffer, sizeof(buffer), pipe);

    int output = atoi(buffer);

    // Subtract 1 from the output
    int result = output - 1;

         // Different greet depending on n terminals
    switch(result)
    {
        case 1:
            printf("Hello, Kay!\n");
            break;

        case 2:
            printf("Let's get to work then!\n");
            break;

        case 3:
            printf("Oh ish is getting serious now...!\n");
            break;

        case 4:
            printf("GOGO SUPERUSER!\n");
            break;

        default: 
            printf("I guess you don't need me anymore then :?\n");
    }  

    // Print the result using printf
    // printf("Output: %d\n", result);
    

    // Close the pipe
    pclose(pipe);

    return 0;
}
