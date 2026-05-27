#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    printf("Hello world!\n");
    return 0;
}
