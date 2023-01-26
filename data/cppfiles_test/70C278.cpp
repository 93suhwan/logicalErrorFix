#include <bits/stdc++.h>
using namespace std;
void removeChar(string& s, char c) {
  long long j, n = s.length();
  for (long long i = j = 0; i < n; i++)
    if (s[i] != c) s[j++] = s[i];
  s = s.substr(0, j);
}
long long power(long long N, long long M) {
  long long power = N, sum = 1;
  if (N == 0) sum = 0;
  while (M > 0) {
    if ((M & 1) == 1) {
      sum *= power;
    }
    power = power * power;
    M = M >> 1;
  }
  return sum;
}
void solve() {
  string s;
  cin >> s;
  string r = "";
  unordered_set<char> st;
  long long n = s.length();
  for (long long i = n - 1; i >= 0; i--) {
    if (st.find(s[i]) == st.end()) {
      st.insert(s[i]);
      r += s[i];
    }
  }
  reverse(r.begin(), r.end());
  map<char, long long> mp;
  for (long long i = 0; i < n; i++) mp[s[i]]++;
  long long x = r.length();
  for (long long i = 0; i < x; i++) {
    if ((mp[r[i]] / (i + 1)) * (i + 1) != mp[r[i]]) {
      cout << "-1\n";
      return;
    }
  }
  string g = "";
  long long y = 0;
  for (long long i = 0; i < x; i++) {
    y += (mp[r[i]] / (i + 1));
  }
  for (long long i = 0; i < y; i++) g += s[i];
  string p = g;
  string f = "";
  for (long long i = 0; i < x; i++) {
    f += g;
    removeChar(g, r[i]);
  }
  if (f == s)
    cout << p << " " << r << "\n";
  else
    cout << "-1\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
