#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int	toIndex(int x, int y, int size){
	return (x * size + y);
}

int	isValid( int x, int y, bool* visited, int size){
        if (x < 0 || y < 0 || x >= size || y >= size)
                return 0;
	return (visited[toIndex( x, y, size)]);
}

bool	solveKnightTour(int x, int y, int moveCount, bool* visited, int size){
        int dx[] = {2,2,1,1,-1,-1,-2,-2};
        int dy[] = {1,-1,2,-2,2,-2,1,-1};

	for (int i = 0; i < (size * size); i++)
		visited[i] = false;
	moveCount = 0;
	for (int i = 0; i < (size * size); i++){
		for (int j = 0; j < 8; j++){
			if (isValid( x + dx[j], y + dy[j], visited, size)){
				visited[toIndex(x, y, size)] = true;
				moveCount++;
				x += dx[j];
				y += dy[j];
				break;
			}
		}
	}
	return (moveCount == (size * size) ? true : false);
}

int main(){
        int 	size = 8;
        int 	movecount;
	bool	visited[size * size];

	for (int x = 0; x <= size; x++){
		for (int y = 0; y <= size; y++){
			printf("Test:\n x: %d, y: %d == %d\n\n", x, y, \
				solveKnightTour(x, y, movecount, visited, size));
		}
	}
}
