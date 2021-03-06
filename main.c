#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getcr, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	char string[100];
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	void *ndPtr; //void pointer for linked list node
	
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int e=0;
	
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r");
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();	//linkedList.h에서 불러온 함수 
	
	//1.3 read each movie data from the file and add it to the linked list
	while ( fscanf(fp, "%s %s %d %f", name, country, &runTime, &score) == 4 )
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()	
		mvInfo = mv_genMvInfo(name, score, runTime, country);
		mv_print(mvInfo);
		list_addTail(mvInfo, list);
		a++;
	}
	

	//1.4 FILE close
	fclose(fp);
	
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		printf("\n");
		printf("Reading the data files...\n");
		printf("Read done! %i items are read\n\n\n\n", a);
		
		printf("--------------------MENU--------------------\n");
		printf("1. print ALL the movies\n");
		printf("2. search for specific COUNTRY movies\n");
		printf("3. search for specific RUNTIME movies\n");
		printf("4. search for specific SCORE movies\n");
		printf("5. exit\n\n");
		
		printf("--------------------MENU--------------------\n");
		printf("--Select the option: ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");
				
				ndPtr = list;
				while ( list_isEndNode(ndPtr) == 0 )
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//print the contents of the mvInfo
					ndPtr = list_getNextNd(ndPtr);
					mvInfo = list_getNdObj(ndPtr);
					
					mv_print(mvInfo);
					b++;
				}
				printf("\t");
				printf("-totally %i movies are listed!\n", b);
				b=0;
				
				break;
				
			case 2: //print movies of specific country
				//2.3.1 get country name to search for
				
				printf("--Select a country: ");
				scanf("%s", &country);
				
				ndPtr = list;
				while ( list_isEndNode(ndPtr) == 0 )
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input country matches to the country of the movie,
					//then print the contents of the mvInfo
					ndPtr = list_getNextNd(ndPtr);
					mvInfo = list_getNdObj(ndPtr);
					
					if ( strncmp(mv_getCountry(mvInfo), country, strlen(country)) == 0 )
					{
						mv_print(mvInfo);
						c++;
					}
				}
				printf("\t");
				printf("-totally %i movies are listed!\n", c);
				c=0;
				
				break;
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				
				printf("--Input a specific runtime: ");
				scanf("%i", &runTime);
				
				ndPtr = list;
				while ( list_isEndNode(ndPtr) == 0 )
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input runtime is lower than the runtime of the movie,
					//then print the contents of the mvInfo
					ndPtr = list_getNextNd(ndPtr);
					mvInfo = list_getNdObj(ndPtr);
				
					if ( mv_getRunTime(mvInfo) > runTime )
					{
						mv_print(mvInfo);
						d++;
					}
				}
				printf("\t");
				printf("-totally %i movies are listed!\n", d);
				d=0;
				
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				
				printf("--Input a specific score: ");
				scanf("%f", &score);
				
				ndPtr = list;
				while ( list_isEndNode(ndPtr) == 0 )
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input score is lower than the score of the movie,
					//then print the contents of the mvInfo
					ndPtr = list_getNextNd(ndPtr);
					mvInfo = list_getNdObj(ndPtr);
					
					if ( mv_getScore(mvInfo) > score )
					{
						mv_print(mvInfo);
						e++;
					}
				}
				printf("\t");
				printf("-totally %i movies are listed!\n", e);
				break;
				e=0;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
	}	 
	return 0;
}
