#include<bits/stdc++.h>
using namespace std;
int ff() { int x=0; int c=getchar(),n=0; for(; !isdigit(c); c=getchar()) n=(c=='-'); for(; isdigit(c); c=getchar()) x=x*10+c-'0'; if(n) x=-x; return x; }
#define in ff()
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fi first
#define se second
#define pii pair<int,int>
#define ii pair<int,pii>
#define getbit(i,x) ((x>>i)&1)
#define tatbit(i,x) (x&~(1<<i))
#define batbit(i,x) (x^(1<<i))
#define task "C"

const int maxn=2e5+10;
int n,m,sum;
int a[maxn];
main(){
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    forinc(i,1,n) cin>>a[i],sum+=a[i];
    sort(a+1,a+n+1);
    cin>>m;
    forinc(i,1,m){
        int x,y;cin>>x>>y;
        int ret = -1;
        int l=1,r=n,pos= -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(a[mid]>=x) pos = mid,r=mid-1;
            else l = mid+1;
        }
        if(pos!=-1) ret = max(0ll,y - sum+a[pos]);
      //  cout<<ret<<" "<<pos<<"\n";
        pos --;
     //   cout<<ret<<" "<<pos<<"\n";
        if(pos>0){
            ret = min(ret,x-a[pos]+max(0ll,y-(sum-a[pos])));
        }
        if(ret==-1){
            ret = x-a[n] + (sum-a[n] >=y ? 0 : y - sum + a[n]);
        }
        cout<<ret<<"\n";
    }
}





