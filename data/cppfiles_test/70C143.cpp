#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, k, now, ans = 0, j;
  string s, t = "", str = "", p, res;
  cin >> s;
  n = s.length();
  set<char> st;
  for (i = n - 1; i >= 0; i--) {
    if (st.find(s[i]) == st.end()) {
      st.insert(s[i]);
      t = s[i] + t;
    }
  }
  k = st.size();
  now = k;
  for (i = k - 1; i >= 0; i--) {
    ans += count(s.begin(), s.end(), t[i]) / now;
    now--;
  }
  for (i = 0; i < ans; i++) {
    str += s[i];
  }
  res = str;
  for (i = 0; i < t.length(); i++) {
    p = "";
    for (j = 0; j < str.size(); j++) {
      if (str[j] != t[i]) {
        p += str[j];
      }
    }
    str = p;
    res += str;
  }
  if (s == res) {
    for (i = 0; i < ans; i++) {
      cout << s[i];
    }
    cout << ' ' << t << endl;
  } else {
    cout << -1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(NULL));
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
