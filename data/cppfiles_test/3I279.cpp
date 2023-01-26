#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef long double ld;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll> >, rb_tree_tag, tree_order_statistics_node_update> ordered_pair_set;
#define forder(x) find_by_order(x)
#define okey(x) order_of_key(x)

typedef vector<ll> vi;
typedef vector<pair<ll,ll> > vpii;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
 
#define cases() int test_case; cin >> test_case; while(test_case--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define input(v) for(auto &invec:v) cin>>invec
#define print(v) for(auto prvec:v) cout<<prvec<<" "; cout<<'\n'
#define uniq(v) auto uniqit=unique(all(v)); v.resize(distance(v.begin(), uniqit));

const ll MOD = 1e9+7;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll INF = 1e18;

#ifndef ONLINE_JUDGE
    #define dbg(...) debg(#__VA_ARGS__, __VA_ARGS__)
    template<typename ...Args>
    void debg(string vars, Args&&... values) {
        cerr<<vars<<" = ";
        string x = "";
        (..., (cerr<<x<<values,x=", "));
        cerr<<'\n';
    }
#else
    #define dbg(...)
#endif

ll power(ll a,ll b) {ll p=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)p=p*a%MOD;a=a*a%MOD;}return p;}

const auto start_time = chrono::high_resolution_clock::now();

void TIME() {
    #ifndef ONLINE_JUDGE
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end_time - start_time;
        cerr << "Time Taken: " << (diff.count())*1000 << " ms\n";
    #endif
}

void solve(){
    string s;
    cin>>s;
    if(s.length()==1 && (s[0]!='_' && s[0]!='X')){
        if(s[0]=='0'){
            cout<<1<<'\n';
            return;
        }
        cout<<0<<'\n';
        return;
    }
    if(s.length()==1 && (s[0]=='_' || s[0]=='X')){
        cout<<1<<'\n';
        return;
    }
    if(s.length()==2 && (s[0]=='X' && s[1]=='X')){
        cout<<0<<'\n';
        return;
    }
    if(s[0]=='0'){
        cout<<0<<'\n';
        return;
    }
    string a="";
    int n=s.length();
    a+=s[n-2];
    a+=s[n-1];
    if(a[0]=='X' && a[1]=='X' && s[0]=='X'){
        cout<<0<<'\n';
        return;
    }
    ll cnt=1;
    if(a[0]=='X'&&a[1]=='X'){
        ll p=count(all(s), '_');
        if(s[0]=='_'){
            cnt=powl(10LL, (p-1));
            cnt*=9;
        }else{
            cnt=powl(10LL, p);
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[0]=='_' && a[1]=='_'){
        if(s[0]=='X'){
            cnt=9;
        }else{
            if(count(all(s), 'X')){
                cnt=10;
            }
        }
        cnt*=4;
        ll p=count(all(s), '_');
        p-=2;
        ll pp=powl(10, p);
        cnt*=pp;
        if(s[0]=='_'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[0]=='_' && a[1]=='X'){
        if(s[0]=='X'){
            cnt=2;
        }else{
            cnt=4;
        }
        ll p=count(all(s), '_');
        p-=1;
        ll pp=powl(10, p);
        cnt*=pp;
        if(s[0]=='_'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[0]=='X' && a[1]=='_'){
        if(s[0]=='X'){
            cnt=3;
        }else{
            cnt=4;
        }
        ll p=count(all(s), '_');
        p-=1;
        ll pp=powl(10, p);
        cnt*=pp;
        if(s[0]=='_'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if((a[0]!='X' && a[0]!='_') && a[0]!='2' && a[0]!='0' && a[0]!='5' && a[0]!='7'){
        cout<<0<<'\n';
        return;
    }
    if((a[1]!='X' && a[1]!='_') && a[1]!='5' && a[1]!='0'){
        cout<<0<<'\n';
        return;
    }
    if(a[0]=='2' && a[1]=='5'){
        ll p=count(all(s), '_');
        ll pp=powl(10, p);
        cnt*=pp;
        if(count(all(s), 'X')){
            cnt*=10;
        }
        if(s[0]=='_' || s[0]=='X'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[0]=='7' && a[1]=='5'){
        ll p=count(all(s), '_');
        ll pp=powl(10, p);
        cnt*=pp;
        if(count(all(s), 'X')){
            cnt*=10;
        }
        if(s[0]=='_' || s[0]=='X'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[0]=='5' && a[1]=='0'){
        ll p=count(all(s), '_');
        ll pp=powl(10, p);
        cnt*=pp;
        if(count(all(s), 'X')){
            cnt*=10;
        }
        if(s[0]=='_' || s[0]=='X'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[0]=='0' && a[1]=='0'){
        ll p=count(all(s), '_');
        ll pp=powl(10, p);
        cnt*=pp;
        if(count(all(s), 'X')){
            cnt*=10;
        }
        if(s[0]=='_' || s[0]=='X'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[1]=='5' && a[0]=='_'){
        cnt=2;
        ll p=count(all(s), '_');
        p--;
        ll pp=powl(10, p);
        cnt*=pp;
        if(count(all(s), 'X')){
            cnt*=10;
        }
        if(s[0]=='_' || s[0]=='X'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[1]=='0' && a[0]=='_'){
        cnt=2;
        ll p=count(all(s), '_');
        p--;
        ll pp=powl(10, p);
        cnt*=pp;
        if(count(all(s), 'X')){
            cnt*=10;
        }
        if(s[0]=='_' || s[0]=='X'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[1]=='5' && a[0]=='X'){
        cnt=2;
        ll p=count(all(s), '_');
        ll pp=powl(10, p);
        cnt*=pp;
        if(s[0]=='_'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[1]=='0' && a[0]=='X'){
        if(s[0]=='X'){
            cnt=1;
        }else{
            cnt=2;
        }
        ll p=count(all(s), '_');
        ll pp=powl(10, p);
        cnt*=pp;
        if(s[0]=='_'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[1]=='5' && a[0]=='_'){
        cnt=2;
        ll p=count(all(s), '_');
        p--;
        ll pp=powl(10, p);
        cnt*=pp;
        if(count(all(s), 'X')){
            cnt*=10;
        }
        if(s[0]=='_' || s[0]=='X'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[1]=='_' && (a[0]=='0' || a[0]=='5'||a[0]=='2'||a[0]=='7')){
        ll p=count(all(s), '_');
        p--;
        ll pp=powl(10, p);
        cnt*=pp;
        if(count(all(s), 'X')){
            cnt*=10;
        }
        if(s[0]=='_' || s[0]=='X'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[1]=='X' && (a[0]=='5'||a[0]=='0')){
        if(s[0]=='X'){
            cout<<0<<'\n';
            return;
        }
        ll p=count(all(s), '_');
        ll pp=powl(10, p);
        cnt*=pp;
        if(s[0]=='_'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[1]=='X' && (a[0]=='2'||a[0]=='7')){
        ll p=count(all(s), '_');
        ll pp=powl(10, p);
        cnt*=pp;
        if(s[0]=='_'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    if(a[0]!='X'&&a[1]!='X'&&a[0]!='_'&&a[1]!='_'){
        int xx=stoi(a);
        if(xx%25){
            cout<<0<<'\n';
            return;
        }
        ll p=count(all(s), '_');
        ll pp=powl(10, p);
        cnt*=pp;
        if(count(all(s), 'X')){
            cnt*=10;
        }
        if(s[0]=='_' || s[0]=='X'){
            cnt/=10;
            cnt*=9;
        }
        cout<<cnt<<'\n';
        return;
    }
    cout<<cnt<<'\n';
}
	
int main(){
    fastio

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
    // cases()
    solve();

    TIME();
	return 0; 
}