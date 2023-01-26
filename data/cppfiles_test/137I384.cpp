#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
const long long maxn = 2e5 + 10;
bool check(string a, string b) {
  long long p = b.find(a);
  if (p == -1) return false;
  for (long long i = 0; i < b.size(); ++i) {
    if (i >= p && i < p + a.size()) continue;
    if (b[i] != '1') return false;
  }
  return true;
}
inline void solve() {
  long long x = read(), y = read();
  if (x == y) {
    puts("YES");
    return;
  }
  string a1 = "", a2 = "", a3 = "", a4 = "", b = "";
  while (x) a1 = (x & 1 ? '1' : '0') + a1, x /= 2;
  while (y) b = (y & 1 ? '1' : '0') + b, y /= 2;
  a3 = a4 = a1 + '1';
  while (a1.back() == '0') a1.pop_back();
  a2 = a1;
  reverse(a2.begin(), a2.end());
  reverse(a4.begin(), a4.end());
  if (check(a1, b) || check(a2, b) || check(a3, b) || check(a4, b))
    puts("YES");
  else
    puts("NO");
}
signed main() {
  solve();
  return 0;
}
