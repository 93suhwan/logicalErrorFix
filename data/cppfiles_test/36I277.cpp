#include <bits/stdc++.h>
#define int long long 
#define double float
#define pb push_back
#define F first 
#define S second 
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
long long po(int x,int y)
{
    int ans=1;
    while(y){
        if(y & 1) ans=(ans*x)%mod;
        y/=2;
        x=(x*x)%mod;
    }
    return ans;
}
int summ(int x,int y){
    return (x%mod)+(y%mod)%mod;
}
int mult(int x,int y){
    return ((x%mod)*(y%mod))%mod;
}
int  a[N];
int prefix[N],seive[N];
main(){ 
    for(int i=2;i<=1e6;i++){
        if(seive[i]==0)
            for(int j=i+i;j<=1e6;j++){
                seive[j]=1;
            }
    }
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int flag=0;
        int sum=0;
        prefix[0]=a[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+a[i];
        }
        int l,r;
        int x;
        int b=0;
        for(int i=0;i<n;i++){
            if(b==1)break;
            else{
            for(int j=n-1;j>=i;j--){
                if(i==0)x=prefix[j];
                else x=prefix[j]-prefix[i-1];
                if(seive[x]==1){
                    l=i;
                    r=j;
                    b=1;
                    break;
                }
            }
        }
        }
        cout<<r-l+1<<endl;
        for(int i=l;i<=r;i++){
            cout<<i+1<<" ";
        }
        cout<<endl;

    }
    
}