#include<iostream>
#include<math.h>
using namespace std;
 
int main()
{
    __int64 m,n,k,t,p;
    cin>>p;
    for(k=0;k<p;k++){
        cin>>m>>n;
        __int64 a,b,odds;
        a=log2(m);
        b=log2(n);
        if(m%2==0 && n%2==0) odds=(n-m)/2;
        if(m%2!=0 && n%2!=0) odds=((n-m)/2);
        else odds=(n-m)/2+1;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        a=log2(m)+1;
        if(ceil(log2(n))==floor(log2(n))){
            b=log2(n)-1;
            __int64 x=min((__int64)(n-pow(2,a)+1),odds);
            cout<<min((__int64)(pow(2,b)-m+1),x)<<endl;
        }else{
            b=log2(n);
            __int64 x=min((__int64)(n-pow(2,a)+1),odds);
            cout<<min((__int64)(pow(2,b)-m),x)<<endl;
        }
    }
}