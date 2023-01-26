#include <bits/stdc++.h>

using namespace std;

#define maxn 200005

int n;

long long a[maxn];

long long it[4*maxn];

long long dis[maxn];

void build(int x,int lx,int rx)
{
  if (rx < lx)
    return;
  if (lx == rx)
  {
    it[x] = abs(a[lx+1]-a[lx]);
    return;
  }

  int midx = (lx+rx)/2;
  build(2*x,lx,midx);
  build(2*x+1,midx+1,rx);

  if (it[2*x] == 0 && it[2*x+1] == 0)
    it[x] = 0;
  else
    it[x] = __gcd(it[2*x],it[2*x+1]);
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

if(t1== 0 && t2 == 0)
    return 0;

return __gcd(t1,t2);

}

int main(){

int t;

scanf("%d",&t);

for(int o=1;o<=t;++o){

scanf("%d",&n);

for(int i=1;i<=n;++i){

scanf("%lld",&a[i]);

}



build(1,1,n-1);

//cout << ok(4);

int ans=1;

  int u=1;

    for(int i=2;i<=n;++i)
    {
        while(u<i-1&&getgcd(1,1,n,u,i-1)==1)
            u++;

        ans=max(ans,i-u+1);
    }
printf("%d\n",ans);


}

}
