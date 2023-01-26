#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
//#define endl '\n'
#define F first
#define S second
#define rs resize

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ppi = pair<int, pair<int, int>>;
using ppl = pair<ll, pair<ll, ll>>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
using vvpi = vector<vpi>;
using vpl = vector<pl>;
using vvl = vector<vl>;
using vvpl = vector<vpl>;
using vppl = vector<ppl>;
using vppi = vector<ppi>;
using ull=unsigned long long;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;



int MOD =  998244353;
mt19937 rnd(time(0));

const int N=2e5+10;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}




/*
const int LIM = 200005;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/
/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/
void solve()
{
    ll x, y;
    cin>>x>>y;
    if(x>y){
        cout<<x+y<<endl;
    }
    else if(x==y){
        cout<<x<<endl;
    }
    else if(x<y){
        if(x%4==0){
            cout<<(x+y)/2<<endl;
        }
        else{
            ll tp=y/x;
            cout<<tp*x+(y%x)/2<<endl;
        }
        /*for(int i=0;i<x;i++){
            for(int j=0;j<1e4;j++){
                ll n=x*j+i;
                if(n!=0){
                    if(n%x==y%n){
                        cout<<n<<"!!!"<<endl;
                    }
                }
            }
        }*/
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while (t--)
        solve();

}
/*

*/
