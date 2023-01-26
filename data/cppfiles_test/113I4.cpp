#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define gc getchar_unlocked
#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define ci(x) cin>>x
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
#define fo(i, n) for(int i=0;i<n;i++)
#define foi(i, n) for(int i=1;i<=n;i++)
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) fo(i, n){cout << a[i] << " ";}
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
const int mod = 1'000'000'007;
const int N = 3e5;
ll gcd(ll a,ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
/*vector<vector<int>>adj(5e5+10);
map<int,int>visited;
vector<int>ans;
void dfs(int x)
{
    for(int y:adj[x])
    {
        if(visited[y])
            continue;
        visited[y]=1;
        dfs(y);
    }
    ans.push_back(x);
}*/
ll maxp(ll n,ll k)
{
    ll step=0;
    while((long long int )pow(k,step)<=n)
    {
        step++;
    }
    return step-1;
}
/*map<ll,ll>p;
bool power(ll n, ll k)
{
    int f=0;
    while(n>0)
    {
        ll s=maxp(n,k);
        p[s]++;
        //cout<<n<<" "<<s<<" "<<p[s]<<" "<<n<<"\n";
        if(p[s]>1)
        {
            f=1;
            break;
        }
        n-=(long long int)pow(k,s);
    }
    if(f==1)
        return false;
    else
        return true;
}*/
ll power(long long x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
/*int te(int k)
{
    int count=0;
    while(k%2==0)
    {
        k/=2;
        count++;
    }
    return count;
}*/
/*vector<int>prime(1e6+10);
void precalc()
{
    prime[1]=1;
    for(int i=2;i<=1e6;i++)
    {
       if(!prime[i])
       { 
          for(int j=2*i;j<=1e6;j+=i)
          prime[j]=1;
       }
    }
}*/
void solution()
{
  ll a,n;
  cin>>a>>n;
  ll b,m;
  cin>>b>>m;
  ll t=min(n,m);
  a=a*(long long int)pow(10,n-t);
  b=b*(long long int)pow(10,m-t);
  if(a>b)
    cout<<">\n";
else if(a<b)
    cout<<"<\n";
else
    cout<<"=\n";
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#else
// online submission
#endif
    /*srand(chrono::high_resolution_clock::now().time_since_epoch().count());*/
     ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    ci(t);
    //precalc();
    while (t--) {
        solution();
    }
    return 0;
}