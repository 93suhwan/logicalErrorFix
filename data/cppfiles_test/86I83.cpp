#include <bits/stdc++.h>
using namespace std;
typedef vector< long long > vi;
typedef long long ll;
typedef long double ld;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fr(n) for(ll i=0;i<n;i++)
#define tr(a) for(auto it=a.begin();it!=a.end();it++)
#define N 1000000007
#define PI 3.1415926535897932384
#define F first
#define S second
#define elasped_time    1.0 * clock() / CLOCKS_PER_SEC
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
vector<pair<int,int>> go{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(pair<int,int> p,pair<int,int> n) {
    return p.first>=0 && p.first<n.first && p.second>=0 && p.second<n.second;
}
ll get( vector<ll> af1 , ll i ){
    if(af1[i]==i) return i ;
    return get(af1,af1[i]);
}
ll lcm(ll a, ll b){
    return (a/__gcd(a,b)) * b ;
}
struct UnionFind{
    int n,set_size,*parent, *rank ;
    UnionFind(){}
    UnionFind(int a) {
        n=set_size=a;
        parent = new int[n+1] ;
        rank = new int[n+1];
        for(int i = 1; i <= n; i++) parent[i]=i, rank[i]=1;}
    int find(int a){
        if(a!=parent[a]) return parent[a] = find(parent[a]);
        return a;
    }
    void merge(int x,int y) {
        int px = find(x) ; int py = find(y) ;
        if(px!=py) {
            if(rank[px] < rank[py]) {
                parent[px] = py;
                rank[py]+=rank[px];
            }
            else{
                parent[py] = px;
                rank[px]+=rank[py];
            }
            set_size-=1;
        }
    }
    int getRank(int k) {
        return rank[k] ;
    }
    void reset() {
        set_size=n ; for(int i = 1 ; i<=n ;i++) parent[i]=i, rank[i]=1;
    }
    int size() {return set_size;} 
    void printf() {for(int i=1;i<=n;i++) cout<<i<<" --> "<<parent[i]<<endl;}
};

void solve()
{
    int n ;
    cin>>n;
    string s,s1  ;
    cin>>s>>s1;
    ll ans = 0 ;
    int vis[n];
    memset(vis,0,sizeof(vis)) ;
    for(int i = 0 ; i < n ; i++ ) {
        if(s[i]=='1' && s1[i]=='1') {
            continue ; 
        }
        else if(s[i]!=s1[i]) {
            ans+=2;
        }
        else{
            if(i-1>=0 && (s[i-1]=='1' && s1[i-1]=='1')) {
                ans+=2;
            }
            else ans++;
        }
    } 
    int i = n-1 ;
    while(i>=0 && s[i]=='1' && s1[i]=='1') {
        i--;
    }
    if(i!=n-1){
        if(i-1>=0 && s[i]=='0' && s1[i]=='0' && s[i-1]!='1' && s1[i-1]!='1') ans++ ; 
        else if(i==0) ans ++;
    } 
    
    cout<<ans<<endl;
}

signed main()
{
	FAST
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif
    ll _t=1;
    cin>>_t;
    //string s; getline(cin,s);
    for(ll i =1 ; i <=_t ; i++ )
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
   
}