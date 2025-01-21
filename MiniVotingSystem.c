#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("\nCandidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote(Candidate candidates[], int numCandidates) {
    int choice;
    printf("Enter the candidate number you want to vote for (1-%d): ", numCandidates);
    scanf("%d", &choice);

    if (choice < 1 || choice > numCandidates) {
        printf("Invalid choice! Please try again.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Vote casted for %s!\n", candidates[choice - 1].name);
    }
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nVoting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates, numVotes, i;

    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &numCandidates);

    if (numCandidates < 1 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates!\n");
        return 1;
    }

    for (i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes to 0
    }

    printf("Enter the number of votes to cast: ");
    scanf("%d", &numVotes);

    for (i = 0; i < numVotes; i++) {
        printf("\nVote %d:\n", i + 1);
        displayCandidates(candidates, numCandidates);
        castVote(candidates, numCandidates);
    }

    displayResults(candidates, numCandidates);

    return 0;
}