#include <bits/stdc++.h>
using namespace std;
void shivam() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  int n;
  cin >> n;
  string s;
  string s1;
  cin >> s >> s1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' and s1[i] == '1') {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
  return;
}
int main() {
  shivam();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
