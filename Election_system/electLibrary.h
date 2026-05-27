#ifndef ELECTLIBRARY_H
#define ELECTLIBRARY_H

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
#define NAME_LEN 100

int isValidPosition(char* pos);
struct Voter* findVoter(int id);
struct Candidate* findCandidate(int id);
void addPosition();
void registerVoter();
void registerCandidate();
void searchRecord();
void updateVoter();
void deleteVoter();
void castVote();
void displayResults();


#endif // ELECTLIBRARY_H