// Rishabh Agarwal aka ranger2k

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define F first
#define S second
#define ll long long int

const ll mod = 1e9+7;
const ll INF = 1e18;
const long double PI = 3.1415926;

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll temp = power(a, b / 2) % mod;
    if (b % 2 == 0)
    {
        return (temp * temp) % mod;
    }
    else
    {
        return ((a * temp) % mod * temp) % mod;
    }
}

ll gcd(ll a, ll b)
{
    if (a<b)
        return gcd(b,a);
    else if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll modInverse(ll a)
{
    return power(a, mod - 2) % mod;
}

void reverse(vector<ll> &a, ll i, ll j)
{
    if (i > j)
    {
        swap(i, j);
    }
    ll len = j - i + 1;
    for (ll x = i; x < i + len / 2; x++)
    {
        swap(a[x], a[j]);
        j--;
    }
}

// ll prime[1000006];
// void sieve(ll MAXN=1000006)
// {
//     prime[1] = 1;
//     for (ll i=2; i<MAXN; i++)
//         prime[i] = i;
//     for (ll i=4; i<MAXN; i+=2)
//         prime[i] = 2;
//     for (ll i=3; i*i<MAXN; i++)
//     {
//         if (prime[i] == i)
//         {
//             for (ll j=i*i; j<MAXN; j+=i)
//                 if (prime[j]==j)
//                     prime[j] = i;
//         }
//     }
// }

// ll divisors(ll x){
//     unordered_map<ll,ll>ump;
//     while (x != 1)
//     {
//         ump[prime[x]]++;
//         x = x / prime[x];
//     }
//     ll total=1;
//     for(auto i:ump){
//         total=total*(i.S+1);
//         total%=mod;
//     }
//     return total;
// }

void solve()
{   
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    string s1 = s, s2 = s;
    ll pre[n],suf[n];
    pre[0]=0;
    suf[n-1]=0;
    bool vis[3];
    memset(vis,false,sizeof(vis));
    for(ll x=1; x<n; x++){
        ll flag=0;
        if(s1[x]==s1[x-1]){
            flag=1;
        }
        if(x>1&&s1[x]==s1[x-2]){
            vis[int(s1[x-2])-97]=true;
            flag=1;
        }
        if(flag){
            vis[int(s1[x-1])-97]=true;
            if(x>1)
                vis[int(s1[x-2])-97]=true;
            else if(x+1<n)
                vis[int(s1[x+1])-97]=true;
            else if(x+2<n&&s1[x-1]==s1[x+1])
                vis[int(s1[x+2])-97]=true;
            for(ll y=0; y<3; y++){
                if(vis[y]==false){
                    s1[x]=char(y+97);
                    break;
                }
            }
        }
        if(flag)
            pre[x]=pre[x-1]+1;
        else
            pre[x]=pre[x-1];
        memset(vis,false,sizeof(vis));
    }
    for(ll x=n-2; x>=0; x--){
        ll flag=0;
        if(s2[x]==s2[x+1]){
            flag=1;
        }
        if(x<n-2&&s2[x]==s2[x+2]){
            flag=1;
        }
        if(flag){
            vis[int(s2[x+1])-97]=true;
            if(x<n-2)
                vis[int(s2[x+2])-97]=true;
            else if(x-1>=0)
                vis[int(s2[x-1])-97]=true;
            else if(x-2>=0&&s2[x-1]==s2[x+1])
                vis[int(s2[x-2])-97]=true;
            for(ll y=0; y<3; y++){
                if(vis[y]==false){
                    s2[x]=char(y+97);
                    break;
                }
            }
        }
        if(flag)
            suf[x]=suf[x+1]+1;
        else
            suf[x]=suf[x+1];
        memset(vis,false,sizeof(vis));
    }
    for(ll x=0; x<m; x++){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        ll ans1,ans2;
        if(a==0){
            ans1 = pre[b];
        }
        else{
            ans1 = pre[b]-pre[a-1];
        }
        if(b==n-1){
            ans2 = suf[a];
        }
        else{
            ans2 = suf[a]-suf[b+1];
        }
        cout<<min(ans1,ans2)<<"\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   #ifndef ONLINE_JUDGE
       freopen("inp.txt", "r", stdin);
       freopen("out.txt", "w", stdout);
   #endif

    ll No_of_cases;
    No_of_cases = 1;
    // cin >> No_of_cases;
    // ll Case = 1;
    while (No_of_cases--)
    {
        // ll ans = 0;
        solve();
        // cout << "Case #" << Case << ": " << ans << "\n";
        // Case++;
    }
    return 0;
}
