#include <iostream>
#include <string>
using namespace std;

typedef string::const_iterator State;
typedef long long ll;

ll number(State &begin);
ll term(State &begin);
ll expression(State &begin);
ll factor(State &begin);

int main(){
  
  return 0;
}

ll number(State &begin){
  ll ret=0;
  while(isdigit(*begin)){
    ret*=10;
    ret+=(*begin-'0');
    begin++;
  }
  return ret;
}

ll term(State &begin){
  ll ret=factor(begin);
  while(1){
    if(*begin=='*'){
      begin++;
      ret*=factor(begin);
    }else if(*begin=='/'){
      begin++;
      ret/=factor(begin);
    }else{
      break;
    }
  }
  return ret;
}

ll expression(State &begin){
  ll ret=term(begin);
  while(1){
    if(*begin=='+'){
      begin++;
      ret+=term(begin);
    }else if(*begin=='-'){
      begin++;
      ret-=term(begin);
    }else{
      break;
    }
  }
  return ret;
}

ll factor(State &begin){
  ll ret=0;
  if(*begin=='('){
    begin++;
    ret=expression(begin);
    begin++;
  }else{
    ret=number(begin);
  }
  return ret;
}

