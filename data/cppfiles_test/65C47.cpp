#include <bits/stdc++.h>
using namespace std;
int sgn(long long x) { return x / abs(x); }
int sgn2(char c) { return c == 'L' ? 1 : -1; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  string s;
  cin >> s;
  int k = 1;
  for (int i = 1; i < n; ++i)
    if (s[i - 1] != s[i]) ++k;
  int j = k;
  --k;
  string ans;
  ans += s[0];
  vector<int> b;
  b.push_back(a[k--]);
  long long bal = b[0] * sgn2(s[0]);
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      long long nbal = bal - sgn2(s[i]) * a[j];
      b.push_back(a[j]);
      if (sgn(nbal) != sgn2(s[i])) {
        nbal = bal + sgn2(s[i]) * a[j];
        ans.push_back(s[i]);
      } else {
        ans.push_back(s[i] ^ 'L' ^ 'R');
      }
      ++j;
      bal = nbal;
    } else {
      b.push_back(a[k]);
      bal += a[k] * sgn2(s[i]);
      ans.push_back(s[i]);
      --k;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] << ' ' << ans[i] << '\n';
  }
  return 0;
}
