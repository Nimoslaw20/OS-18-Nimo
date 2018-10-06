#include <stdio.h> //std C library
#include <stdlib.h> // To enable use of exit()
#include <string.h> // string lib
#include <sys/types.h>
#include <unistd.h>

char **tokenize(char string[]);

int main(){
    char command[100];
    char **args;
    char holder[5] = {'e','x','i','t','\0'};
        do{
            printf("prompt.>>");
            fgets(command,100,stdin);
            puts(command);
            puts(strtok(command, " "));
            args = tokenize(command);
    }while(strcmp(command,holder) != 0);
}

char **tokenize(char string[100])
{
    char *token;
    char **tokens = malloc(64 *sizeof(char));
	
    token = strtok(string," ");
    int i = 0;
    while (token != NULL){
    	//token = strtok(token, "\n");
    	printf("%s", token);
        tokens[i] = token;
       	token = strtok (NULL," ");
        i = i + 1;
    }
    tokens[i] = NULL;
	return tokens;
}
