#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define MaxCandidates 10
#define MaxUser 10
#define MaxNameLength 50
#define MaxSignLength 20

int num_candidates = 0;
int num_users = 0;

typedef struct {
    char name[MaxNameLength];
    char sign[MaxSignLength];
    int votes;
} Candidate;

typedef struct {
    char username[MaxNameLength];
    char password[MaxNameLength]; // Added password field for user
    int votes_given;
} User;

Candidate candidates[MaxCandidates];
User users[MaxUser];

void adminLogin();
void userLogin();
void userSignup();
void addCandidate();
void countTotalVotes();
void totalCandidates();
void sortCandidates();
void voteCandidate(User *user);

int main() {
    int choice;

    while (1) {
        printf("\n********** Voting System **********\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. User Signup\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminLogin();
                break;
            case 2:
                userLogin();
                break;
            case 3:
                userSignup();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void adminLogin() {
    int choice;

    while (1) {
        printf("\n********** Admin Menu **********\n");
        printf("1. Add Candidate\n");
        printf("2. Count Total Votes\n");
        printf("3. Total Candidates\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                countTotalVotes();
                break;
            case 3:
                totalCandidates();
                break;
            case 4:
                return; // Return to main menu
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}

void addCandidate() {
    char choice;

    do {
        if (num_candidates >= MaxCandidates) {
            printf("Maximum candidates reached. Cannot add more candidates.\n");
            return;
        }

        printf("Enter candidate name: ");
        scanf("%s", candidates[num_candidates].name);

        printf("Enter candidate sign: ");
        scanf("%s", candidates[num_candidates].sign);

        candidates[num_candidates].votes = 0;
        num_candidates++;

        printf("Candidate added successfully.\n");

        printf("Do you want to add more candidates? (1: yes / 2: no): ");
        scanf(" %c", &choice);
    } while (choice == '1');
}

void countTotalVotes() {
    // Sort candidates based on votes
    sortCandidates();

    printf("\n********** Total Votes **********\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

void totalCandidates() {
    printf("\n********** Total Candidates **********\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void sortCandidates() {
    for (int i = 0; i < num_candidates - 1; i++) {
        for (int j = i + 1; j < num_candidates; j++) {
            if (candidates[i].votes < candidates[j].votes) {
                Candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}

void userLogin() {
    char username[MaxNameLength];
    char password[MaxNameLength];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("User logged in successfully.\n");
            voteCandidate(&users[i]);
            return;
        }
    }

    printf("Invalid username or password. Please try again.\n");
}

void userSignup() {
    if (num_users >= MaxUser) {
        printf("Maximum users reached. Cannot create a new user.\n");
        return;
    }

    printf("Enter your username: ");
    scanf("%s", users[num_users].username);
    printf("Enter your password: ");
    scanf("%s", users[num_users].password);

    users[num_users].votes_given = 0;
    num_users++;

    printf("User created successfully. Please login.\n");
}

void voteCandidate(User *user) {
    printf("\n********** Candidates List **********\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%s)\n", i + 1, candidates[i].name, candidates[i].sign);
    }

    int choice;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_candidates) {
        candidates[choice - 1].votes++;
        user->votes_given++;
        printf("Vote recorded successfully!\n");
    } else {
        printf("Invalid choice. Please select a valid candidate.\n");
    }
}
