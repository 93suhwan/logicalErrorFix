#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll  long long int
#define ull unsigned long long
#define ld long double
const ll mod = 1e9+7;
#define pb push_back
#define f first
#define s second
#define ump unordered_map<ll,pair<ll,ll>>
#define um unordered_map<ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pi pair<ll,ll> 
#define pii pair<ll,pair<ll,ll>>
#define pq priority_queue<pi, vector<pi>, greater<pi>>
#define pis pair<ll,string>
#define vp vector<pair<ll,ll>>
#define lp(x,n) for(ll x = 0; x < n; x++)
#define rp(x,n) for(ll x=n-1; x>=0; x--)
typedef pair<ll, ll> node;
typedef tree<node, null_type, less<node>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// ll binpow(ll a, ll b) 
// {
//     if(b == 0)
//     {
//         return 1;
//     }
//     ll ans = binpow(a,b/2);
//     ans *= ans;
//     ans %= mod;
//     if(b % 2)
//     {
//         ans *= a;
//     }
//     return ans % mod;
// }
// ll gcd(ll a, ll b)
// {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }
// vector<ll> div(ll n)
// {
//     vector<ll> v;
//     for(ll i=1; i<=sqrt(n); i++)
//     {
//         if(n%i==0)
//         {
//             v.pb(i);
//             v.pb(n/i);
//         }
//     }
//     return v;
// }
// ll fact(ll n)
// {
//     if(n==0 || n==1)
//         return 1;
//     return n*fact(n-1);
// }
// vector<ll> decimal(ll n)
// {
//     vector<ll> v;
//     while(n)
//     {
//         v.pb(n%2);
//         n/=2;
//     }
//     reverse(v.begin(), v.end());
//     return v;
// }
// struct UnionFind
// {
//     ll n;
//     vector<ll> rank;
//     vector<ll> parent;
//     UnionFind(ll n) 
//     {
//         rank.resize(n);
//         fill(rank.begin(), rank.end(), 0);
//         parent.resize(n);
//         for (ll i = 0; i < n; i++)
//         {
//             parent[i] = i;
//         }
//     }
//     ll find(ll a) 
//     {
//         return parent[a] = (parent[a] == a ? a : find(parent[a]));
//     }
//     bool isconnected(ll a, ll b)
//     {
//         return find(a) == find(b);
//     }
//     void merge(ll a, ll b)
//     {
//         a = find(a);
//         b = find(b);
//         if (rank[a] == rank[b])
//         {
//             rank[a]++;
//         }
//         if (rank[a] > rank[b]) 
//         {
//             parent[b] = a;
//         } else 
//         {
//             parent[a] = b;
//         }
//         return;
//     }
// };
// priority_queue<pis, vector<pis>, greater<pis>> q;
// void haspath(vector<pi> adj[], ll src, vector<ll>& visited , string p, ll v, ll wt)
// {
//     if(p.length()== 2*v-1)
//     {
//         q.push({wt,p});
//         return;
//     }
//     visited[src] = 1;
//     for( auto i : adj[src])
//     {
//         if(!visited[i.f])
//         {
//             haspath(adj, i.f, visited , p+" "+to_string(i.f), v, wt+i.s);
//         }
//     }
//     visited[src] = 0;
//     return;
// }
// vector<ll> v;
// void bfs(ll root, vector<vector<ll>>& dist, vector<ll> adj[], ll n)
// {
//     priority_queue<pair<ll,ll>> q;
//     vector<ll> visited(n+1,0);
//     q.push({0,root});
//     v.resize(n+1, 0);
//     v[0] = 0;
//     while(!q.empty())
//     {
//         ll d = q.top().first;
//         ll src = q.top().second;
//         q.pop();
//         if(visited[src])
//             continue;
//         visited[src]=1;
//         for(auto j: adj[src])
//         {
//             if(!visited[j])
//             {
//                 if(v[j] < d + 1)
//                 {
//                     v[j] = d+1;
//                     q.push({d+1,j});
//                 }
//             }
//         }
//     }
// }
// ll find(ll n, vector<ll> adj[], vector<ll>& vec)
// {
//     ll res = 0;
//     vector<vector<ll>> dist;
//     v.resize(n+1,0);
//     dist.pb(v);
//     for(ll i=1; i<=n; i++)
//     {
//         v.clear();
//         bfs(i,dist,adj,n);
//         dist.pb(v);
//     }
//     // for(ll i=1; i<=n; i++)
//     // {
//     //     for(ll j=1; j<=n; j++)
//     //     {
//     //         cout<<dist[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     vector<ll> visited(n+1,0);
//     priority_queue<pii> q;
//     for(ll i=0; i<vec.size()-1; i++)
//     {
//         for(ll j= i+1; j<vec.size(); j++)
//         {
//             q.push({dist[vec[i]][vec[j]],{vec[i],vec[j]}});
//             //q.push({dist[vec[i]][vec[j]],{vec[j],vec[i]}});
//         }
//     }
//     while(!q.empty())
//     {
//         ll d = q.top().f;
//         ll ff = q.top().s.f;
//         ll ss = q.top().s.s;
//         q.pop();
//         if(visited[ff] || visited[ss])
//             continue;
//         //cout<<ff<<" "<<ss<<" "<<d<<endl;
//         res += d;
//         visited[ff]=1;
//         visited[ss]=1;
//     }
//     return res;
// }
int countofdigits(int num)
{
    int c = 0;
    while(num)
    {
        ++c;
        num /= 10;
    }
    return c;
}
int find(int n)
{
    int ans=0;
    while(n%2==0)
    {
        n=n/2;
        ans++;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            n=n/i;
            ans++;
        }
    }
    if(n>1)
    ans++;
    
    return ans;
}
bool okay(vector<int> v)
{
    int n = v.size();
    if(n <= 2)
        return true;
    if(n >= 5)
        return false;
    for(int i=0; i<n; i++)
    {
        for(int j= i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if((v[i]<=v[j] && v[j]<=v[k]) || (v[i]>=v[j] && v[j]>=v[k]))
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin); 
    freopen("output.txt", "w" ,stdout);   
    #endif
    ll t;
    //t=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ab=0, ba=0;
        for(int i=0; i<s.length()-1; i++)
        {
            if(s[i]=='a' && s[i+1]=='b')
                ++ab;
            else if(s[i]=='b' && s[i+1]=='a')
                ++ba;
        }
        if(ab==ba)
        {
            cout<<s<<endl;
            continue;
        }
        if(ab > ba)
        {
            int c = ab-ba;
            for(int i=0; i<s.length()-1; i++)
            {
                if(c>0 && s[i]=='a' && s[i+1]=='b')
                {
                    --c;
                    if(i==0 || s[i-1] != 'a')
                        s[i] = 'b';
                    else
                        s[i+1] = 'a';
                }
            }
        }
        else 
        {
            int c = ba-ab;
            for(int i=0; i<s.length()-1; i++)
            {
                if(c>0 && s[i]=='b' && s[i+1]=='a')
                {
                    --c;
                    if(i==0 && s[i-1] != 'b')
                        s[i] = 'a';
                    else
                        s[i+1] = 'b';
                    //s[i] = 'a';
                }
            }
        }
        cout<<s<<endl;
    }
}