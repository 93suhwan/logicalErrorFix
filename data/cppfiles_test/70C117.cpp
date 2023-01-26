#include <bits/stdc++.h>
using namespace std;
bool check(string& a, string& b, string& order) {
  string temp = a, temp2 = a;
  for (int i = 0; i < order.size() - 1; i++) {
    string temp3 = "";
    for (int j = 0; j < temp.size(); j++) {
      if (temp[j] != order[i]) {
        temp3 += temp[j];
      }
    }
    temp2 += temp3;
    temp = temp3;
  }
  return temp2 == b;
}
void solve() {
  string t;
  cin >> t;
  vector<int> v(26, 0);
  set<char> s;
  string orig = "";
  for (int i = t.size() - 1; i >= 0; i--) {
    v[t[i] - 'a'] += 1;
    if (s.count(t[i]) == 0) {
      orig += t[i];
      s.insert(t[i]);
    }
  }
  reverse(orig.begin(), orig.end());
  int len = 0;
  for (int i = orig.size() - 1; i >= 0; i--) {
    if (v[orig[i] - 'a'] % (i + 1)) {
      cout << "-1\n";
      return;
    }
    len += v[orig[i] - 'a'] / (i + 1);
  }
  string ans = t.substr(0, len);
  bool a = check(ans, t, orig);
  if (!a) {
    cout << "-1\n";
    return;
  }
  cout << ans << " " << orig << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }
}
