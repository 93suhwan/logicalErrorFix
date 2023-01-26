#include <bits/stdc++.h>
using namespace std;
void yn(bool tf) { tf == 1 ? cout << "YES\n" : cout << "NO\n"; }
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<string> v(n - 2);
  for (long long i = 0; i < n - 2; i++) cin >> v[i];
  string str = "";
  str += v[0][0];
  for (long long i = 1; i < n - 2; i++) {
    if (v[i][0] != v[i - 1][1]) {
      str += v[i - 1][1];
      str += v[i][0];
    } else {
      str += v[i][0];
    }
  }
  str += v[n - 3][1];
  while (str.size() != n) str += 'a';
  cout << str << "\n";
}
int main() {
  init();
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
