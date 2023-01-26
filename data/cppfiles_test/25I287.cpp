#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  string t;
  getline(cin >> ws, s);
  getline(cin >> ws, t);
  int n = s.size();
  int i, j, k;
  while (true) {
    if (s.find(t[0]) == string::npos) {
      cout << "NO" << endl;
      return;
    }
    i = s.find(t[0]);
    j = i;
    k = 0;
    while (i < n && s[i] == t[k]) {
      i++;
      k++;
    }
    i = i - 2;
    while (i >= 0 && s[i] == t[k]) {
      i--;
      k++;
    }
    if (k == t.size()) {
      cout << "YES" << endl;
      return;
    }
    s = s.substr(j + 1, s.size());
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
