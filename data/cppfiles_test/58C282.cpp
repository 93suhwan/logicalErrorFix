#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const int MOD = 1000000007;
const int N = 200005;
int n;
string s1, s2;
bool q;
void solve() {
  cin >> n >> s1 >> s2;
  q = 1;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '1' and s2[i] == '1') {
      q = 0;
      break;
    }
  }
  if (q)
    cout << "YES" << nl;
  else
    cout << "NO" << nl;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
