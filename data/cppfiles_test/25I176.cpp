#include <bits/stdc++.h>
using namespace std;
int compare(vector<char> a, string b) {
  if (a.size() != b.size())
    return 0;
  else {
    for (int i = 0; i < a.size(); i++)
      if (a[i] != b[i]) return 0;
  }
  return 1;
}
void solve() {
  string s, t;
  cin >> s >> t;
  vector<char> ans;
  long long j = 0, lst, k = 0;
  long long x = s.find(t[0]);
  for (int i = x; i < s.size(); i++, k++) {
    if (s[i] == t[k]) {
      ans.push_back(s[i]);
      lst = i;
    } else
      break;
    if (compare(ans, t)) {
      cout << "YES\n";
      return;
    }
  }
  for (int i = lst - 1; i >= 0; i--, k++) {
    if (s[i] == t[k]) {
      ans.push_back(s[i]);
    }
    if (compare(ans, t)) {
      cout << "YES\n";
      return;
    }
  }
  if (compare(ans, t))
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
