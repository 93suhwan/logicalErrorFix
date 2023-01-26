#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define debug(x) cerr << #x << " " << x << "\n"
#define debugs(x) cerr << #x << " " << x << " "

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair <ll, ll> pii;
typedef pair <long double, pii> muchie;

const ll NMAX = 100001;
const ll VMAX = 1000001;
const ll INF = (1LL << 59);
const ll MOD = 998244353;
const ll BLOCK = 318;
const ll base = 31;
const ll nr_of_bits = 21;

set <pii> used[NMAX];
set <pii> unused[NMAX];

struct ura {
    ll x, y, z;
};

ura edges[NMAX * 2];
int n, m;

set <pii> st;
set <pii> rez;
map <pii, int> mp;

ll minim[NMAX];

ll best(ll idx) {
    ll minim = INF;
    int stt = edges[idx].x;
    int dr = edges[idx].y;
    for(auto x : st) {
        int l = edges[x.second].x;
        int r = edges[x.second].y;
        if(l != stt && l != dr && r != stt && r != dr) {
            minim = min(minim, x.first);
            break;
        }
    }
    return (edges[idx].z + minim);
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

void update(ll node) {
    rez.erase({minim[node], node});
    if(used[node].size() != 3) {
        minim[node] = INF;
        rez.insert({minim[node], node});
        return;
    }
    minim[node] = 0;
    for(auto x : used[node]) {
        minim[node] += x.first;
    }
    rez.insert({minim[node], node});

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        minim[i] = 0;
    for(i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x > y)
            swap(x, y);
        mp[ {x, y}] = i;
        edges[i] = {x, y, z};
        used[x].insert({z, i});
        used[y].insert({z, i});
        st.insert({z, i});
        pii it = *used[x].rbegin();
        pii it1 = *used[y].rbegin();
        if(used[x].size() > 3) {
            used[x].erase(it);
            unused[x].insert(it);
            st.erase(it);
        }
        if(used[y].size() > 3) {
            used[y].erase(it1);
            unused[y].insert(it1);
            st.erase(it1);
        }
        update(x);
        update(y);
    }
    for(i = 1; i <= n; i++) {
        if(used[i].size() < 3)
            minim[i] = INF;
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
            used[x].erase({edges[idx].z, idx}); /// poate e in used
            used[y].erase({edges[idx].z, idx});
            st.erase({edges[idx].z, idx});
            update(x);
            update(y);
        } else {
            int x, y, z;
            cin >> x >> y >> z;
            if(x > y)
                swap(x, y);
            mp[ {x, y}] = ++m;
            edges[m] = {x, y, z};
            used[x].insert({z, m});
            used[y].insert({z, m});
            st.insert({z, m});
            pii it = *used[x].rbegin();
            pii it1 = *used[y].rbegin();
            if(used[x].size() > 3) {
                used[x].erase(it);
                unused[x].insert(it);
                st.erase(it);
            }
            if(used[y].size() > 3) {
                used[y].erase(it1);
                unused[y].insert(it1);
                st.erase(it1);
            }
            update(x);
            update(y);
        }
        cout << sol() << "\n";
    }
    return 0;
}
