#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define debug(x) cerr << #x << " " << x << "\n"
#define debugs(x) cerr << #x << " " << x << " "

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair <ll, ll> pii;
typedef pair <int, int> piii;
typedef pair <long double, pii> muchie;

const ll NMAX = 100001;
const ll VMAX = 1000001;
const ll INF = (1LL << 59);
const ll MOD = 998244353;
const ll BLOCK = 318;
const ll base = 31;
const ll nr_of_bits = 21;

set <piii> used[NMAX];
set <piii> unused[NMAX];

struct ura {
    int x, y, z;
};

ura edges[NMAX * 2];
int n, m;

set <piii> st;
set <pii> rez;
map <piii, int> mp;

ll minim[NMAX];
ll last[NMAX];

void update(int node){
    rez.erase({last[node], node});
    last[node] = minim[node];
    if(used[node].size() != 3)
        last[node] = INF;
    rez.insert({last[node], node});
}

void baga(int node, pii edge) {
    if(used[node].size() < 3) {
        used[node].insert(edge);
        st.insert(edge);
        minim[node] += edge.first;
        update(node);
        return;
    }
    pii ultim = *used[node].rbegin();
    if(ultim.first <= edge.first){
        unused[node].insert(edge);
        return;
    }
    minim[node] += (edge.first - ultim.first);
    update(node);
    used[node].erase(ultim);
    st.erase(ultim);
    unused[node].insert(ultim);
    used[node].insert(edge);
    st.insert(edge);
}

void sterge(int node, pii edge){
    if(unused[node].find(edge) != unused[node].end()){
        unused[node].erase(edge);
        return;
    }
    used[node].erase(edge);
    st.erase(edge);
    minim[node] -= edge.first;
    if(unused[node].size()){
        pii primul = *unused[node].begin();
        unused[node].erase(primul);
        used[node].insert(primul);
        st.insert(primul);
        minim[node] += primul.first;
    }
    update(node);
}

ll best(ll idx) {
    int stt = edges[idx].x;
    int dr = edges[idx].y;
    int cc = 0;
    for(auto x : st) {
        int l = edges[x.second].x;
        int r = edges[x.second].y;
        if(l != stt && l != dr && r != stt && r != dr) {
            return (1LL * edges[idx].z + 1LL * x.first);
        }
        cc++;
        if(cc > 13)
            exit(0);
    }
}

ll sol() {
    ll minim = rez.begin()->first;
    pii x = *st.begin();
    minim = min(minim, best(x.second));
    int st = edges[x.second].x;
    int dr = edges[x.second].y;
    for(auto y : used[st]) {
        minim = min(minim, best(y.second));
    }
    for(auto y : used[dr]) {
        minim = min(minim, best(y.second));
    }
    return minim;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i;
    cin >> n >> m;
    rez.insert({INF, 0});
    for(i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x > y)
            swap(x, y);
        mp[ {x, y}] = i;
        edges[i] = {x, y, z};
        baga(x, {z, i});
        baga(y, {z, i});
    }
    int q;
    cin >> q;
    cout << sol() << "\n";
    while(q--) {
        int c;
        cin >> c;
        if(c == 0) {
            int x, y;
            cin >> x >> y;
            if(x > y)
                swap(x, y);
            int idx = mp[ {x, y}];
            sterge(x, {edges[idx].z, idx});
            sterge(y, {edges[idx].z, idx});
        } else {
            int x, y, z;
            cin >> x >> y >> z;
            if(x > y)
                swap(x, y);
            mp[ {x, y}] = ++m;
            edges[m] = {x, y, z};
            baga(x, {z, m});
            baga(y, {z, m});
        }
        cout << sol() << "\n";
    }
    return 0;
}