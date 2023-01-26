#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  bool flag0 = false;
  bool flag1 = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      flag0 = true;
    } else {
      flag1 = true;
    }
  }
  if (!flag0) {
    cout << 0 << "\n";
    return;
  }
  if (!flag1) {
    cout << 1 << "\n";
    return;
  }
  char prev = s[0];
  int app0 = 0;
  int app1 = 0;
  if (prev == '0') {
    app0++;
  } else {
    app1++;
  }
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '0') {
      if (prev == '1') {
        app0++;
        prev = '0';
      }
    } else {
      if (prev == '0') {
        app1++;
        prev = '1';
      }
    }
  }
  if (app0 > 1) {
    cout << 2 << "\n";
  } else {
    cout << 1 << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
