#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i) cin >> va[i];
    for (int i = 0; i < n; ++i) cin >> vb[i];
    map<int, int> atob, btoa;
    for (int i = 0; i < n; ++i) {
      atob[va[i]] = vb[i];
      btoa[vb[i]] = va[i];
    }
    set<int> sa, sb;
    for (int i = 0; i < n; ++i) {
      sa.insert(va[i]);
      sb.insert(vb[i]);
    }
    auto it = sa.end();
    --it;
    int mxa = *it;
    it = sb.end();
    --it;
    int mxb = *it;
    int mxba = btoa[mxb];
    queue<int> q;
    q.push(mxa);
    if (mxba != mxa) q.push(mxba);
    sa.erase(mxba);
    sb.erase(mxb);
    sa.erase(mxa);
    sb.erase(atob[mxa]);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      int b = atob[a];
      it = sa.upper_bound(a);
      set<int> e;
      while (it != sa.end()) {
        e.insert(*it);
        ++it;
      }
      it = sb.upper_bound(b);
      while (it != sb.end()) {
        e.insert(btoa[*it]);
        ++it;
      }
      for (int x : e) {
        q.push(x);
        sa.erase(x);
        sb.erase(atob[x]);
      }
    }
    for (int i = 0; i < n; ++i) cout << !sa.count(va[i]);
    cout << '\n';
  }
}
