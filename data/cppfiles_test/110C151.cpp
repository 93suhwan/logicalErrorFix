#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> to[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) to[i].clear();
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < x; j++) {
        int k;
        cin >> k;
        k--;
        to[k].push_back(i);
        in[i]++;
      }
    }
    queue<int> q;
    vector<int> ts(n);
    for (int i = 0; i < n; i++) {
      if (in[i] == 0) {
        q.push(i);
        ts[i] = 1;
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : to[u]) {
        in[v]--;
        if (v < u)
          ts[v] = max(ts[v], ts[u] + 1);
        else
          ts[v] = max(ts[v], ts[u]);
        if (!in[v]) q.push(v);
      }
    }
    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (in[i]) {
        ok = 0;
        break;
      }
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    cout << *max_element(ts.begin(), ts.end()) << '\n';
  }
}
