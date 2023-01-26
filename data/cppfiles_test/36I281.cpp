#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fori(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define pii pair<int,int>
#define piii pair<int,pii>
#define f first
#define s second
#define bit(i,x) ((x>>i)&1ll)
#define onbit(i,x) (x|(1ll<<i))
#define offbit(i,x) (x&(~(1ll<<i)))
#define getbit(x,a) (x&(~((1<<a)-1)))
const int ma=1e2+5;
int t,n,a[ma],p[20005];
void prime()
{
    fori(i,1,20000) p[i]=i;
    fori(i,2,20000) if(p[i]==i)
    {
        fori(j,2,20000/i) p[i*j]=i;
    }
}
main(){
   // freopen("cpp.inp","r",stdin);
    prime();
    cin>>t;
    while(t--){
        cin>>n;
        int sum=0,odd=0;
        fori(i,1,n){
            cin>>a[i];
            sum+=a[i];
            if(a[i]%2) odd++;
        }
        if(p[sum]!=sum){
            cout<<n<<'\n';
            fori(i,1,n) cout<<i<<' ';
            cout<<'\n';
        }
        else{
            cout<<n<<'\n';
            sum=0;
            fori(i,1,n){
                if(a[i]%2&&!sum){
                    sum=1;
                }
                else cout<<i<<' ';
            }
            cout<<'\n';
        }
    }
}
