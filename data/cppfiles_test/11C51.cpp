#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const int INF = 1e9 + 10;
template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;
int n;
vector<int> a;
vector<pair<int, int>> pos;
void Solve() {
  scanf("%d", &n);
  a.resize(n + 1);
  pos.resize(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pos[i - 1] = {a[i], i};
  }
  sort((pos).begin(), (pos).end(),
       [&](const pair<int, int>& x, const pair<int, int>& y) -> bool {
         if (x.first == y.first) return x.second > y.second;
         return x.first < y.first;
       });
  int ans = 0;
  map<int, int> f;
  f[0] = 0;
  for (auto [i, p] : pos) {
    int d = p - i;
    if (d < 0) continue;
    int w;
    {
      auto it = prev(f.upper_bound(d));
      w = it->second + 1;
      42;
    }
    ans = max(ans, w);
    f[d] = w;
    auto it = f.upper_bound(d);
    while (it != f.end() && it->second <= w) it = f.erase(it);
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
  return 0;
}
