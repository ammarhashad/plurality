#include<stdio.h>
#include <stdlib.h>
#include<cs50.h>
#include<string.h>

#define MAX 9
bool vote(string name);
void print_winner(void);
int numberOfname = 0;
int candidate_count = 0;
typedef struct
{
    string name;
    int votes;
}
candidate;
candidate candidates[MAX];

int main(int argc, string argv[])
{
    candidate_count = argc;
    if (argc == 1 || argc > 9)
    {
        return 1;
    }
    //this for for hundle if 2 name are the same go out
    for (int i = 1; i < argc - 1; i++)
    {
        if (strcmp(argv[i], argv[i + 1]) == 0)
        {
            return 1;
        }
    }
    for (int i = 1; i < argc; i++)
    {
        candidates[i - 1].name = argv[i];
    }
    numberOfname = get_int("Number of namers: ");
    for (int i = 0; i < numberOfname; i++)
    {
        string voteName = get_string("vote: ");
        bool votes = vote(voteName);
        if (votes == false)
        {
            printf("Invalid vote.\n");
        }
    }
    print_winner();
}
bool vote(string name)
{
    int c = 0;
    for (int i = 0; i < (candidate_count - 1); i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            ++candidates[i].votes;
            c++;
        }
    }
    if (c == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void print_winner(void)
{
    candidate cordinateTemp;
    for (int i = 0 ; i < (candidate_count - 2); i++)
    {
        for (int j = 0; j < (candidate_count - 2); j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                cordinateTemp.name = candidates[j].name;
                cordinateTemp.votes = candidates[j].votes;
                candidates[j].name = candidates[j + 1].name;
                candidates[j].votes = candidates[j + 1].votes;
                candidates[j + 1].name = cordinateTemp.name;
                candidates[j + 1].votes = cordinateTemp.votes;
            }
        }
    }
    int c = 0;
    for (int i = 0; i < (candidate_count - 2); i++)
    {
        if (candidates[i].votes == candidates[i + 1].votes)
        {
            if (candidates[i + 1].votes != 0 && candidates[i + 1].votes == candidates[candidate_count - 2].votes)
            {
                c++;
            }
        }


    }
    if (candidates[candidate_count - 2].votes == 0)
    {
        for (int i = 0; i < (candidate_count - 1); i++)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    else if (c != 0)
    {
        for (int i = (candidate_count - 2) - c; i < (candidate_count - 1); i++)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    else
    {
        printf("%s\n", candidates[candidate_count - 2].name);
    }
}
