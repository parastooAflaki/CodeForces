

#include <iostream>
#include <vector>
using namespace std;


int is_black[100005];
vector<int> is_edge[100005];
long long dp[100005][2];
int solve_dfs(int node , int n){

int mod =  1000000007;
// dp[node][1] : num of ways to construct a tree with node as root with only one black vertix in tree
// dp[node][0] : num of ways to construct a tree with node as root without any black vertix in tree
  if(is_black[node])
    dp[node][1] = 1;
  else
    dp[node][0] = 1;

   for(int i: is_edge[node]){
        solve_dfs(i , n);
        dp[node][1] = ((dp[node][1]*dp[i][0]) % mod + (dp[node][1] * dp[i][1])%mod  + (dp[node][0] * dp[i][1])%mod)% mod;
                    // node black . i white    node black . i black    node white . i black
        dp[node][0] = ((dp[node][0] * dp[i][1]) % mod + (dp[node][0] * dp[i][0])%mod ) % mod;
                    // node white . i black     node white . i white
      }

  return dp[node][1];
}

int  main() {

  int n;
  cin >> n ;
  for(int i = 0 ; i < n-1 ; i++){
    int node;
    cin >> node;
    is_edge[node].push_back(i+1);
  }
  for(int i=0;i<n;i++){
          cin>>is_black[i];
    }

  cout << solve_dfs(0 , n);
  return 0;
}
