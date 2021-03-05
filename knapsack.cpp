#include<iostream>

using namespace std;

int Knapsack(int n , int w , int items[],int weights[]){


  int dp[n+1][w+1];
  for(int i =0 ; i <= n ; i++)
    dp[0][j] = 0;
  for(int j=0 ; j <= w ; j++)
    dp[i][0] = 0;

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1; j <= w ; j++){
        if(weights[i-1] > w)
          dp[i][j] = dp[i-1][j];
        else{
          dp[i][j] = max(dp[i-1][j] , items[i-1] + dp[i-1][j - weights[i-1]]);
        }
    }
  }
  return dp[n][w];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", Knapsack(W, n, val, wt));
    return 0;
}
