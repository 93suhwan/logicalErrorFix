#include <bits/stdc++.h>

using namespace std;

#define maxn 200005

int n;

long long a[maxn];

long long it[5*maxn];


void updategcd(int r,int k,int l,int u,long long val){

if(u<k || u>l){

return;

}

if(u==k && u==l){

it[r]=val;

return;

}

int g=(k+l)/2;

updategcd(2*r,k,g,u,val);

updategcd(2*r+1,g+1,l,u,val);

it[r]=__gcd(it[2*r],it[2*r+1]);

}

long long getgcd(int r,int k,int l,int u,int v){

if(u>l || v<k){

return 0;

}

if(u<=k && l<=v){

return it[r];

}

int g=(k+l)/2;

long long t1=getgcd(2*r,k,g,u,v);

long long t2=getgcd(2*r+1,g+1,l,u,v);

it[r]=__gcd(it[2*r],it[2*r+1]);

return __gcd(t1,t2);

}

int main(){

int t;

scanf("%d",&t);

for(int o=1;o<=t;++o){

    scanf("%d",&n);

    int ans=1;

    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);

    for(int i=1;i<n;++i)
        updategcd(1,1,n-1,i,abs(a[i]-a[i+1]));

    int u=1;

    for(int i=2;i<=n;++i)
    {
        while(u<i-1&&getgcd(1,1,n-1,u,i-1)==1)
            u++;

        ans=max(ans,i-u+1);
    }



    printf("%d\n",ans);
}
}
