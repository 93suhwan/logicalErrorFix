#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long int oo = 1e18;
const long long int mod = 1e9;
const int base = 31;
const int tx[4] = {0, 0, 1, -1};
const int ty[4] = {1, -1, 0, 0};
const long long int maxN = 100 + 5;
long long int n;
string s1;
void solve() {
  cin >> n >> s1;
  s1 = ' ' + s1;
  for (long long int j = 1; j <= (n); j++) {
    if (s1[j] == '1') continue;
    if (s1[j] == '0')
      if (j > (n + 1) / 2) {
        cout << 1 << " " << j - 1 << " " << 1 << " " << j << " " << endl;
        return;
      } else {
        cout << j + 1 << " " << n << " " << j << " " << n << endl;
        return;
      }
  }
  cout << 2 << " " << n << " " << 1 << " " << n - 1 << endl;
  return;
}
int main() {
  {
    ios::sync_with_stdio(false);
    cin.tie(0);
  };
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
