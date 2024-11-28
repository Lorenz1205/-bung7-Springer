# -bung7-Springer

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int toIndex(int x, int y, int size) {
        return x*size+ y;
        }

int isValid( int x, int y, bool* visited, int size){
        int toIndex();
        if (x < 0 ||y<0||x>=size||y>=size){
                return 0;
        }else{
                index=toIndex(int x, int y, int size);
                if visited[index]== false(
                        return 0;
                }
                else {
                        ;
                        return 1;
                }

        }
bool solveKnightTour(int x, int y, int moveCount,bool*visited, int size,int i){
        if  moveCount != size * size{
                        int x = dx[i]+x
                        int y = dy[i]+y
                        if isValid(int x, int y, bool* visited, int size)==1{
                                return x,y,movecount++,solveKnightTour(int x, int y, int MoveCount, bool*visited, int size, int i);
                                else{
                                        for(i =1; i < 8; i++){
                                                x = dx[i]+x;
                                                y = dy[i]+y;
                                                if isValid(int x, int y, bool*visited, int size)==1{
                                                return x,y,movecount++, solveKnightTour(int x, int y, int moveCount, bool* visited, int size, int i);
                                                }
                                        }
                                        
                                }
                        }
        }
}

int main(){
        int size =8;
        int x=0;
        int y=0;
        int dx=[2,2,1,1,-1,-1,-2,-2]
        int dy=[1,-1,2,-2,2,-2,1,-1]
        int movecount = 0;
        while movecount != size * size{
                solveKnightTour(int x, int y, int moveCount, bool*visited, int size, int i);
                }
        }
