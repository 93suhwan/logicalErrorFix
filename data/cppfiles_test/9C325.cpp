#include <bits/stdc++.h>
using namespace std;
void solve() {
  string a;
  cin >> a;
  unordered_map<char, int> m;
  for (auto c : a) {
    if (m.find(c) == m.end())
      m[c] = 1;
    else
      m[c]++;
  }
  int single = 0;
  int more = 0;
  for (auto k : m) {
    if (k.second > 1)
      more++;
    else
      single++;
  }
  cout << single / 2 + more << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
