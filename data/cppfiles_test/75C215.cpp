#include <bits/stdc++.h>
const long long mod = 998244353;
const long long ds = 1e18;
const double eps = 1e-8;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return f * x;
}
void print(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x / 10) print(x / 10);
  putchar(x % 10 + '0');
}
using namespace std;
const int N = 1e6 + 5;
pair<long long, long long> maxi[100005];
void solve() {
  int n = read();
  for (int i = 0; i < n; ++i) maxi[i].first = 0;
  for (int i = 0; i < n; ++i) {
    long long k = read();
    maxi[i].second = k;
    vector<long long> tmp(k);
    for (int j = 0; j < k; ++j) {
      tmp[j] = read() - j;
      maxi[i].first = max(maxi[i].first, tmp[j]);
    }
  }
  sort(maxi, maxi + n);
  long long now = 0, tmp = 0;
  for (int i = 0; i < n; ++i) {
    if (now + tmp <= maxi[i].first) now = maxi[i].first + 1 - tmp;
    tmp += maxi[i].second;
  }
  cout << now << endl;
}
int main() {
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}
