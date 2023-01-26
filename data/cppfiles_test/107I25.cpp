#include <bits/stdc++.h>
const int xsz = 60 + 1;
const int MOD = 1e9 + 7;
const long long oo = 1e18 + 5;
using namespace std;
void Solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1 or a + b > n - 2) {
    cout << "-1\n";
    return;
  }
  int flag = 0;
  string res = "1";
  if (a > b) {
    for (int i = 2; i < a + b + 2; i += 2) {
      res += " " + to_string(i + 1) + " " + to_string(i);
    }
    if (n % 2 == 0) {
      for (int i = 0; i <= res.size() - 5; ++i) {
        cout << res[i];
      }
      cout << ' ' << n << ' ' << res[res.size() - 3] << ' '
           << res[res.size() - 1] << "\n";
    } else {
      cout << res << "\n";
    }
    return;
  } else if (a < b) {
    res = "3 1 2";
    flag = 2;
  }
  for (int i = 2 + flag; i < a + b + 2; i += 2) {
    res += " " + to_string(i + 1) + " " + to_string(i);
  }
  for (int i = res.size() / 2 + 2; i <= n; ++i) {
    res += " " + to_string(i);
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
  return 0;
}
