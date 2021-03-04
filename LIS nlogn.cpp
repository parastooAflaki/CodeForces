/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


int binary_search(int arr[] , vector<int> tails,int key , int low , int high){

    if(high - low > 1){
        int mid = (high + low)/2;
        if(arr[tails[mid]] < key)
            return binary_search(arr ,tails , key , mid , high);
        else
            return binary_search(arr ,tails, key , low , mid);
    }
    return high;


}

void LIS (int seq[] , int size_seq){

    vector<int> prev(size_seq , -1);
    vector<int> tails(size_seq , 0);

    tails[0] = 0;
    int max_len = 1;

    for(int i = 1; i < size_seq ; i++){

        if(seq[i] < seq[tails[0]])
            tails[0] = i;

        else if (seq[i] > seq[tails[max_len - 1]]){
            prev[i] = tails[max_len-1];
            tails[max_len++] = i;
            }

        else{
            int substitude = binary_search(seq , tails , seq[i] , 0 , max_len - 1 );
            prev[i] = tails[substitude - 1];
            tails[substitude] = i;
        }

    }
    cout << "LIS of given input " << max_len<< endl;
    //   for(int i = 1; i < size_seq ; i++){

    //       cout<< prev[i] <<endl;
    //   }

    for (int i = tails[max_len - 1]; i != -1; i = prev[i])
        cout << seq[i] << " ";
    cout << endl;

}


int main()
{
   int arr[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
   int size_seq = sizeof(arr) / sizeof(int);
   cout << size_seq<<endl;
   LIS(arr , size_seq);

    return 0;
}
