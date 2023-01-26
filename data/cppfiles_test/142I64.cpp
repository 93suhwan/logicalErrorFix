#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(),(x).end()
#define scan(a) for(auto &it:a)cin>>it;
#define print(a) {for(auto it:a)cout<<it<<" ";cout<<"\n";}
#define out(x) cout<<((x)?"YES\n":"NO\n");
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//#define prime (int)(1e9+7)
//#define prime (int)((1<<23)*7*17+1)
//#define int ll
const int MAXN = 1e5;
int LOG[MAXN+1];
const int K=25;
int st[MAXN][K + 1];
vector<int> b;
void fill(int N)
{
    for (int i = 0; i < N; i++)
    st[i][0] = b[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1];
}
int query(int L,int R)
{
    if(L>R)
        return INT_MAX;
    int j = LOG[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    return minimum;
}
void init()
{
    LOG[1] = 0;
    for (int i = 2; i <= MAXN; i++)
    LOG[i] = LOG[i/2] + 1;
}
    
void solve()
{
    int n,m;
    cin>>m>>n;
    int a[m][n],mx[n]={};
    rep(i,0,m)
    {
        rep(j,0,n)
        {
            cin>>a[i][j];
            if(a[mx[j]][j]<=a[i][j])
                mx[j]=i;
        }
    }
    set<int> unq;
    rep(i,0,n)
    unq.insert(mx[i]);
    if(unq.size()<=n-1)
    {
        int ans=INT_MAX;
        rep(i,0,n)
        ans=min(a[mx[i]][i],ans);
        cout<<ans<<endl;
        return;
    }
    b.resize(n);
    rep(i,0,n)
        b[i]=a[mx[i]][i];
    fill(n);
    int ans=0;
    rep(i,0,n)
    {
        rep(j,i+1,n)
        {
            int t=min(query(i+1,j-1),query(j+1,n-1));
            int x=0;
            rep(k,0,m)
            {
                x=max(min(a[k][i],a[k][j]),x);
            }
            ans=max(min(x,t),ans);
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t=1;
    init();
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
