#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void Find_longest_polindrom(string str , long len_str){

  int is_palindrom[len_str + 1][len_str + 1];
  int begin_index = 0;
  int max_len = 1;
  memset(is_palindrom, 0, sizeof(is_palindrom));

  for(int i = 0 ; i < len_str ; i++)
    is_palindrom[i][i] = 1;

  for(int i = 0 ; i < len_str ; i++)
    if(str[i] == str[i+1]){
      is_palindrom[i][i+1] = 1;
      max_len = 2;
      begin_index = i;
    }
  for(int k = 3 ; k <len_str ; k++){

    for(int i = 0;i < len_str - k + 1 ; i++){
      int j = i + k -1;
      if(str[i] == str[j] && is_palindrom[i+1][j-1] == 1)
        {
          is_palindrom[i][j] = 1;
          max_len = k;
          begin_index = i;
        }
    }
  }

  for (int i = 0; i < len_str; i++) {
     for (int j = 0; j < len_str; j++) {
         cout<< is_palindrom[i][j]<<" ";
     }
     cout<<endl;
  }

  std::cout << "max len is " << max_len << '\n';
  std::cout << "max len palindrom " << str.substr(begin_index , begin_index + max_len )<<'\n';
}

int main(){


string str1 ;
cin >>str1 ;
long len_str1 = str1.length();
Find_longest_polindrom(str1 , len_str1);


}
