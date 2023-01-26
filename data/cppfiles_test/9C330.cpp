#include <bits/stdc++.h>
using namespace std;
void func() {
  string s;
  cin >> s;
  map<char, int> m;
  for (char c : s) {
    m[c]++;
  }
  int ans = 0;
  for (auto it = m.begin(); it != m.end(); ++it) {
    int x = it->second;
    ans += min(2, x);
  }
  cout << ans / 2 << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    func();
  }
  return 0;
}
