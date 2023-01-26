#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  char c;
  string s;
  cin >> n >> c;
  cin >> s;
  int cnt = count((s).begin(), (s).end(), c);
  if (cnt == n)
    cout << 0 << '\n';
  else {
    if (s[n - 1] == c) {
      cout << 1 << '\n' << n << '\n';
    } else {
      int j = (n + 1) / 2;
      for (; j >= 1; j--) {
        int b = j;
        while (b <= n) {
          if (s[b - 1] != c) break;
          b += j;
        }
        if (b > n) {
          cout << 1 << '\n' << j + 1 << '\n';
          return;
        }
      }
      cout << 2 << '\n' << n - 1 << " " << n << '\n';
    }
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
