#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
  map<char, int> mp;
  for (auto i : s) mp[i]++;
  int cnt = 0, c = 0;
  for (auto i : mp) {
    if (i.second > 1)
      cnt++;
    else
      c++;
  }
  cout << cnt + (c >> 1);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) {
    cin >> s;
    solve();
    cout << "\n";
  }
  return 0;
}
