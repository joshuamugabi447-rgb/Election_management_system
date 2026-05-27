#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "electLibrary.h"

struct Voter{
int id;
char name[NAME_LEN];
int hasVoted;
};

struct Candidate{
int id;
char name[NAME_LEN];
bool hasVoted;
};

int main()
{
int choice = 0;

switch(choice){
case 0:
    addPosition();
    break;
case 1:
    registerVoter();
    break;
case 2:
    registerCandidate();
    break;
case 3:
    searchRecord();
    break;
case 4:
    updateVoter();
    break;
case 5:
    deleteVoter();
    break;
case 6:
    castVote();
    break;
case 7:
    displayResults();
    break;        
default:
    printf("Invalid selection\n");

}
    return 0;
}
