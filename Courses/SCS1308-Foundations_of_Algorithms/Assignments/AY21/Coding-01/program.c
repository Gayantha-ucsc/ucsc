#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20

typedef struct Player {
    char name[MAX_NAME_LEN];
    int score;
} Player;

typedef struct Node {
    Player player;
    int height;
    struct Node *left, *right;
} Node;

// Function to create a new AVL tree node
Node* createNode(char* name, int score) {
    return newNode;
}

// Get height of a node
int getHeight(Node* node) {
}

// Get balance factor
int getBalance(Node* node) {
}

// Right rotation
Node* rightRotate(Node* y) {
}

// Left rotation
Node* leftRotate(Node* x) {
}

// Insert a player (or update score if exists)
Node* insert(Node* root, char* name, int score) {
}

// Find minimum node in a subtree
Node* minValueNode(Node* node) {
}

// Remove a player
Node* removePlayer(Node* root, char* name) {
}

// Print top K players
void printTopK(Node* root, int* count, int k) {

}

// Function to print the tree structure
void printTree(Node* root, int space) {
    if (!root) return;

    space += 5;
    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%s (%d)\n", root->player.name, root->player.score);

    printTree(root->left, space);
}

// Read input from file and execute commands
void processFileInput(char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file\n");
        return;
    }

    Node* root = NULL;
    char command[10], name[MAX_NAME_LEN];
    int score, k;

    while (fscanf(file, "%s", command) != EOF) {
        if (strcmp(command, "INSERT") == 0) {
            fscanf(file, "%s %d", name, &score);
            root = insert(root, name, score);
        } else if (strcmp(command, "UPDATE") == 0) {
            fscanf(file, "%s %d", name, &score);
            root = insert(root, name, score); // Same as insert since it updates if found
        } else if (strcmp(command, "REMOVE") == 0) {
            fscanf(file, "%s", name);
            root = removePlayer(root, name);
        } else if (strcmp(command, "TOP") == 0) {
            fscanf(file, "%d", &k);
            printf("Top %d players:\n", k);
            int count = 0;
            printTopK(root, &count, k);
        }
        
        // Print the tree after each operation
        printf("\nCurrent AVL Tree:\n");
        printTree(root, 0);
        printf("\n--------------------------------------\n");
    }

    fclose(file);
}

int main() {
    processFileInput("input.txt");
    return 0;
}