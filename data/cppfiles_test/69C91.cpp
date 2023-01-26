#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
long long CommonSubsequence(string s1, string s2) {
  int i = 0, j = 0;
  int t = 0;
  while (i < s1.length() && j < s2.length()) {
    if (s1[i] == s2[j]) {
      t++;
      j++;
    }
    i++;
  }
  return t;
}
void solve(vector<string> v) {
  string s;
  cin >> s;
  int ans = s.length() + 1;
  for (auto str : v) {
    int n = CommonSubsequence(s, str);
    int p = s.length() - n + str.length() - n;
    ans = min(ans, p);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  vector<string> v;
  for (long long i = 1; i <= 2e18; i *= 2) {
    v.push_back(to_string(i));
  }
  for (long long i = 0; i < t; i++) {
    solve(v);
  }
  return 0;
}
