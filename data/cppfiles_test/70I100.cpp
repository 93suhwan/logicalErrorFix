#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
void solve() {
  string s;
  cin >> s;
  set<char> st;
  long long int n = s.size();
  vector<vector<long long int>> v(n, vector<long long int>(26, 0));
  for (long long int i = n - 1; i >= 0; i--) {
    for (long long int j = 0; j < 26; j++) {
      if (i != n - 1) {
        v[i][j] = v[i + 1][j];
      }
    }
    v[i][s[i] - 'a'] += 1;
    st.insert(s[i]);
  }
  string ans;
  long long int prev = -1;
  for (long long int i = 0; i < n; i++) {
    long long int ct = 0;
    for (long long int j = 0; j < 26; j++) {
      ct += (v[i][j] > 0 ? 1 : 0);
    }
    if (prev != -1 && prev != ct) {
      ans.push_back(s[i - 1]);
    }
    prev = ct;
  }
  if (st.size() > 1) ans.push_back(s[n - 1]);
  vector<long long int> ind;
  string temp;
  char ch = '&';
  prev = -1;
  bool f = false;
  long long int th = -1;
  for (long long int i = 0; i < n; i++) {
    if (s[i] != ans[0] && ch == '&') {
      ch = s[i];
    }
    if (f && ch == s[i]) {
      ind.push_back(i);
    }
    if (!f) {
      long long int ct = 0;
      for (long long int j = 0; j < 26; j++) {
        ct += (v[i][j] > 0 ? 1 : 0);
      }
      if (prev != -1 && prev != ct) {
        f = true;
        th = i - 1;
        if (ch == s[i]) ind.push_back(i);
      }
      if (s[i] != ans[0] && th == -1) temp.push_back(s[i]);
      prev = ct;
    }
  }
  for (auto i : ind) {
    string t = temp + s.substr(th + 1, i - th - 1);
    long long int l = t.size();
    if (l + i > n) break;
    if (t.compare(s.substr(i, l)) == 0) {
      cout << s.substr(0, i) << " " << ans << endl;
      return;
    }
  }
  cout << -1 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int x;
  cin >> x;
  while (x--) {
    solve();
  }
  return 0;
}
