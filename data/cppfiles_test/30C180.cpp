#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int n;
string s;
bool palindrome(string s) {
  for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
    if (s[l] != s[r]) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> s;
    if (palindrome(s)) {
      cout << "0\n";
      continue;
    }
    int ans = INF;
    for (auto i = 'a'; i <= 'z'; i++) {
      string t;
      int cnt = 0;
      vector<int> v;
      for (auto j : s) {
        if (i != j) {
          v.push_back(cnt);
          cnt = 0;
          t += j;
        } else
          cnt++;
      }
      v.push_back(cnt);
      if (!palindrome(t)) continue;
      int cur = 0, tot = 0;
      for (int j : v) tot += j;
      for (int l = 0, r = v.size() - 1; l <= r; l++, r--) {
        if (l == r)
          cur += 2 * v[l] / 2;
        else
          cur += 2 * min(v[l], v[r]);
      }
      ans = min(ans, tot - cur);
    }
    cout << (ans == INF ? -1 : ans) << '\n';
  }
  return 0;
}
