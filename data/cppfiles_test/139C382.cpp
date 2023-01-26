#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(
    chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);
bool solve(string& s) {
  int n = (int)(s).size();
  if (n % 2 != 0) return false;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[i + (n / 2)]) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    cout << (solve(s) ? "YES" : "NO") << nl;
  }
  return 0;
}
