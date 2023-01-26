#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const long long INF = (long long)(1e18) + 5;
const int N = 5e5 + 5;
long long fp(long long x, long long y, long long m = Mod) {
  long long res = 1;
  for (int i = 0; (1LL << i) <= y; i++, x = x * x % m)
    if (y & 1LL << i) res = res * x % m;
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (s[i] == c);
    if (cnt == n) {
      cout << "0\n";
      continue;
    }
    s = "#" + s;
    cnt = -1;
    for (int i = 2; i <= n; i++) {
      bool ok = 1;
      for (int j = i; ok && j <= n; j += i) ok = (ok && s[j] == c);
      if (ok) {
        cnt = i;
        break;
      }
    }
    if (cnt != -1) {
      cout << "1\n" << cnt << '\n';
      continue;
    }
    cout << "2\n" << n - 1 << ' ' << n << '\n';
  }
  return 0;
}
