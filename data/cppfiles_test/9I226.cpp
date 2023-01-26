#include <bits/stdc++.h>
using namespace std;
void solve(string s) {
  int c[200] = {0};
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    c[s[i]]++;
  }
  for (int i = 0; i < 200; i++) {
    if (c[i] != 0) cnt++;
  }
  if (cnt >= s.size() / 2) {
    cout << s.size() / 2 << "\n";
  } else
    cout << cnt << "\n";
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    solve(s);
  }
  return 0;
}
