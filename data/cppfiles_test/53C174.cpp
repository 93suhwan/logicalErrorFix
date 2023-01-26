#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const int maxn = 1001;
const long long mod = 1000000007;
void solve() {
  int a;
  char k;
  string s;
  cin >> a >> k >> s;
  s = " " + s;
  int ind = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != k) {
      ind = 1;
      break;
    }
  }
  if (ind == 0) {
    cout << 0;
    return;
  }
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == k) {
      int ind = 0;
      for (int t = i; t < s.size(); t += i) {
        if (s[t] != k) {
          ind = 1;
          break;
        }
      }
      if (ind == 0) {
        cout << 1 << endl;
        cout << i;
        return;
      }
    }
  }
  cout << 2 << endl;
  cout << a << " " << a - 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
