#include <bits/stdc++.h>
using namespace std;
void fast_io(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve(void) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  int p = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      p++;
    }
    if (s[i] == '0' && p == 0) {
      cout << "0";
    } else {
      if (s[i] == '0') {
        cout << p;
        p = 0;
      }
    }
  }
  if (p != 0) {
    cout << p;
  }
}
int main(void) {
  fast_io();
  solve();
  return 0;
}
