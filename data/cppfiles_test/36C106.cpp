#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2, M = 1e9 + 7;
int tt = 1, n, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> n;
    if (n == 1) {
      cout << "a\n";
      continue;
    }
    string second = "", ans = "";
    for (int i = 0; i < n / 2 - 1; i++) second += 'a';
    ans += 'a' + second + 'b' + second;
    if (n & 1) ans += 'c';
    cout << ans << "\n";
  }
  return 0;
}
