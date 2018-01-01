/*
    文字列関係のライブラリ
*/

#include <iostream>
#include <string>
using namespace std;

/*
    文字列を数値に変換
*/
int str_to_int(string s){
  int n=0,ten=1;
  char c;
  ten=pow(ten,L);
  rep(i,s.size()-1){
    c=s[i];
    n+=int(c-'0')*ten;
    ten/=10;
  }
  return n;
}


