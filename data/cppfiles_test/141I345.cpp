#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <stdio.h>
using namespace std;
using namespace __gnu_pbds;
#define ll int64_t
#define ld long double
#define ull unsigned long long
#define pi pair<ll,ll>
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007
#define IMAX INT64_MAX
#define IMIN INT64_MIN
#define send string::npos
#define endl "\n"



bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}


ll max(ll a,ll b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

ll min(ll a,ll b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a, b);
}


ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
    {
        res = res * i;
    }
    return res;
}

ll nCr(ll n, ll r)
{
    return (fact(n) / (fact(r) * fact(n - r)));
}



ll fpow(ll base,ll exp)
{
    base%=1000000000000000007;
    ll ans=1;
    while(exp)
    {
        if(exp&1) {ans*=base; ans%=1000000000000000007;}
        exp/=2;
        base*=base;
        base%=1000000000000000007;
    }
    return ans;
}

class DSU {
public:
    int n;
    vector<int> parent,size;

    DSU(int a) {
        n = a;
        parent.assign(n,0);
        size.assign(n,0);
        for(int i=0 ; i<n ; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void makeSets(int k) {
        for(int i=0 ; i<n ; i++) {
            if(find(i) != i) {
                size[i] = 0;
            }
        }
    }

    int find(int a) {
        int root = a;
        while(root != parent[root]) {
            root = parent[root];
        }
        while(root != a) {
            int temp = parent[a];
            parent[a] = root;
            a = temp;
        }
        return root;
    }

    void unionSet(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b) return;
        if(size[a] < size[b]) {
            parent[root_a] = root_b;
            size[root_b] += size[root_a];
        }
        else {
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
        }
    }
};


set<ll> intersection(set<ll> s1,set<ll> s2)
{
    set<ll> intersect;
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), inserter(intersect,intersect.begin()));
    return intersect;
}
set<ll> unioun(set<ll> s1,set<ll> s2)
{
    set<ll> intersect;
    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(), inserter(intersect,intersect.begin()));
    return intersect;
}




class unionFind
{
public:
    vector<int> rank,p;
    int noc;
public:
    unionFind(int n)
    {
        rank.assign(n,0);
        p.assign(n,0);
        noc=n;
        for(int i=0;i<n;i++)
        {
            p[i]=i;
        }
    }
    int find(int i)
    {
        return (p[i] == i) ? i : (p[i] = find(p[i]));
    }
    bool isSameSet(int i,int j)
    {
        return find(i)==find(j);
    }
    void unionSet(int i,int j)
    {
        if(!isSameSet(i,j))
        {
            int x=find(i);
            int y=find(j);
            noc--;
            if(rank[x]>rank[y])
            {
                p[y]=x;
            } else{
                p[x]=y;
            }
            if(rank[x]==rank[y])
            {
                rank[y]++;
            }
        }
    }
    int getNoc()
    {
        return noc;
    }

};



struct safe_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct tri
{
    unordered_map<char,tri*> child;
    bool end;
    tri()
    {
        for(char i='a';i<='z';i++)
        {
            child[i]=NULL;
        }
        end=false;
    }
};



const ll INF = 1e18;

vector<ll> inv, FactorialInv, Factorial;
ll beki(ll a, ll b){
    ll ret = 1 % mod;
    a %= mod;
    while(b) {
        if(b & 1LL) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void init_combination(ll MAX){
    Factorial.resize(MAX + 1);
    FactorialInv.resize(MAX + 1);
    inv.resize(MAX + 1);
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], mod - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
    }
}
ll nCr1(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    if(b < 0) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}
const long long MAX_SIZE = 1000001;
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
void sieve(int N)
{
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false ;

    // Fill rest of the entries
    for (long long int i=2; i<N ; i++)
    {

        if (isprime[i])
        {

            prime.push_back(i);

            SPF[i] = i;
        }
        for (long long int j=0;
             j < (int)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;

            // put smallest prime factor of i*prime[j]
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

bool luc(ll a,ll d)
{
    while(a>0)
    {
        if(a%10==d)
        {
            return 1;
        }
        a/=10;
    }
    return 0;
}
ld ceil1(ld a,ld b)
{
    ld c=(a+b-1)/b;
    return c;
}



ll lowerBound(vector<ll> &arr,ll r,ll l,ll d)
{
    ll ans=-1;
    while(l<=r)
    {
        int mid=(l+(r))/2;
        if(arr[mid]==d)
        {
            ans=mid;
            r=mid-1;
        }
        else if(arr[mid]>d)
        {
            r=mid-1;
        }

        else
        {
            l=mid+1;
        }
    }
    if(ans==-1)
    {
        if(r==-1)
        {
            return 0;
        }
        return r;
    }
    return ans;
}

//map<ll,vector<ll>> v,ch;
//map<ll,ll> par;
//map<ll,ll> vis;
//map<ll,ll> dep,dep1;
//set<ll> leaves;
//ll ed=0;
//ll ve=0;

//void dfs(ll x)
//{
//    vis[x]=1;
//    ed+=v[x].size();
//    ve++;
//    for(auto&i:v[x])
//    {
//        if(!vis[i])
//        {
//            dep[i] = dep[x] + 1;
//            par[i]=x;
//            ch[x].push_back(i);
//            dfs(i);
//            dp[x][0]+=max(dp[i][0]+abs(nos[i].first-nos[x].first),dp[i][1]+abs(nos[i].second-nos[x].first));
//            dp[x][1]+=max(dp[i][0]+abs(nos[i].first-nos[x].second),dp[i][1]+abs(nos[i].second-nos[x].second));
//        }
//    }
//
//}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //        init_combination(1050000);
    ll t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        string s1,s2,h="";
        cin>>s1>>s2;

        ll n1=s1.length(),n2=s2.length();

        int i=n1-1,j=n2-1,e=1;
        while(i>=0&&j>=0)
        {
            if(s1[i]<=s2[j])
            {
                h=to_string(s2[j]-s1[i])+h;
                i--;j--;
            }
            else
            {
                if(j-1<0)
                {
                    cout<<-1<<endl;
                    e=0;
                    break;
                }
                int x=stoi(s2.substr(j-1,2)),y=s1[i]-48;
                if((x-y)<=9)
                {
                    h=to_string(x-y)+h;
                    i--;j-=2;
                }
                else
                {
                    cout<<-1<<endl;
                    e=0;
                    break;
                }

            }

        }
        if(j<0&&i>=0){cout<<-1<<endl;continue;}
        if(j>=0&&i<0)
        {
            h=s2.substr(0,j+1)+h;
        }

        if(e)
        {
            for(int l=0;l<h.length();l++)
            {
                if(h[l]!='0')
                {
                    cout<<h.substr(l,h.length()-l+1)<<endl;
                    break;
                }
            }
        }

    }


}
