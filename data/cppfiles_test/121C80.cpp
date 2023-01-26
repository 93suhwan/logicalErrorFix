#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
const long long INF = 1e18;
const int MX = 200005;
vector<int> decToBinary(int n) {
  int binaryNum[32];
  vector<int> v;
  int i = 0;
  while (n > 0) {
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
  }
  for (int j = 0; j < i; j++) {
    v.push_back(binaryNum[j]);
  }
  return v;
}
int solve() {
  int c1 = 0, c2 = 0;
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < (n); i++) {
    if (s[i] == '0' && t[i] == '1') {
      c1++;
    }
    if (s[i] == '1' && t[i] == '0') {
      c2++;
    }
  }
  int ans = 1e9;
  if (c1 == c2) ans = 2 * c1;
  long long in = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' && t[i] == '1') {
      in = i;
    }
  }
  if (in == -1) {
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
    return 0;
  }
  for (int i = 0; i < (n); i++) {
    if (i == in) continue;
    if (s[i] == '1')
      s[i] = '0';
    else
      s[i] = '1';
  }
  c1 = 0, c2 = 0;
  for (int i = 0; i < (n); i++) {
    if (s[i] == '0' && t[i] == '1') {
      c1++;
    }
    if (s[i] == '1' && t[i] == '0') {
      c2++;
    }
  }
  if (c1 == c2) {
    ans = min(ans, 2 * c1 + 1);
  }
  if (ans == 1e9) ans = -1;
  cout << ans << endl;
  return 0;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
