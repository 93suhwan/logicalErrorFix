#include <bits/stdc++.h>
using namespace std;
ifstream in("test.in");
ofstream out("test.out");
using ll = long long;
const ll N = 1e5 + 2;
void solve() {
  string s;
  cin >> s;
  int red = 0, green = 0;
  map<char, int> m;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (m[s[i]] < 2) {
      if (red <= green) {
        red++;
      } else {
        green++;
      }
      m[s[i]]++;
    }
  }
  cout << min(red, green) << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
