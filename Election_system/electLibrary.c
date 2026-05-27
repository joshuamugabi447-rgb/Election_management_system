#include "electLibrary.h"
#include "struct.h"
#include "arrays.h"
#include <stdio.h>
#include <string.h>
#include "readLine.h"

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
    char pos[NAME_LEN];
    printf("Enter position name: \n");
    readLine(pos, NAME_LEN);
    // Check if position already exists
    if(isValidPosition(pos)){
        printf("Position already exists.\n");
        return;
    }
    strcpy(positions[positionCount], pos);
    positionCount++; 
    printf("Position added successfully.\n");
}

void registerVoter(){
    // Code to register a new voter
    printf("Registering a new voter...\n");
    if(voterCount >= MAX_VOTERS){
        printf("Maximum voters reached.\n");
        return;
    }

    voters[voterCount].id = voterCount + 1; // Simple ID assignment
    voters[voterCount].hasVoted = false; // Initialize vote status
    printf("Enter voter name: \n");
    readLine(voters[voterCount].name, NAME_LEN);
    printf("Voter registered successfully with ID %d.\n", voters[voterCount].id);
    voterCount++;
   
}

void registerCandidate(){
    // code to register a new candidate
    printf("Registering a new candidate...\n");
    if(candidateCount >= MAX_CANDIDATES){
        printf("Maximum candidates reached.\n");
        return;
    }

    candidates[candidateCount].id = candidateCount + 1; // Simple ID assignment
    candidates[candidateCount].hasVoted = false; // Initialize vote status
    printf("Enter candidate name: \n");
    readLine(candidates[candidateCount].name, NAME_LEN);
    printf("Enter position for the candidate: \n");
    readLine(candidates[candidateCount].position, NAME_LEN);
    printf("Candidate registered successfully with ID %d.\n", candidates[candidateCount].id);
    candidateCount++;
}
void searchRecord(){
    // searching for a voter or candidate record
    printf("Searching for a record...\n");
 // Voter search
    int id;
    printf("Enter voter ID to search: \n");
    scanf("%d", &id);
    struct Voter* voter = findVoter(id);
    if(voter){
        printf("Voter found: ID %d, Name: %s\n", voter->id, voter->name);
    } else {
        printf("Voter not found.\n");
    }

    // Candidate search
    printf("Enter candidate ID to search: \n");
    scanf("%d", &id);
    struct Candidate* candidate = findCandidate(id);
    if(candidate){
        printf("Candidate found: ID %d, Name: %s, Position: %s\n", candidate->id, candidate->name, candidate->position);
    } else {
        printf("Candidate not found.\n");
    }
}

void updateVoter(){
    // updating voter information
    printf("Updating voter information...\n");
    int id;
    printf("Enter voter ID to update: \n");
    scanf("%d", &id);
    struct Voter* voter = findVoter(id);
    if(voter){
        printf("Enter new name for the voter: \n");
        readLine(voter->name, NAME_LEN);
        printf("are you sure you want to update this record? (y/n): \n");
        char confirm;
        scanf(" %c", &confirm);
        if(confirm == 'y' || confirm == 'Y'){
            printf("Voter information updated successfully.\n");
        } else {
            printf("Update cancelled.\n");
        }   
    } else {
        printf("Voter not found.\n");
    }
}

void deleteVoter(){
    // deleting a voter record    
    printf("Deleting a voter record...\n");
    int id;         
    printf("Enter voter ID to delete: \n");
    scanf("%d", &id);               
    struct Voter* voter = findVoter(id);
    if(voter){          
        // Shift remaining voters to fill the gap
        for(int i = (voter - voters); i < voterCount - 1; i++){
            voters[i] = voters[i + 1];
        }
        voterCount--;
        printf("Voter record deleted successfully.\n");
    } else {
        printf("Voter not found.\n");
    }
}

void castVote(){
    // Code to cast a vote for a candidate
    printf("Casting a vote...\n");
    int voterId, candidateId;
    printf("Enter your voter ID: \n");
    scanf("%d", &voterId);
    struct Voter* voter = findVoter(voterId);
    if(voter){
        if(voter->hasVoted){
            printf("You have already voted.\n");
            return;
        }
        printf("Enter candidate ID to vote for: \n");
        scanf("%d", &candidateId);
        struct Candidate* candidate = findCandidate(candidateId);
        if(candidate){
            // Increment the vote count for the candidate
            candidate->votes++;
            voter->hasVoted = true; // Mark voter as having voted
            printf("Vote cast successfully for %s.\n", candidate->name);
        } else {
            printf("Candidate not found.\n");
        }
    } else {
        printf("Voter not found.\n");
    }
}

void displayResults(){
    // Code to display election results
    printf("Election Results:\n");
    for(int i = 0; i < candidateCount; i++){
        printf("Candidate: %s, Position: %s, Votes: %d\n", candidates[i].name, candidates[i].position, candidates[i].votes);
    }
}

int isValidPosition(char* pos){
    for(int i = 0; i < positionCount; i++){
        if(strcmp(positions[i], pos) == 0){
            return 1;// Position exists
        }
    }
    return 0; // Position does not exist
}
