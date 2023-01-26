#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0, j = n / 2; j < n; i++, j++) {
    if (s[i] != s[j] || n % 2) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
