#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include "../include/BSTApi.h"

int dummy(){
	return 0; 
}
void dummy1(){

}

int main(int argc, char** argv){

	int menuInput; 
	//char line[1000]; 
	//char line2[1000];
	char word[1000];
	char sentence[1000]; 
	double userRating = 0;

	char * inputWord; 
	char * inputSentence;
	char * toLower;  
	char * split; 
	//char * userRating; 

	Tree * newTree = createBinTree(dummy, dummy1);
	info * xInfo;  

	FILE * inputFile; 

	inputFile = fopen(argv[1], "r"); 

	if (inputFile == NULL){
		printf("Error reading file\n"); 
		return 0;
	}else{

		while(fgets(word, 100, inputFile) != NULL){
					
			word[strcspn(word, "\r\n")] = '\0'; 
			fgets(sentence, 1000, inputFile); 
			sentence[strcspn(sentence, "\r\n")] = '\0';

			toLower = malloc(sizeof(char*)*strlen(word)+1);
			strcpy(toLower, word); 

			for(int i=0; i<strlen(toLower); i++){
			 		toLower[i] = tolower(toLower[i]);
			 }


			xInfo = createInfo(0.5, 0, sentence, toLower, 0); 
			addToTree(newTree, xInfo);

		}
		//printInOrder(newTree, dummy1); 

	}


	while(1){

		 printf("\n1) Add a new rule\n");
		 printf("2) Remove a rule\n"); 
		 printf("3) Display rules\n"); 
		 printf("4) Modify Rule Rating\n");
		 printf("5) Discuss\n"); 
		 printf("9) Exit\n"); 
		 scanf("%d", &menuInput); 
		 getchar(); 


			 if(menuInput == 1){


			 	printf("Enter word:");
			 	inputWord = malloc(sizeof(char*)*1000); 
			 	fgets(inputWord, 1000, stdin); 
			 	inputWord[strlen(inputWord)-1] = '\0';
			 	printf("\n");

			 	toLower = malloc(sizeof(char*)*strlen(inputWord)+1);
			 	strcpy(toLower, inputWord); 

			 	for(int i=0; i<strlen(toLower); i++){
			 		toLower[i] = tolower(toLower[i]);
			 	}


			 	printf("Enter sentence:");
			 	inputSentence = malloc(sizeof(char*)*1000); 
			 	fgets(inputSentence, 1000, stdin); 
			 	inputSentence[strlen(inputSentence)-1] = '\0';  
			 	printf("\n"); 


			 	printf("Enter Importance Value:"); 
			 	scanf("%lf", &userRating);
			 	getchar(); 
			 	// userRating = malloc(sizeof(char*)*100); 
			 	// fgets(userRating, sizeof(userRating), stdin); 
			 	// userRating[strlen(userRating)-1] = '\0'; 
			 	printf("\n");

				xInfo = createInfo(userRating, 0.5, inputSentence, toLower, 0);
				addToTree(newTree, xInfo);
				printInOrder(newTree, stringInfo); 


			 }else if(menuInput == 2){

			 }else if(menuInput == 3){

			 	printInOrder(newTree, stringInfo);  


			 }else if(menuInput == 4){
			 	
			 	printf("Enter word:");
			 	inputWord = malloc(sizeof(char*)*100); 
			 	fgets(inputWord, sizeof(inputWord), stdin); 
			 	inputWord[strlen(inputWord)-1] = '\0';
			 	printf("\n");  

			 	for(int i = 0; i < strlen(inputWord); i++){
			 		inputWord[i] = tolower(inputWord[i]); 
			 	}

			 	info * newInfo = malloc(sizeof(info)); 
			 	strcpy(newInfo->word, inputWord);

			 	TreeNode * node = findInTree(newTree, newInfo); 

			 	info* toUpdate = ((info*)node); 

				if(node == NULL){
			 		 printf("Empty"); 
			 	}else{

			 		printf("Enter user rating:"); 
			 		scanf("%lf", &userRating); 
			 		getchar(); 
			 		printf("\n"); 

			 		printf("debuging: %f \n", userRating);
			 		toUpdate->userRating = userRating; 
			 		printf("Updated\n");
			 	}



			 }else if(menuInput == 5){


			 	printf("Enter Discussion: "); 
			 	inputSentence = malloc(sizeof(char*)*100);
			 	fgets(inputSentence, sizeof(char*)*100, stdin); 
			 	inputSentence[strlen(inputSentence)-1] ='\0'; 
			 	printf("\n");

			 	info * tInfo = NULL; 
			 	
			 	split = strtok(inputSentence, " .!@#$^&,*();?");		 	

			 	for(int i = 0;i<strlen(split);i++){
          			split[i] = tolower(split[i]);
        		}
        		while(split != NULL){
        			
        			for(int i = 0;i<strlen(split);i++){
          				split[i] = tolower(split[i]);
        			}

				 	info * newInfo = malloc(sizeof(info)); 
				 	strcpy(newInfo->word, split);

				 	TreeNode * node = findInTree(newTree, newInfo); 

				 	if(node != NULL){
				 		tInfo = ((info*)node); 
				 	}
                   	split = strtok(NULL, " .!@#$^&,*();?");
                    
				 	//info* toUpdate = ((info*)node); 
			 		
        		}
        		if(tInfo != NULL){
        			printf("%s\n", tInfo->sentence);
        		}

        		//printf("%s\n", i->sentence)

			 }else if(menuInput == 9){
			 	destroyBinTree(newTree);
			 	return 0; 
			 }else{
			 	printf("Incorrect Input, Please enter a number within 1-6"); 
			 }	
		
	}
	fclose(inputFile); 
}

