#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> v, r;
long long find_set(long long a) {
  if (v[a] == -1) return a;
  return v[a] = find_set(v[a]);
}
bool union_set(long long a, long long b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (r[a] > r[b]) swap(a, b);
    r[b] += r[a];
    v[a] = b;
    return 1;
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    v.clear();
    r.clear();
    v.resize(n + 1, -1);
    r.resize(n + 1, 1);
    vector<pair<long long, long long>> edges;
    for (long long i = 0; i < m; i++) {
      long long a;
      cin >> a;
      long long b;
      cin >> b;
      long long c;
      cin >> c;
      if (union_set(a, c)) edges.push_back({a, c});
    }
    vector<long long> a;
    for (long long i = 1; i <= n; i++) {
      find_set(i);
      if (v[i] == -1) a.push_back(i);
    }
    for (long long i = 1; i < a.size(); i++) edges.push_back({a[i - 1], a[i]});
    for (auto x : edges) cout << x.first << ' ' << x.second << endl;
  }
  return 0;
}
