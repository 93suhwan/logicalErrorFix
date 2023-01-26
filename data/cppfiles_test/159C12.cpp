#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 13;
using li = unsigned long long;
int pr[N];
li hs[N], f[N];
unordered_map<li, int> rf;
int main() {
  int n;
  scanf("%d", &n);
  mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
  iota(pr, pr + N, 0);
  for (int i = 2; i <= n; ++i)
    if (pr[i] == i) {
      for (int j = i; j <= n; j += i) pr[j] = min(pr[j], i);
      hs[i] = rnd();
    }
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i - 1];
    int x = i;
    while (x != 1) {
      f[i] ^= hs[pr[x]];
      x /= pr[x];
    }
    rf[f[i]] = i;
  }
  auto solve = [&](int n) -> vector<int> {
    li fp = 0;
    for (int i = 2; i <= n; ++i) fp ^= f[i];
    if (fp == 0) return {};
    if (rf.count(fp)) return {rf[fp]};
    for (int i = 2; i <= n; ++i) {
      li x = f[i] ^ fp;
      if (rf.count(x) && rf[x] != i) return {rf[x], i};
    }
    return {2, n / 2, n};
  };
  auto ans = solve(n);
  printf("%d\n", n - (int)ans.size());
  for (int i = 1; i <= n; ++i)
    if (find(ans.begin(), ans.end(), i) == ans.end()) printf("%d ", i);
  puts("");
}
