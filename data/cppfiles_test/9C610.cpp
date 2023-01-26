#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void comp() {
  string s;
  cin >> s;
  map<char, int> m;
  for (int i = 0; i < s.length(); i++) m[s[i]]++;
  int ans = 0, cnt = 0;
  for (pair<char, int> p : m) {
    if (p.second >= 2)
      ans++;
    else
      cnt++;
  }
  ans += cnt / 2;
  cout << ans << "\n";
}
int main() {
  fast();
  int t = 1;
  cin >> t;
  while (t--) {
    comp();
  }
  return 0;
}
