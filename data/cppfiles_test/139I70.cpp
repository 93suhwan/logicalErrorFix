#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  if (n % 2 == 1) {
    cout << "NO"
         << "\n";
  } else {
    string s1, s2;
    int flag = 0;
    for (int i = 0; i < n / 2; i++) {
      s[i] = s1[i];
    }
    for (int i = n / 2; i < n; i++) {
      s[i] = s2[i - n / 2];
    }
    for (int i = 0; i < n / 2; i++) {
      if (s1[i] != s2[i]) {
        cout << "NO\n";
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "YES\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
