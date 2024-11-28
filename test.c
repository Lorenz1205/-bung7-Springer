#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int toIndex(int x, int y, int size) {
    return (x * size + y);
}

int isValid(int x, int y, bool* visited, int size) {
    if (x < 0 || y < 0 || x >= size || y >= size)
        return 0;
    return (visited[toIndex(x, y, size)] == false);
}

// Calculate the degree (number of valid onward moves) for a given position
int getDegree(int x, int y, bool* visited, int dx[], int dy[], int size) {
    int degree = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, visited, size)) {
            degree++;
        }
    }
    return degree;
}

// Warnsdorff-enhanced backtracking
int solveKnightTourRecursive(int x, int y, int moveCount, bool* visited, int dx[], int dy[], int size) {
    if (moveCount == size * size)
        return 1;

    int moves[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Move indices to sort
    int degrees[8];

    // Calculate degrees for all valid moves
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, visited, size)) {
            degrees[i] = getDegree(nx, ny, visited, dx, dy, size);
        } else {
            degrees[i] = 9; // Invalid moves get the highest degree
        }
    }

    // Sort moves based on degrees (Warnsdorff's Rule)
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (degrees[moves[i]] > degrees[moves[j]]) {
                int temp = moves[i];
                moves[i] = moves[j];
                moves[j] = temp;
            }
        }
    }

    // Try moves in order of increasing degree
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[moves[i]];
        int ny = y + dy[moves[i]];
        if (isValid(nx, ny, visited, size)) {
            visited[toIndex(nx, ny, size)] = true;
            if (solveKnightTourRecursive(nx, ny, moveCount + 1, visited, dx, dy, size)) {
                return 1;
            } else {
                visited[toIndex(nx, ny, size)] = false;
            }
        }
    }
    return 0;
}

bool solveKnightTour(int x, int y, int size) {
    int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

    bool* visited = calloc(size * size, sizeof(bool));
    visited[toIndex(x, y, size)] = true;

    if (solveKnightTourRecursive(x, y, 1, visited, dx, dy, size)) {
        free(visited);
        return true;
    } else {
        free(visited);
        return false;
    }
}

int main() {
    int size = 2; // Board size
    int x = 0, y = 0; // Starting position

    if (solveKnightTour(x, y, size)) {
        printf("Knight's Tour completed successfully.\n");
    } else {
        printf("Knight's Tour not possible.\n");
    }

    return 0;
}

