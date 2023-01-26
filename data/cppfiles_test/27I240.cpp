#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  int i = 0, j = 0, n1 = s.length(), n2 = t.length();
  vector<int> v;
  for (i = 0; i < n1; i++) {
    if (s[i] == t[0]) v.push_back(i);
  }
  for (j = 0; j < v.size(); j++) {
    i = v[j];
    while (i < n1) {
      if (s[i] == t[j]) {
        i++;
        j++;
      } else
        i = i + 2;
    }
    if (j == n2 && i == n1) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
  return;
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k;
  while (k--) {
    solve();
  }
  return 0;
}
