#include<iostream>
#define N 4
using namespace std ;

bool isSafe(int board[N][N],int row,int column) {
    int i , j ;

    //Same Row
    for(i = 0 ; i < column ; i++) {
        if(board[row][i]) {
            return false ;
        }
    }

    //Upper Diagonal
    for(i = row , j = column ; i >= 0 && j >= 0 ; i-- , j--) {
        if(board[i][j]) {
            return false ;
        }
    }

    //Lower Diagonal
    for(i = row , j = column ; i < N && j >= 0 ; i++ , j--) {
        if(board[i][j]) {
            return false ;
        }
    }

    return true ;
}

void printSolution(int board[N][N]) {

    for(int i = 0 ; i < N ; i++) 
    {
        for(int j = 0 ; j < N ; j++) 
        {
            if(board[i][j]) {
                cout << "Q" << " " ;
            } else {
                cout << "." << " " ;
            }
        }

        cout<< "\n" << endl ;
    }
}

bool nQueenAlgo(int board[N][N],int column) {

    if(column >= N) {
        return true ;
    }

    for(int i = 0 ; i < N ; i++) 
    {
        if(isSafe(board,i,column)) {

            board[i][column] = 1 ;

            if(nQueenAlgo(board,column+1) == true) {
                return true ;
            }

            board[i][column] = 0 ;
        }
    }

    return false ;
}

int main() {

    int board[N][N] = { {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0},
                        {0,0,0,0} } ;

    if(nQueenAlgo(board,0) == false) {
        cout << "Solution doesn't Exist " << endl ;
    } else {
        printSolution(board) ;
    }

    return 0 ;
}



/*

OutPut 
...............................

. . Q . 

Q . . .

. . . Q

. Q . .


*/