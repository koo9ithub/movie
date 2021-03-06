#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{
	char name[200];
	float score;
	int runTime;
	char country[10];
} movInfo_t;


void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	
	//allocate memory and set the member variables
	mvPtr = (movInfo_t*)malloc(2*sizeof(movInfo_t));	//잘 생각해보세요. 
	
	if (mvPtr == NULL)
	{
		printf("ERROR.");
		return;
	}
	
	strcpy(mvPtr->name, name);
	mvPtr->score = score;
	mvPtr->runTime = runTime;
	strcpy(mvPtr->country, country);
		
	return (void*)mvPtr;
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->country);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	printf("----------------------------------------------\n");
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{
	movInfo_t* mvPtr;
	float score;
	
	mvPtr = (movInfo_t*)obj;
	score = mvPtr->score;
	
	return score;
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	movInfo_t* mvPtr;
	int runTime;
	
	mvPtr = (movInfo_t*)obj;
	runTime = mvPtr->runTime;
	
	return runTime;
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	movInfo_t* mvPtr;
	char *name;
	
	mvPtr = (movInfo_t*)obj;
	name = mvPtr->name;
	
	return (char*)name;
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	movInfo_t* mvPtr;
	char* country;
	int i;
	
	mvPtr = (movInfo_t*)obj;
	country = mvPtr->country;
	
	return (char*)country;
}


