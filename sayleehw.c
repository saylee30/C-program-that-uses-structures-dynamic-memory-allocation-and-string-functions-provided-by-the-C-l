#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct data
{
   char* word;
   int count;
};


int main(int argc, char** argv){
    int i;
    struct data* file = (struct data*) malloc(argc* sizeof(struct data));
    for(i = 0; i < argc-1; i++){
       file[i].word = argv[i+1];
       file[i].count = 0;
    }

    char *line=NULL;
    size_t maxlen=0;
    ssize_t n;

    // applying do while loop to comparing the keywords from the text while

    	do{
		printf(" Reading the commandline input"); // Reading input from string commandline input
	}

    while ( (n = getline(&line, &maxlen, stdin)) > 0)
    {
      //As per getline.c fule in hw1 we perform count operation.
      char *alpha = strtok(line, " ");
      while(alpha != NULL)
      {
        for (i=0; i<argc-1;i++)
        {
          if(strcmp(alpha, file[i].word)==0)
          {
              file[i].count += 1;
          }
        }
        alpha = strtok(NULL," ");
      }
     }
     for(i=0; i<argc-1; i++){
       // Each keyword is displayed individually and number of times each word appers in the text file
       printf ("Here is the number of times each keyword appears:");
       printf("%s %d\n", file[i].word,file[i].count);
     }
     free(line);
}
