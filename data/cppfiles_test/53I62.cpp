#include <bits/stdc++.h>
using namespace std;
bool check(string& s, char c) {
  for (auto& x : s)
    if (x != c) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    if (check(s, c)) {
      cout << 0 << "\n";
      continue;
    }
    bool flag = false;
    for (int i = (n + 1) / 2; i <= n; i++) {
      if (s[i - 1] == c) {
        cout << 1 << "\n";
        cout << i << "\n";
        flag = true;
        break;
      }
    }
    if (flag) continue;
    cout << 2 << "\n";
    cout << n - 1 << " " << n << "\n";
  }
  return 0;
}
