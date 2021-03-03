#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void LCS(string str1 , string str2 , long len_str1 , long len_str2 ){

  int len_substrs[len_str1 + 1][len_str2 + 1];
  int ending_index = 0;
  int max_len = -1;
  memset(len_substrs, 0, sizeof(len_substrs));
  for(int i = 1 ; i<len_str1+1 ; i++){
    for(int j =1 ; j < len_str2+1 ; j++){

      if(str1[i-1] == str2[j-1]){
        len_substrs[i][j] = len_substrs[i-1][j-1] +1;
         if(max_len < len_substrs[i][j]){
            max_len = len_substrs[i][j];
            ending_index = i-1;
          }
        }
      }
    }
    std::cout << "Max Len " << max_len<< '\n';
    string longest_substr =  str1.substr(ending_index - max_len+1, max_len);
    cout<<"Longest Common SubString is "<<longest_substr<<endl;
}

int main(){


string str1 , str2;
cin >>str1 >>str2;
long len_str1 = str1.length() , len_str2 = str2.length();
LCS(str1 , str2 , len_str1 , len_str2);


}
