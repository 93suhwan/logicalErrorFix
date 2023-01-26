#include <bits/stdc++.h>
using namespace std;
string s;
bool solve() {
  int n = s.length();
  if (n & 1) return false;
  for (int i = 0, j = n >> 1; i < n >> 1 && j < n; ++i, ++j) {
    if (s[i] != s[j]) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    if (solve())
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}
