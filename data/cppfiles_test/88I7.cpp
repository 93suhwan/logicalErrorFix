#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;


#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007
#define float double
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define sz(x) ((int)(x).size())
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define nline "\n"
#define debug(x) cout << #x <<" "; print(x); cout << endl;
 
 
void print(ll t) {cout << t;}
void print(int t) {cout << t;}
void print(string t) {cout << t;}
void print(char t) {cout << t;}
void print(lld t) {cout << t;}
void print(double t) {cout << t;}
void print(ull t) {cout << t;}
void printn(ll t) {cout << t<<nline;}
void printn(int t) {cout << t<<nline;}
void printn(string t) {cout << t<<nline;}
void printn(char t) {cout << t<<nline;}
void printn(lld t) {cout << t<<nline;}
void printn(double t) {cout << t<<nline;}
void printn(ull t) {cout << t<<nline;}
 
template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T, class V> void print(map <T, V> v);
template <class T> void print(multiset <T> v);
template <class T, class V> void print(pair <T, V> p) {cout << "{"; print(p.ff); cout << ","; print(p.ss); cout << "}";}
template <class T> void print(vector <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]";}
template <class T> void print(set <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]";}
template <class T> void print(multiset <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]";}
template <class T, class V> void print(map <T, V> v) {cout << "[ "; for (auto i : v) {print(i); cout << " ";} cout << "]";}
 
 bool comp(pair<ll,ll>a,pair<ll,ll>b)
 {

     return a.second<b.second;
 }
 bool comp1(pair<ll,ll>a,pair<ll,ll>b)
 {
if(a.first!=b.first)
return a.first<b.first;
     return a.second>b.second;
 }
 
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>v(n*m);
    for (int i = 0; i < n*m; i++)
    {
        cin>>v[i].first;
        v[i].second=i;
    }
    ll  arr[n+1][m+1];
    ll ans=0;
    memset(arr,0,sizeof(arr));
    sort(all(v),comp1);
    for (int i = 0; i < n*m; i++)
    {
        v[i].first=i+1;
    }
    sort(all(v),comp);
    for (int i = 0; i < n*m; i++)
    {
        int x=v[i].first;
        int j=m,ct=1;
        while (j<x)
        {
            ct++;
            j+=m;
        }
        int k=j,cnt=m;
        while (k!=x)
        {
            k--;
            cnt--;
        }
        arr[ct][cnt]=1;
        for (int f = cnt-1 ; f >= 1; f--)
        {
            if(arr[ct][f])
            ans++;
        }
    }
    cout<<ans<<endl;
    
     
}
 
 
 
int main(){
              fast
              int t=1;
              cin>>t;
              while(t--)
              {
                  solve();
              }
return 0;
}