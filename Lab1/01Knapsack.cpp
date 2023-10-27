#include<bits/stdc++.h>
using namespace std ;

int max(int a, int b) { return (a > b) ? a : b; } 

int knapsack(int maxWeight, int profitValues[], int weight[], int size) {

    int i, w; 
    int K[size+1][maxWeight+1] ;
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= size; i++) { 
        for (w = 0; w <= maxWeight; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (weight[i - 1] <= w) 
                K[i][w] = max(profitValues[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
    return K[size][maxWeight]; 
}

int main() {

    int profit[] = {60,100,120} ;
    int weight[] = {10,20,30} ;

    int maxWeight = 50 ;

    int size = sizeof(profit)/sizeof(profit[0]) ;

    cout << "Max Profit: " << knapsack(maxWeight,profit,weight,size) ;

    return 0 ;
}