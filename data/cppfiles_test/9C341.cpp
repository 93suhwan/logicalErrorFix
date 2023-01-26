#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const long long biginf = 1e18;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> v(26, 0);
  for (int i = 0; s[i]; i++) {
    v[int(s[i] - 'a')]++;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (v[i] <= 1) {
      ans += v[i];
    } else {
      ans += 2;
    }
  }
  cout << ans / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solve();
  }
  return 0;
}
