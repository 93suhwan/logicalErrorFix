#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
const long long int N = 2e5 + 5;
long long int fact[N], inv[N];
void cases() {
  string s, t;
  cin >> s >> t;
  vector<long long int> f(26, 0);
  for (long long int i = 0; i < s.size(); i++) f[s[i] - 'a']++;
  if (t == "abc" && f[0] > 0 && f[1] > 0 && f[2] > 0) {
    string res;
    long long int cnt = f[0];
    char c = 0 + 'a';
    while (cnt--) {
      res = res + c;
    }
    cnt = f[2];
    c = 2 + 'a';
    while (cnt--) {
      res = res + c;
    }
    cnt = f[1];
    c = 1 + 'a';
    while (cnt--) {
      res = res + c;
    }
    for (long long int i = 3; i < 26; i++) {
      cnt = f[i];
      c = i + 'a';
      while (cnt--) {
        res = res + c;
      }
    }
    cout << res << "\n";
  } else {
    string res;
    for (long long int i = 0; i < 26; i++) {
      long long int cnt = f[i];
      char c = i + 'a';
      while (cnt--) {
        res = res + c;
      }
    }
    cout << res << "\n";
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    cases();
  }
}
