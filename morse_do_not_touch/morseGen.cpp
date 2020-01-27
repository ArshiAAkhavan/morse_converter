#include <bits/stdc++.h>

#define min(a,b)  ((a<b)?a:b)
#define max(a,b)  ((a>b)?a:b)
#define debug(x)  cerr<<#x<<" : "<<x<<"\n";
#define show(x,y) cerr<<#x<<","<<#y<<" : "<<x<<" , "<<y<<"\n";
#define wait()    scanf("%c",&waitChar);
char waitChar;


#define CHERT     (1000*10+10)//(1000*1000+10)
#define ULL unigned long long
using namespace std;

int f(int n){
  // debug(n);
  int ret=0;
  int p=1;
  while(n>0){
    // show(ret, n);
    // debug(p);
    ret+=(n%10)*p;
    n/=10;
    p*=3;
  }
  return ret;
}

int main(){
  int a,n;
  cin>>n;
  for(int i=0;i<n;i++){
    scanf("\n%c\t",&waitChar);
    cin>>a;
    // debug(a);
    cout<<f(a)<<",";
  }
}
