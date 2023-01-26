#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <bits/stdc++.h>
#define ll long long
#define pb pop_back
#define eb emplace_back
#define pii pair<int,int>
#define pil pair<ll,ll>
#define mp make_pair
#define mod 1000000007
#define Max 100000000000000000
#define N 200000
#define fi first
#define se second
#define fo(i,k,n) for(int i=k;i<n;i++)
#define ifo(i,k,n) for(int i=n-1;i>=k;i--)
#define deb(x) cout<<#x<<"="<<x<<"\n";
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<"\n"
#define trav(a,x) for (auto& a : x)
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
using namespace __gnu_pbds;
using namespace std;

typedef tree <
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll expo(ll a, ll b) {
    if (b == 0) {return 1;}
    ll z = expo(a, b / 2); z *= z; z %= mod; if (b % 2 != 0) {z *= a; z %= mod;}
    return z;
}
ll gcd(ll a, ll b) {
    if (a == 0)return b;
    return gcd(b % a, a);
}
vector<int>parent, tme;
vector<pair<pii, int>>v;
int root(int x) {
    if (parent[x] == x) {
        return x;
    }
    return (parent[x] = root(parent[x]));
}
void unio(int x, int y) {
    int r1 = root(x);
    int r2 = root(y);
    if (r1 == r2)return;
    parent[r1] = r2;
    tme[r2] = min(tme[r2], tme[r1]);
}
void test() {
    int n, k;
    cin >> n >> k;
    parent.clear();
    v.clear();
    tme.clear();
    parent.resize(n + 1);
    tme.resize(n + 1, mod);
    int x, y, t;
    map<pii, int>Mp;
    map<int, vector<int>>Mp1, Mp2;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> t;
        v.eb(mp(mp(x, y), t));
        Mp[mp(x, y)] = i;
        tme[i] = t;
        Mp1[y].eb(x);
        Mp2[x].eb(y);
    }
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    trav(z, Mp1) {
        //  deb(z.fi);
        vector<int>v1 = z.se;
        for (int i = 0; i < v1.size(); i++) {
            if (!(i == 0 || v1[i] - v1[i - 1] > k)) {
                unio(Mp[mp(v1[i - 1], z.fi)], Mp[mp(v1[i], z.fi)]);
            }
            int z1 = v1[i];
            //for z1--> Mp2[z1] me z.fi->z.fi-k tak me nearest point ko tch karenge
            auto it = upper_bound(Mp2[z1].begin(), Mp2[z1].end(), z.fi);
            if (it == Mp2[z1].end()) {
                continue;
            }
            else {
                y = *it;
                if ((z.fi + k) >= y) {
                    unio(Mp[mp(z1, z.fi)], Mp[mp(z1, y)]);
                }
            }

        }
    }
    t = -1;
    vector<int>times;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            times.eb(tme[i]);
            //  deb2(i, tme[i]);
        }
    }
    sort(all(times), greater<int>());
    for (int i = 0; i < times.size(); i++) {
        //  deb2(i, times[i]);
        if (times[i] <= t) {
            continue;
        }
        else {
            t++;
        }
    }
    if (t == -1) {
        cout << 0 << "\n";
        return;
    }
    cout << t << "\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        test();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
//limiting conditions should be placed in order for recursive solutions