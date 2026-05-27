#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "electLibrary.h"


int main(){
    int choice = 0;
    do {
     printf("\n===== UNIVERSITY ELECTION SYSTEM =====\n");
        printf("1. Add Position\n");
        printf("2. Register Voter\n");
        printf("3. Register Candidate\n");
        printf("4. Search Record\n");
        printf("5. Update Voter\n");
        printf("6. Delete Voter\n");
        printf("7. Cast Vote\n");
        printf("8. Display Results\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);


switch(choice){
case 1:
    addPosition();
    break;
case 2:
    registerVoter();
    break;
case 3:
    registerCandidate();
    break;
case 4:
    searchRecord();
    break;
case 5:
    updateVoter();
    break;
case 6:
    deleteVoter();
    break;
case 7:
    castVote();
    break;
case 8:
    displayResults();
    break;
case 0:
    printf("Exiting the system...\n");
    break;
default:
    printf("Invalid selection\n");

    }
    } while(choice != 0);
    return 0;
}
