#ifndef STRUCT_H
#define STRUCT_H
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
#endif // STRUCT_H