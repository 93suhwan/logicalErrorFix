#include <bits/stdc++.h>
const int N = 1000005;
const int M = 10000;
int n, t;
inline void read(int &x) {
  register char ch = 0;
  register bool w = 0;
  for (x = 0; !std::isdigit(ch); w |= ch == '-', ch = getchar())
    ;
  for (; std::isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  (w) && (x = -x);
  return;
}
std::vector<int> reach[M];
int min0[M], vis[M], res[M];
void solve() {
  read(n);
  static int ai[N];
  for (int i = 1; i <= n; ++i) read(ai[i]);
  for (int i = 0; i < 8192; ++i) reach[i].push_back(0), min0[i] = 8192;
  for (int i = 1; i <= n; ++i) {
    if (vis[ai[i]]) continue;
    vis[ai[i]] = 1;
    for (auto v : reach[ai[i]]) {
      int xr = v ^ ai[i];
      for (int j = ai[i] + 1; j < min0[xr]; ++j) {
        if (vis[j]) std::vector<int>().swap(reach[j]), vis[j] = 0;
        reach[j].push_back(xr);
      }
      res[xr] = 1;
      min0[xr] = std::min(min0[xr], ai[i] + 1);
    }
  }
  res[0] = 1;
  std::vector<int> vec;
  for (int i = 0; i < 8192; ++i)
    if (res[i]) vec.push_back(i);
  printf("%lu\n", vec.size());
  for (auto v : vec) printf("%d ", v);
  printf("\n");
}
int main() {
  t = 1;
  while (t--) solve();
  return 0;
}
