
//This is going to be my first C file
#include <stdio.h> 
 
int main(int argc, char *argv[]) {
	int i = 1;
    if (argc>2){
    	for (i ; i < argc; i++ ) {
    		FILE *file;
    		int a;
    		file = fopen(argv[i], "r");
    		if (file){
    			a = getc(file);
    			while (a!= EOF){
    				printf("%c", a);
    				a = getc(file);
    			}
    				
    				fclose(file);
				}
	
				}
    			
			}
	else {
	printf("my-cat: cannot open file\n");
					}
    return 0;
		}






//FILE *file;
//    int a;
//
//    file =fopen("text.txt", "r"); 
//    if (file) {
//    a = getc(file);
//    while ( a != EOF){
//    	printf("%c", a);
//        a = getc(file);
//}
//   fclose(file);
