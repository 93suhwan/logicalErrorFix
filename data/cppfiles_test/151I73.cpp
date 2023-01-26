#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = (int)5e5+500;

int n;
int a[maxn];
int nxt[maxn];
map<int, vi> mp;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    int cur=0;
    while(q--) {
        int t;
        cin >> t;

        if(t==1) {
            int x;
            cin >> x;

            a[++cur] = x;
            mp[x].emplace_back(cur);
        } else {
            int x,y;
            cin >> x >> y;
            if(mp[x].empty()) continue;
            int rep = mp[x].back();
            for(int idx: mp[x]) {
                nxt[idx] = rep;
            }
            a[rep] = y;
            mp[y].emplace_back(rep);

            mp[x].clear();
        }
    }

    for(int i = cur; i >= 1; i--) {
        if(nxt[i]) a[i] = a[nxt[i]];
    }

    for(int i = 1; i <= cur; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/*

dsu thing

*/