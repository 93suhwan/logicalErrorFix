#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
const int N = 2e5 + 10;
int a[N];
map<int, int> mp;
signed main() {
  int _;
  read(_);
  while (_--) {
    mp.clear();
    int n;
    read(n);
    long long s = 0, ans = 0;
    for (int i = (1); i <= (n); i++) read(a[i]), s += a[i], mp[a[i]]++;
    if (s % n != 0) {
      puts("0");
      continue;
    }
    long long mid = s / n;
    for (int i = (1); i <= (n); i++)
      if (a[i] < mid) ans += mp[mid * 2 - a[i]];
    ans += mp[mid] * (mp[mid] - 1) / 2;
    cout << ans << endl;
  }
  return 0;
}
