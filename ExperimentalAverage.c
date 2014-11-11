#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main(){
	FILE *file;
	char expName;
	double value;
	int i, ch, lines;
	int j = 0; 
	char input[] = "";
	float count=0; 
	float total=0;
	
	file = fopen("data.txt", "r");
	if(file == NULL){
		perror("Error opening file");
		return(-1);
	}

	/* GET NUMBER OF LINES IN FILE */
	do {
    	ch = fgetc(file);
    	if(ch == '\n')
    		lines++;
	} while (ch != EOF);
	
	if(ch != '\n' && lines != 0){ 
    		lines++;
	}
	rewind(file);

	for(i=0; i<lines; i++){		
		while((expName=getc(file))!=','){
			if(expName==EOF){
				fclose(file);
				return 0;
				}
			printf("%c", expName);
			}

		printf(": ");
		
		/* CALCULATE & PRINT THE DATA AVERAGE */  
		while((expName!='\n')&&(expName!=EOF)){
			/* PUT DATA FROM FILE INTO INPUT */			
			expName=fgetc(file);
			while((expName!=',')&&(expName!='\n')&&(expName!=EOF)){
				input[j] = expName;
				expName=fgetc(file);
				j++;
			}  
/*      FOR DEBUGGING           */
/* printf("%s, ", input);       */
			float fInput = atof(input);
			fInput--;  
			memset(&input[0], 0, sizeof(input));
			total = total + fInput;
			count++;
			j=0;
		}
		total = (total/count);
		printf("%f\n", total);
		count = 0;
		total = 0; 
	}
	fclose(file);
	return 0;
}
