#include <bits/stdc++.h>
using namespace std;
mt19937_64 rndGen(chrono::steady_clock::now().time_since_epoch().count());
inline long long read() {
  long long s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') f *= c == '-' ? -1 : 1, c = getchar();
  while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();
  return s * f;
}
inline int wk() {
  int n = read();
  vector<int> a(n);
  for (int i = (0), __i = (n); i < __i; ++i) a[i] = read();
  int ans = 0;
  for (; !is_sorted(a.begin(), a.end()); ++ans) {
    for (int i = ans & 1; i < n - 1; i += 2) {
      if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    }
  }
  return ans;
}
int main() {
  for (int _ = (0), ___ = (read()); _ < ___; ++_) cout << wk() << endl;
  return 0;
}
