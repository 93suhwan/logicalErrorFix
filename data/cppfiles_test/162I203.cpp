#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define fin(i,a,b) for(ll i=a; i<b; i++)
#define finr(i,a,b) for(ll i=a; i>=b; i--)
template<class T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
/*struct edge{
    int a; int b; int w;
};
edge arr[10000000];
int par[3001];
bool comp(edge a, edge b){
    if(a.w<b.w) return true;
    return false;
}
int find_it(int a){
    if(par[a]==-1) return a;
    return par[a]=find_it(par[a]);
}
void merge_it(int a, int b){
    par[a]=b;
}
ll vis[100001]={0},col[300001]={0},dis[300001]={0};
vector<ll> arr[300001],v;
ll t[201][400];
long wt[10000][10000];
long long ans = 0;*/
bool isprime(ll x){
    if(x==1)return false;
    else{
        int a=0;
        for(int i=2; i<=sqrt(x); i++){
            if(x%i==0){
                a++;
                break;
            }
        }
        if(a>0)return false;
        else return true;
    }
}
ll first(ll x){
    for(int i=2; i<=sqrt(x); i++){
        if(x%i==0)return i;
    }
}
/*long long prime(long long y){
    while(isprime(y)==false){
        y++;
    }
    return y;
}
ll invfact[300001],fact[300001],invnum[300001];
long long combination(long long n, long long r){
    if(n<r)return 0;
    else{
        ll ans = ((fact[n]*invfact[r])%mod*invfact[n-r])%mod;
        return ans;
    }
}
/*void bfs(int node){
    queue<int> q;
    q.push(node);
    vis[node]=1;
    dis[node] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int child : arr[curr]){
            if(vis[child]==0){
                q.push(child);
                dis[child] = dis[curr]+6;
                vis[child] = 1;
            }
        }
    }
}
void dfs(ll node, vector<ll> &v, ll n){
    vis[node]=1;
    for(ll child : arr[node]){
        if(vis[child]==0){
            dfs(child,v,n); col[node]+=1+col[child];
            ll tempo = (n-col[child]-1)*(col[child]+1);
            v.push_back(tempo);
        }
    }
}
/*bool dfs2(ll node1, ll node2){
    vis[node1] = 1;
    for(ll child : arr[node1]){
        if(vis[child]==0){
            if(child==node2)return 1;
            else if(dfs2(child,node2))return 1;
        }
    }
    return 0;
}
/*int knapsack(int n, int arr[], int k){
    if(n==0)
        return 0;
    else if(t[n][k]!=-1)
        return t[n][k];
    else if(arr[n-1]<=k){
        t[n][k]=max(arr[n-1]+knapsack(n,arr,k-arr[n-1]),arr[n-1]+knapsack(n-1,arr,k-arr[n-1]));
        t[n][k]=max(t[n][k],knapsack(n-1,arr,k));
        return t[n][k];
    }
    else
        return t[n][k]=knapsack(n-1,arr,k);
}*/
ll power(ll a, ll b)
{
    ll result = 1;
    while(b){
        if(b&1)result*=a;
        b/=2;
        if(b>0)a*=a;
    }
    return result;
}
/*void subsetsUtil(ll *c, vector<vector<ll> > &res,
                 vector<ll> &subset, int index, int n)
{
    res.push_back(subset);
    for (int i=index; i<n; i++){
        subset.push_back(c[i]);
        subsetsUtil(c, res, subset, i+1, n);
        subset.pop_back();
    }
    return;
}
vector<vector<ll> > subsets(ll *c, int n)
{
    vector<ll> subset;
    vector<vector<ll> > res;
    int index = 0;
    subsetsUtil(c, res, subset, index, n);
    return res;
}
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
ll modinv(ll a)
{
    ll x, y;
    ll g = gcdExtended(a, mod, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        ll res = (x % mod + mod) % mod;
        return res;
    }
}
void floyd(){
    for(ll k=0; k<26; k++){
        for (ll i=0; i<26; i++)
            for (ll j=0; j<26; j++) {
                if (t[i][j]>(t[i][k]+t[k][j])&& (t[k][j]!=LLONG_MAX&&t[i][k]!=LLONG_MAX))
                    t[i][j] = t[i][k] + t[k][j];
        }
    }
}
ll dp[5001][5001], ans = 0;
void lcs(string x, string y){
    ll n = x.size(), m = y.size();
    fin(i,1,n+1){
        fin(j,1,m+1){
            if(x[i-1]==y[j-1])dp[i][j] = max({max(dp[i-1][j],dp[i][j-1])-1,dp[i-1][j-1]+2});
            else dp[i][j] = max({dp[i-1][j],dp[i][j-1]})-1;
            if(dp[i][j]<0)dp[i][j] = 0;
            ans = max(ans,dp[i][j]);
        }
    }
}
bool issubsequence(string str1, string str2, ll n, ll m)
{
    ll j = 0;
    for(ll i = 0; i<m && j<n; i++)
        if (str1[j]==str2[i])
            j++;
    return (j == n);
}*/
ll func(ll a[], ll b[], ll n, ll m, ll p){
    ll x = 0, y = 0;
    fin(i,0,n){
        if(a[i]%p!=0){
            x = i; break;
        }
    }
    fin(i,0,m){
        if(b[i]%p!=0){
            y = i; break;
        }
    }
    return x+y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("ouput.txt", "w", stdout);
    //vector<ll> pri;
    /*for(ll i=2; i<1000001; ){
        if(isprime(i)){
            pri.push_back(i);
            i++;
        }
        else{
            ll t = prime(i);
            i=t+1;
            pri.push_back(t);
        }
    }
    invnum[0]=1; invnum[1]=1; fact[0]=1; invfact[0]=1; invfact[1]=1;
    fin(i,1,300001){
        fact[i] = (fact[i-1]*i)%mod;
    }
    fin(i,2,300001){
        invnum[i] = invnum[mod%i]*(mod-mod/i)%mod;
    }
    fin(i,2,300001){
        invfact[i] = (invnum[i]*invfact[i-1])%mod;
    }*/
    int w=1;
    cin>>w;
    while(w--){
        ll n; cin>>n;
        ll h[n];
        fin(i,0,n)cin>>h[i];
        ll ans, low = 1, high = power(10,9);
        while(low<=high){
            ll mid = (low+high)/2;
            ll tempo[n];
            fin(i,0,n)tempo[i] = h[i];
            fin(i,0,n-1){
                if(tempo[i]<mid){
                    if(i+1>=2){
                        ll x = min(mid-tempo[i],tempo[i+1]/3);
                        tempo[i]+=x; tempo[i-1]+=2*x;
                        tempo[i+1]-=3*x;
                    }
                    if(tempo[i]<mid&&i+2<n){
                        ll x = min((mid-tempo[i]+1)/2,tempo[i+2]/3);
                        tempo[i]+=2*x; tempo[i+1]+=x;
                        tempo[i+2]-=3*x;
                    }
                }
            }
            bool f = 1;
            fin(i,0,n){
                if(tempo[i]<mid)f = 0;
            }
            if(f){
                ans = mid; low = mid+1;
            }
            else high = mid-1;
        }
        cout<<ans<<endl;
    }
}
