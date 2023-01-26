#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN = 1e3 + 3;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (s[i] - '0');
    if (i != n - 1 && s[i] != '0') ans += 1;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
