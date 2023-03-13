#include<bits/stdc++.h>
using namespace std;

double pow(double x , long n)
{
  if(x<0)
  {
    x = 1/x;
    n = -n;
  }
  if(x==1) return 1;
  if(n==1) return x;
  double temp = pow(x,n/2);
  if(x%2==1) return temp*temp*x;
  return temp*temp;
}
int main(){
  long n;
  double x;
  cin>>n>>x;
  cout<<pow(n,x);
  return 0;
}