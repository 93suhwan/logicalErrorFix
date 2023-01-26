#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// templates //
template <class T> ostream &operator << (ostream &os, const vector<T> &p) { os << "["; for (auto&it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream &operator << (ostream &os, const pair<S, T> &p) { return os << "(" << p.first << "," << p.second << ")";}
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#ifndef ONLINE_JUDGE
#define deb(...) dbs(#__VA_ARGS__,__VA_ARGS__)
template <class T> void dbs(string str, T t) { cerr << str << ":" << t << "\n";}
template<class T, class...S> void dbs(string str, T t, S... s) { int idx = str.find(','); cerr << str.substr(0, idx) << ":" << t << ","; dbs(str.substr(idx + 1), s...);}
#else
#define deb(...){}
#endif
#define int                  long long int
#define w(t)                 int t; cin>>t; while(t--)
#define mod                  1000000007
#define pb                   push_back
#define F                    first
#define S                    second
#define all(v)               v.begin(),v.end()

template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }

void stugs(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    a%=2;b%=2;c%=2;
    b*=2;c*=3;
    cout<<(min({abs(b+c-a),abs(c+a-b),abs(a+b-c)}))<<endl;   
}

int32_t main(){
        
    stugs();
    w(t)
    solve();
    return 0;
}