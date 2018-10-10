#include <stdio.h> //std C library
#include <stdlib.h> // To enable use of exit()
#include <string.h> // string lib
#include <sys/types.h>
#include <unistd.h>


char **tokenize(char string[]);
int notBatch();
int Batch();
int mycd(char **myPar);

int main(int argc, char **argv){
    if(argv[1]!=NULL){
    }
    else{
            char *command = NULL;
	    char **args;
	    char *holder = "exit\n";
	    printf("wish> ");
	    size_t length = 0;
	    ssize_t read;
		read = getline(&command, &length, stdin);
		while(strcmp(command,holder) != 0){
			args = tokenize(command);
			mycd(args);
			printf("wish> ");
			read = getline(&command, &length, stdin);
		}
		printf("Done");
		/*do{
		    
		    
		    puts(holder);
		    //puts(strtok(command, " "));
		    //args = tokenize(command);
		    //mycd(args);
	    };*/
	    return 0;
    }
}

int notBatch(){
    char *command;
    char **args;
    char *holder = "exit\n";
    printf("wish> ");
    size_t *length = 0;
    ssize_t read;
	read = getline(&command, length, stdin);
	while(strcmp(command,holder) != 0){
		printf("%s", command);
		printf("wish> ");
		read = getline(&command, length, stdin);
	}
	printf("Done");
        /*do{
            
            
            puts(holder);
            //puts(strtok(command, " "));
            //args = tokenize(command);
            //mycd(args);
    };*/
    return 0;
}

int Batch(){
    return 0;
}

char **tokenize(char string[100])
{
    char *token;
    char **tokens = malloc(64 *sizeof(char));
	
    token = strtok(string," ");
    int i = 0;
    while (token != NULL){
    	//token = strtok(token, "\n");
    	//printf("%s", token);
        tokens[i] = token;
       	token = strtok (NULL," ");
        i = i + 1;
    }
    tokens[i] = NULL;
	return tokens;
}

int mycd(char **myPar){
    char *myText = "cd";//check how to use fork here.
    printf("%s\n", myPar[1]);
    if(memcmp(myPar[1], myText, 2)==0){
        if(myPar[2]==NULL)
            return 1;
        else
            chdir(myPar[2]);//check how to wait and exec here
    }
    return 0;    
}


