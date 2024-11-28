#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int	toIndex(int x, int y, int size){
	return (x * size + y);
}

int	isValid( int x, int y, bool* visited, int size){
        if (x < 0 || y < 0 || x >= size || y >= size)
                return 0;
	return (visited[toIndex( x, y, size)] == false);
}

int	solveKnightTourRecursive( int x, int y, int i, bool* visited, int dx[], int dy[], int size){
	int	tmpx;
	int	tmpy;

	if ( i == size * size )
		return (1);

	for ( int j = 0; j < 8; j++ ){
		tmpx = x + dx[j];
		tmpy = y + dy[j];
		if (isValid( tmpx, tmpy, visited, size)){
			visited[toIndex(tmpx, tmpy, size)] = true;
			if (solveKnightTourRecursive( tmpx, tmpy, i + 1, visited, dx, dy, size))
				return (1);
			else
				visited[toIndex(tmpx, tmpy, size)] = false;
		}
	}
	return (0);
}

bool	solveKnightTour(int x, int y, int moveCount, bool* visited, int size){
        int dx[] = {2,  2, 1,  1, -1, -1, -2, -2};
        int dy[] = {1, -1, 2, -2,  2, -2,  1, -1};

	for (int i = 0; i < (size * size); i++)
		visited[i] = false;
	moveCount = 0;
	visited[toIndex(x, y, size)] = true;
	return (solveKnightTourRecursive( x, y, 1, visited, dx, dy, size));
}

int main(){
        int 	size = 7;
        int 	movecount;
	bool	visited[size * size];
	int	x = 0;
	int	y = 0;

	printf("Test:\n x: %d, y: %d == %d\n\n", x, y, \
		solveKnightTour(x, y, movecount, visited, size));

//	for (int x = 0; x < size; x++){
//		for (int y = 0; y < size; y++){
//			printf("Test:\n x: %d, y: %d == %d\n\n", x, y, \
//				solveKnightTour(x, y, movecount, visited, size));
//		}
//	}
}
