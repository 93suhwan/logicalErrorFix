#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
  }
  sort(v.begin(), v.end());
  string s;
  cin >> s;
  int changes = 0;
  for (int i = 0; i + 1 < s.size(); ++i) {
    changes += s[i] != s[i + 1];
  }
  int l = n - 1 - changes, r = n - 1 - changes;
  char lstleft = s[0];
  char lstright = s[0];
  vector<pair<int, char> > ans;
  ans.emplace_back(v[l], s[0]);
  for (int j = 1; j < n; j++) {
    if (s[j] != s[j - 1]) {
      r++;
      lstright = char('L' + 'R' - lstright);
      ans.emplace_back(v[r], lstright);
    } else {
      l--;
      lstleft = char('L' + 'R' - lstleft);
      ans.emplace_back(v[l], lstleft);
    }
  }
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  while (t--) solve();
}
