#include <bits/stdc++.h>
const int MAX = 5e5 + 10;
using namespace std;
int T, N, K;
long long teto(int x, int y) { return (x + y - 1) / y; }
void solve() {
  scanf("%d %d", &N, &K);
  vector<long long> arr(N);
  for (auto &e : arr) scanf("%lld", &e);
  sort(arr.begin(), arr.end());
  vector<long long> a[2];
  for (auto e : arr) a[e >= 0].push_back(e);
  reverse(a[0].begin(), a[0].end());
  long long ans = 0;
  if (!a[0].empty()) ans += (-a[0][0]) * teto((int)(a[0].size()), K);
  if (!a[1].empty()) ans += a[1][0] * teto((int)(a[1].size()), K);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < (int)(a[i].size()); j++)
      ans += abs(a[i][j + 1] - a[i][j]) * teto((int)(a[i].size()) - j - 1, K);
  ans *= 2LL;
  if (a[0].empty())
    ans -= a[1].back();
  else if (a[1].empty())
    ans += a[0].back();
  else
    ans -= max(abs(a[0].back()), a[1].back());
  printf("%lld\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
}
