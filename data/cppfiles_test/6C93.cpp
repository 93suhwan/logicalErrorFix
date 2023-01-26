#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
const long long mod = 1e9 + 7;
vector<long long> adj[N];
long long dis[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long TC = 1;
  while (TC--) {
    long long n, m, k, q;
    cin >> n >> m;
    vector<long long> adj[N];
    map<long long, set<long long>> mp;
    set<long long> st;
    for (long long i = 0; i < m; ++i) {
      long long x, y;
      cin >> x >> y;
      if (x < y) {
        mp[x].insert(y);
        st.insert(x);
      } else {
        mp[y].insert(x);
        st.insert(y);
      }
    }
    cin >> q;
    while (q--) {
      long long xx;
      cin >> xx;
      if (xx == 3) {
        cout << n - st.size() << endl;
      } else if (xx == 1) {
        long long x, y;
        cin >> x >> y;
        if (x < y) {
          mp[x].insert(y);
          st.insert(x);
        } else {
          st.insert(y);
          mp[y].insert(x);
        }
      } else {
        long long x, y;
        cin >> x >> y;
        if (x < y) {
          mp[x].erase(y);
          if (mp[x].size() == 0) {
            mp.erase(x);
            st.erase(x);
          } else {
            long long ele = *(mp[x]).rbegin();
            if (ele < x) st.erase(x);
          }
        } else {
          mp[y].erase(x);
          if (mp[y].size() == 0) {
            mp.erase(y);
            st.erase(y);
          } else {
            long long ele = *(mp[y]).rbegin();
            if (ele < y) st.erase(y);
          }
        }
      }
    }
  }
}
