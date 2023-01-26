#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    __int64 m,n,k,t,p;
    cin>>p;
    for(k=0;k<p;k++){
        cin>>m>>n;
        __int64 a=log2(m);
        __int64 b=log2(n);
        //cout<<a<<" "<<b<<endl;
        if(a==b){
            cout<<0<<endl;
        }else{
            if(b!=a+1){
            __int64 x=pow(2,a+1);
            __int64 y=pow(2,b-1);
            //cout<<x<<" "<<y<<endl;
            cout<<min(n-x+1,y-m+1)<<endl;
        }else{
            cout<<min(n-pow(2,b)+1,pow(2,b)-m)<<endl;
        }
        }
    }
}
