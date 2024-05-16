#include <iostream>
#include <cstring>
#include <algorithm> // for sorting

using namespace std;

int maxCandidates = 10;
int maxUsers = 10;
int maxNameLength = 50;
int maxSignLength = 20;

int num_candidates = 0;
int num_users = 0;

struct Candidate {
    char name[50];
    char sign[20];
    int votes;
};

struct User {
    char username[50];
    char password[50]; // Added password field for user
    int votes_given;
};

Candidate candidates[10];
User users[10];

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

    while (true) {
        cout << "\n********** Voting System **********\n";
        cout << "1. Admin Login\n";
        cout << "2. User Login\n";
        cout << "3. User Signup\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}

void adminLogin() {
    int choice;

    while (true) {
        cout << "\n********** Admin Menu **********\n";
        cout << "1. Add Candidate\n";
        cout << "2. Count Total Votes\n";
        cout << "3. Total Candidates\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void addCandidate() {
    char choice;

    do {
        if (num_candidates >= maxCandidates) {
            cout << "Maximum candidates reached. Cannot add more candidates.\n";
            return;
        }

        cout << "Enter candidate name: ";
        cin >> candidates[num_candidates].name;

        cout << "Enter candidate sign: ";
        cin >> candidates[num_candidates].sign;

        candidates[num_candidates].votes = 0;
        num_candidates++;

        cout << "Candidate added successfully.\n";

        cout << "Do you want to add more candidates? (1: yes / 2: no): ";
        cin >> choice;
    } while (choice == '1');
}

void countTotalVotes() {
    // Sort candidates based on votes
    sortCandidates();

    cout << "\n********** Total Votes **********\n";
    for (int i = 0; i < num_candidates; i++) {
        cout << candidates[i].name << " received " << candidates[i].votes << " votes.\n";
    }
}

void totalCandidates() {
    cout << "\n********** Total Candidates **********\n";
    for (int i = 0; i < num_candidates; i++) {
        cout << i + 1 << ". " << candidates[i].name << "\n";
    }
}

void sortCandidates() {
    sort(candidates, candidates + num_candidates, [](const Candidate &a, const Candidate &b) {
        return a.votes > b.votes; // Sort in descending order of votes
    });
}

void userLogin() {
    char username[50];
    char password[50];

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            cout << "User logged in successfully.\n";
            voteCandidate(&users[i]);
            return;
        }
    }

    cout << "Invalid username or password. Please try again.\n";
}

void userSignup() {
    if (num_users >= maxUsers) {
        cout << "Maximum users reached. Cannot create a new user.\n";
        return;
    }

    cout << "Enter your username: ";
    cin >> users[num_users].username;
    cout << "Enter your password: ";
    cin >> users[num_users].password;

    users[num_users].votes_given = 0;
    num_users++;

    cout << "User created successfully. Please login.\n";
}

void voteCandidate(User *user) {
    cout << "\n********** Candidates List **********\n";
    for (int i = 0; i < num_candidates; i++) {
        cout << i + 1 << ". " << candidates[i].name << " (" << candidates[i].sign << ")\n";
    }

    int choice;
    cout << "Enter the number of the candidate you want to vote for: ";
    cin >> choice;

    if (choice >= 1 && choice <= num_candidates) {
        candidates[choice - 1].votes++;
        user->votes_given++;
        cout << "Vote recorded successfully!\n";
    } else {
        cout << "Invalid choice. Please select a valid candidate.\n";
    }
}