#include <iostream>
#include <string>
using namespace std;
#define MAX 100
int len_substrs[MAX][MAX];

void LCS(string str1 , string str2 , long len_str1 , long len_str2 ){

  for (int i = 1; i <= len_str1; i++)
	{
		for (int j = 1; j <= len_str2; j++)
		{
			
      if(str1[i-1] == str2[j-1])
        len_substrs[i][j] = len_substrs[i-1][j-1] +1;
      else
        len_substrs[i][j] = max(len_substrs[i][j-1] , len_substrs[i-1][j]);
		}
	}


    std::cout << "Max Len " << len_substrs[len_str1][len_str2]<< '\n';

}

int main(){


string str1 , str2;
cin >>str1 >>str2;
long len_str1 = str1.length() , len_str2 = str2.length();
LCS(str1 , str2 , len_str1 , len_str2);


}
