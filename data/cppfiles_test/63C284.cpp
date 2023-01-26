#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
struct DJS {
  int p[100002];
  long long sz[100002];
  void init(int n) {
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      sz[i] = 1;
    }
  }
  int find(int x) {
    if (x == p[x]) return x;
    p[x] = find(p[x]);
    return p[x];
  }
  void Union(int a, int b) {
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = p[a];
    sz[a] += sz[b];
  }
  int pieces(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i == find(i)) ans++;
    }
    return ans;
  }
  long long ask_size(int a) { return sz[find(a)]; }
};
DJS djs1, djs2;
vector<pair<long long, long long> > ans;
signed main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  djs1.init(n);
  djs2.init(n);
  for (int i = 0; i < m1; i++) {
    int a, b;
    cin >> a >> b;
    djs1.Union(djs1.find(a), djs1.find(b));
  }
  for (int i = 0; i < m2; i++) {
    int a, b;
    cin >> a >> b;
    djs2.Union(djs2.find(a), djs2.find(b));
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if ((djs1.find(i) != djs1.find(j)) && (djs2.find(i) != djs2.find(j))) {
        djs1.Union(djs1.find(i), djs1.find(j));
        djs2.Union(djs2.find(i), djs2.find(j));
        ans.push_back(make_pair(i, j));
      }
    }
  }
  cout << ans.size() << "\n";
  for (pair<long long, long long> p : ans)
    cout << p.first << " " << p.second << "\n";
}
