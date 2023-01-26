#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const long long MOD = 1e9 + 7;
const int N = 2e6 + 10;
const long double pi = 3.1415926535897932384650288;
int n, m;
string s, t;
bool ok(int i, int j, int d) {
  if (j == m) return 1;
  if (i == n) return 0;
  if (i < 0) return 0;
  if (s[i] != t[j]) return 0;
  if (d) {
    return ok(i - 1, j + 1, d);
  }
  return ok(i + 1, j + 1, d) || ok(i - 1, j + 1, 1);
}
void solve() {
  cin >> s >> t;
  n = s.size();
  m = t.size();
  for (int i = 0; i < n; i++) {
    if (ok(i, 0, 0)) {
      puts("Yes");
      return;
    }
  }
  puts("No");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
