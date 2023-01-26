#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define debug(x) cerr << #x << " " << x << "\n"
#define debugs(x) cerr << #x << " " << x << " "

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair <ll, ll> pii;
typedef pair <long double, pii> muchie;

const ll NMAX = 400005;
const ll VMAX = 200000;
const ll INF = (1LL << 59);
const ll MOD = 998244353;
const ll BLOCK = 318;
const ll base = 31;
const ll nr_of_bits = 21;
vector <int> Ys[NMAX];
vector <int> aib[NMAX];
struct mazan
{
    int x,y,z;
} v[NMAX];
int n;
int lsb(int x)
{
    return x&-x;
}
bool cmp(mazan a,mazan b)
{
    return a.x<b.x;
}
void upd(int x,int y,int val)
{
    for(; x<=n; x+=lsb(x))
    {
        int normy=1+(lower_bound(Ys[x].begin(),Ys[x].end(),y)-Ys[x].begin());
        for(; normy<=Ys[x].size(); normy+=lsb(normy))
            aib[x][normy]=max(aib[x][normy],val);
    }
}
int ans(int x,int y)
{
    int max1=0;
    for(; x>0; x-=lsb(x))
    {
        int normy=1+(upper_bound(Ys[x].begin(),Ys[x].end(),y)-Ys[x].begin())-1;

        for(; normy>0; normy-=lsb(normy)){
            max1=max(max1,aib[x][normy]);
        }
    }
    return max1;
}
void preupdate(int x,int y)
{
    for(; x< NMAX; x+=lsb(x))
        Ys[x].push_back(y);
}
int main()
{
    int t,i,max1,x;
    cin>>n;
    t = 1;
    while(t--)
    {
        max1=0;
        int cnt = 0;
        for(i=1; i<=n; i++)
        {
            v[++cnt].x = i;
            cin>>v[cnt].z;
            v[cnt].y = v[cnt].z - i;
            if(v[cnt].y > 0){
                cnt--;
                continue;
            }
            v[cnt].y = n + v[cnt].y;
            preupdate(v[cnt].y,v[cnt].z);
        }
        for(i=1; i<=n; i++)
        {
            aib[i].resize(Ys[i].size()+1,0);
            sort(Ys[i].begin(),Ys[i].end());
        }
        sort(v+1,v+cnt+1,cmp);
        for(i=1; i<=cnt; i++)
        {
            x=ans(v[i].y,v[i].z)+1;
            max1=max(max1,x);
            upd(v[i].y,v[i].z,x);

        }
        cout<<max1<<'\n';
        for(i=1; i<=cnt; i++)
        {
            Ys[i].clear();
            aib[i].clear();
        }
    }
    return 0;
}
