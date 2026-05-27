#include "electLibrary.h"
#include "struct.h"
#include "arrays.h"
#include <stdio.h>
#include <string.h>

int voterCount     = 0;
int candidateCount = 0;
int positionCount  = 0;

void addPosition(){
    // Code to add a new position for election
    printf("Adding a new position...\n");
    if(positionCount >= MAX_POSITIONS){
        printf("Maximum positions reached.\n");
        return;
    }
    printf("Enter position name: ");
    fgets(positions[positionCount], NAME_LEN, stdin);
    // Remove newline character from fgets
    positions[positionCount][strcspn(positions[positionCount], "\n")] = '\0';
    positionCount++;
     printf("Position added successfully.\n");
}