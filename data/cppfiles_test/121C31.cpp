#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9 + 5;
using namespace std;
int binomialCoeff(int n, int k) {
  if (k > n) return 0;
  if (k == 0 || k == n) return 1;
  return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}
const int N = 1e6 + 5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c;
    string s, t;
    cin >> n >> s >> t;
    a = b = c = 0;
    for (int i = 0; i < n; i++) {
      a += s[i] - '0';
      b += t[i] - '0';
      c += s[i] != t[i];
    }
    int ans = N;
    if (a == b) {
      ans = c;
    }
    if (a == n - b + 1) {
      ans = min(ans, n - c);
    }
    if (ans == N) {
      cout << "-1\n";
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
