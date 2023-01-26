#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 1; i < n - 1; i++) {
    if (s1[i] == '1' && s2[i] == '1') {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
