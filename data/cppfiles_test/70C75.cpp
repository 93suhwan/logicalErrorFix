#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
bool helper(string s, string s1, string s2) {
  long long int ind = 0;
  string temp = "";
  while (ind < s2.size() && s1.size() > 0) {
    temp += s1;
    string st;
    for (long long int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[ind]) st.push_back(s1[i]);
    }
    s1 = st;
    ind++;
  }
  return (s.compare(temp) == 0);
}
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
  if (st.size() == 1) {
    cout << s << " " << s[0] << endl;
    return;
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
  vector<long long int> fr(26, 0);
  for (auto ch : s) {
    fr[ch - 'a']++;
  }
  vector<long long int> cnt(26, 0);
  for (long long int i = ans.size() - 1; i >= 0; i--) {
    long long int ct = fr[ans[i] - 'a'] / (i + 1);
    cnt[ans[i] - 'a'] += ct;
  }
  for (long long int i = 0; i < 26; i++) {
    fr[i] = 0;
  }
  long long int ind = -1;
  for (long long int i = 0; i < n; i++) {
    fr[s[i] - 'a']++;
    bool f = false;
    for (long long int j = 0; j < 26; j++) {
      if (fr[j] != cnt[j]) {
        f = true;
        break;
      }
    }
    if (!f) {
      ind = i;
      break;
    }
  }
  if (ind != -1) {
    string first = s.substr(0, ind + 1);
    if (helper(s, first, ans)) {
      cout << first << " " << ans << endl;
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
