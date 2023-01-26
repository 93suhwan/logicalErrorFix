#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b == 0 ? a : gcd(b, a % b));
}
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gli() {
  long long a;
  scanf("%I64d", &a);
  return a;
}
int a[200000], b[200000], m[200000];
void solve() {
  int n = gi();
  for (int i = 0; i < n; i++) {
    a[i] = gi();
    b[i] = gi();
    m[i] = gi();
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) mp[a[i] + b[i] - m[i]].push_back(i);
  int ans = 0;
  for (auto it : mp) {
    vector<pair<int, pair<int, int>>> r;
    for (int i : it.second) {
      r.push_back({a[i] - min(m[i], a[i]), {0, i}});
      r.push_back({a[i] - max(0, m[i] - b[i]), {1, i}});
    }
    sort(r.begin(), r.end());
    vector<int> s;
    for (pair<int, pair<int, int>> &p : r) {
      if (p.second.first == 0)
        s.push_back(p.second.second);
      else if (b[p.second.second] >= 0) {
        ans++;
        for (int i : s) {
          a[i] -= p.first;
          b[i] = -1;
        }
        s.clear();
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) printf("%d %d\n", a[i], m[i] - a[i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = gi();
  while (t--) solve();
  return 0;
}
