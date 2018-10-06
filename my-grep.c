#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            return i;
    }
	return -1;
}

int main(int argc,  char *argv[]) {
	if (argc > 1){
		int i = 2;
    	for (i ; i < argc; i++ ) {		
    		FILE *file;
    		char line[256];
    		
    		file = fopen(argv[i], "r");
    		if  (file  == NULL){    		
    			printf("my-grep: cannot open file\n");    			
    			exit(0);
			}
			while (fgets(line, sizeof(line), file)) {
    			int x = search(argv[1], line);
			//printf("%d", x);
    			if (x >= 0){
    				printf("%s", line);
			}

    		}
			fclose(file);		
		}
	}
	else{
		printf("Provide parameters please..");
	}	
	return 0;
}
