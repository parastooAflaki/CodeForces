#include<iostream>

using namespace std;


int main(){

  int width = 5 ;
  int height = 5;
  int map[width][height] =
      {
          { 4, 7, 8, 6, 4 },
          { 6, 7, 3, 9, 2 },
          { 3, 8, 1, 2, 4 },
          { 7, 1, 7, 3, 7 },
          { 2, 9, 8, 9, 3 }
      };

  int dp[width+1][height+1];

  for(int i = 0 ; i <= width ; i ++){
    for(int j = 0 ; j <= height ; j ++){

      if(i==1 && j ==1)
        dp[i][j] = map[i-1][j-1];
      else if(i==0 || j==0)
        dp[i][j] = 1e5;
      else
        dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + map[i-1][j-1];
    }
  }
  cout << dp[width][height]<<endl;

  return 0;
}
