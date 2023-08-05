#include <stdio.h>
#include <stdlib.h>


int main()
{
 
    //Shell command to execute 
    const char* command = "ls /dev/tty/ | wc -l";

    // Open a pipe to execute the command and capture its output
    FILE* pipe = popen(command, "r"); 
    if(pipe == NULL)
    {
        perror("popen");
        return 1;
    }
    
    int result;
    // Read the output from the pipe and convert to integer
    char buffer[128];
    fgets(buffer, sizeof(buffer), pipe);
    int output = atoi(buffer);
    // Subtract 1 from the output 
    result = output -1; 
    

    // Close the pipe
    pclose(pipe);

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

    return(0);
}
