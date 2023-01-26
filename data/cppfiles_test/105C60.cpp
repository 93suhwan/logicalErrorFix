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
int a[200000], b[200000], m[200000], res[200000], vis[200000];
void solve() {
  int n = gi();
  for (int i = 0; i < n; i++) {
    vis[i] = 0;
    a[i] = gi();
    b[i] = gi();
    m[i] = gi();
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int x = a[i] + b[i] - m[i];
    mp[x].push_back(i);
  }
  int ans = 0;
  for (auto it : mp) {
    vector<pair<int, pair<int, int>>> r;
    for (int i : it.second) {
      int mxa = a[i] - max(0, m[i] - b[i]);
      int mna = a[i] - min(m[i], a[i]);
      r.push_back({mna, {0, i}});
      r.push_back({mxa, {1, i}});
    }
    sort(r.begin(), r.end());
    stack<int> s;
    for (pair<int, pair<int, int>> &p : r) {
      if (p.second.first == 0)
        s.push(p.second.second);
      else if (!vis[p.second.second]) {
        ans++;
        while (!s.empty()) {
          int i = s.top();
          s.pop();
          vis[i] = 1;
          res[i] = a[i] - p.first;
        }
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) printf("%d %d\n", res[i], m[i] - res[i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = gi();
  while (t--) solve();
  return 0;
}
