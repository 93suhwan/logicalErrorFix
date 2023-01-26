#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') f *= c == '-' ? -1 : 1, c = getchar();
  while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();
  return s * f;
}
inline void wk() {
  int n = read(), m = read();
  vector<int> a(n), bin(n), ans;
  for (int i = (0), __i = (n); i < __i; ++i)
    a[i] = read() - 1, ++bin[(i + n - a[i]) % n];
  auto chk = [&](int r) {
    vector<char> vis(n);
    int cnt = 0;
    for (int i = (0), __i = (n); i < __i; ++i)
      if (!vis[i]) {
        int p = i;
        while (!vis[p]) vis[p] = 1, p = (a[p] + r) % n;
        ++cnt;
      }
    return cnt >= n - m;
  };
  for (int i = (0), __i = (n); i < __i; ++i)
    if (bin[i] >= n - 2 * m && chk(i)) ans.push_back(i);
  cout << ans.size();
  for (auto x : ans) cout << ' ' << x;
  cout << endl;
}
int main() {
  for (int _ = (0), ___ = (read()); _ < ___; ++_) {
    wk();
  }
  return 0;
}
