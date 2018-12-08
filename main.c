#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getcr, system("pause") or input loop */

void list_genList() {
	
	printf("Reading the data files...\n");
	printf("Read done! i items are read\n\n\n\n", /* %i: ¿µÈ­ ÃÑ °³¼ö */);
	
	printf("--------------------MENU--------------------\n");
	printf("1. print ALL the movies\n");
	printf("2. search for specific COUNTRY movies\n");
	printf("3. search for specific RUNTIME movies\n");
	printf("4. search for specific SCORE movies\n");
	printf("5. exit\n\n").
	
	printf("--------------------MENU--------------------\n");
	
	printf("Select the option: ");
	scanf("%d", option);
}

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[20]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	void *ndPtr; //void pointer for linked list node
	
	
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	
	fp = fopen(movie.dat, "r");
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	
	fclose(fp); 
	return 0;
}
