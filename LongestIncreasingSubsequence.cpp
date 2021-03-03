#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_LIS(vector<int> max){
    for( int x : max)
        cout << x << " ";
}

//O(n^2)
void LIS(int arr[] , int in_len){

    int dp[in_len] ;
    vector<vector<int> > L(in_len);


    for(int i = 0 ; i < in_len ; i++)
        dp[i] = 0;


    for(int i = 0 ; i < in_len ; i++){
        for(int j = 0 ; j < i ; j ++){
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                L[i] = L[j];
            }
        }
        L[i].push_back(arr[i]);
    }

    vector<int> max = L[0];
    for (vector<int> x : L)
        if (x.size() > max.size())
            max = x;

    std::cout << "max len is " << max.size()<< '\n';
    print_LIS(max);


   // int* max_len = max_element(dp , dp + in_len);
    // int index = std::distance(dp, max_len);
}


int main(){

    int arr[] = { 1 , 4 , 2 , 8 , 3 , 4 , 5};
    int in_len = sizeof(arr) / sizeof(int);
    LIS(arr , in_len);

}
