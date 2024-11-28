# -bung7-Springer

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int toIndex(int x, int y, int size) {
        return x*size+ y;
        }

int isValid( int x, int y, bool* visited, int size){
        int toIndex();
        if (x < 0 ||y<0||x>=size||y>=size)
                return visited[index( x, y, size)];
}
        
bool solveKnightTour(int x, int y, int moveCount, bool*visited, int size, ){
        moveCount = 0
        int dx[] = {2,2,1,1,-1,-1,-2,-2}
        int dy[] = {1,-1,2,-2,2,-2,1,-1}
        for (i = 0 ; i < (size* size); i++)
                visited[i] = false;
        for (i = 0 ; i < (size* size); i++){
                for (j = 0, j < 8, j++){
                        if(isValid(dx[j] + x, dy[j] + y, visited, size){
                                visited[toIndex( x, y, size)];
                                x += dx[j]
                                y += dx[j]
                                movecount++
                                break;
                        }
        return( movecount == size * size)
                }
        }

                
                
                        if (isValid(int x, int y, bool* visited, int size)
                                return (x,y,movecount++,solveKnightTour(int x, int y, int MoveCount, bool*visited, int size, int i));
                                else{
                                        for(i ; i < size; i++){
                                                x = dx[i] + x;
                                                y = dy[i] + y;
                                                if (isValid(int x, int y, bool*visited, int size))
                                                return (x,y,movecount++, solveKnightTour(int x, int y, int moveCount, bool* visited, int size, int i));
                                                
                                        }
                                        
                                }
                        }
        }
}

int main(){
        int size =8;
        int x=0;
        int y=0;
        for(x = 0, x < size, x++)
                for(y = 0, y < size, y++)
                        
                        
                
