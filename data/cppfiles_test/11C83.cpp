#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const int maxN = 1e6 + 1;
const int mod = 1e9 + 7;
const ll oo = 1e9;
int n, a[maxN];
pair<int, int> d[maxN];
int f[maxN], e[maxN];
inline void FastInput() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
void ReadInput() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    e[i] = oo;
    d[i] = {a[i], i - a[i]};
  }
  sort(d + 1, d + n + 1, [](pair<int, int> p, pair<int, int> q) {
    return (p.first < q.first || (p.first == q.first && p.second > q.second));
  });
}
void Solve() {
  for (int i = 1; i <= n; i++) {
    if (d[i].second < 0) continue;
    f[i] = upper_bound(e + 1, e + n + 1, d[i].second) - e;
    e[f[i]] = d[i].second;
  }
  cout << *max_element(f + 1, f + n + 1);
}
int main() {
  FastInput();
  ReadInput();
  Solve();
}
