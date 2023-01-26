#include <bits/stdc++.h>
using namespace std;
int32_t mod = 1e9 + 7;
void solveCase() {
  string s, t;
  cin >> s >> t;
  if (t.length() > s.length()) {
    cout << "NO\n";
    return;
  }
  if (t.length() == s.length()) {
    cout << (t == s ? "YES" : "NO") << '\n';
    return;
  }
  long long n = s.length(), m = t.length();
  long long st1 = 0, st2 = 0;
  for (long long i = 0; i < n; i++)
    if (s[i] == t[0] && i % 2 == 0) {
      st1 = i;
      break;
    }
  for (long long i = 0; i < n; i++)
    if (s[i] == t[0] && i % 2) {
      st2 = i;
      break;
    }
  bool ans = false;
  long long j = 0, cnt = 0;
  for (long long i = st1; i < n && j < m; i++) {
    if (s[i] == t[j] && cnt % 2 == 0) {
      j++;
      cnt = 0;
      continue;
    }
    cnt++;
  }
  ans |= j == m;
  j = 0, cnt = 0;
  for (long long i = st2; i < n && j < m; i++) {
    if (s[i] == t[j] && cnt % 2 == 0) {
      j++;
      cnt = 0;
      continue;
    }
    cnt++;
  }
  ans |= j == m;
  cout << (ans ? "YES" : "NO") << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  long long t = 0;
  cin >> t;
  while (t--) solveCase();
}
