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

void update(int node) {
    for(auto x : used[node]) {
        unused[node].insert(x);
        st.erase(x);
    }
    rez.erase({minim[node], node});
    used[node].clear();
    minim[node] = 0;
    int cnt = 0;
    for(auto x : unused[node]) {
        used[node].insert(x);
        minim[node] += 1LL * x.first;
        cnt++;
        if(cnt == 3)
            break;
    }
    if(cnt != 3)
        minim[node] = INF;
    rez.insert({minim[node], node});
    for(auto x : used[node]) {
        unused[node].erase(x);
        st.insert(x);
    }
}

ll best(ll idx){
    ll minim = INF;
    int stt = edges[idx].x;
    int dr = edges[idx].y;
    for(auto x : st){
        int l = edges[x.second].x;
        int r = edges[x.second].y;
        if(l != stt && l != dr && r != stt && r != dr){
            minim = min(minim, 1LL * x.first);
            break;
        }
    }
    return (1LL * edges[idx].z + minim);
}

ll sol(){
    ll minim = rez.begin()->first;
    pii x = *st.begin();
    minim = min(minim, best(x.second));
    int st = edges[x.second].x;
    int dr = edges[x.second].y;
    for(auto y : used[st]){
        minim = min(minim, best(y.second));
    }
    for(auto y : used[dr]){
        minim = min(minim, best(y.second));
    }
    return minim;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x > y)
            swap(x, y);
        mp[ {x, y}] = i;
        edges[i] = {x, y, z};
        unused[x].insert({z, i});
        unused[y].insert({z, i});
        update(x);
        update(y);
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
            unused[x].erase({edges[idx].z, idx});
            unused[y].erase({edges[idx].z, idx});
            update(x);
            update(y);
        } else {
            int x, y, z;
            cin >> x >> y >> z;
            if(x > y)
                swap(x, y);
            mp[{x, y}] = ++m;
            edges[m] = {x, y, z};
            unused[x].insert({z, m});
            unused[y].insert({z, m});
            update(x);
            update(y);
        }
        cout << sol() << "\n";
    }
    return 0;
}
