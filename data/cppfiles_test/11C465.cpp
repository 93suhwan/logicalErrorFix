#include <bits/stdc++.h>
using namespace std;
void Test() {
  long long n;
  cin >> n;
  string s[n];
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long ans = 0;
  for (char i = 'a'; i <= 'e'; i++) {
    vector<pair<long long, long long> > v;
    for (long long j = 0; j < n; j++) {
      long long cnti = 0, len = s[j].size();
      for (long long k = 0; k < len; k++) {
        if (s[j][k] == i) {
          ++cnti;
        }
      }
      v.push_back(make_pair(2 * cnti - len, cnti));
    }
    sort(v.begin(), v.end());
    long long curr = 0, oth = 0, temp = 0;
    for (long long j = n - 1; j >= 0; j--) {
      long long length = ((2 * v[j].second) - v[j].first);
      long long x = v[j].second;
      long long y = (length - v[j].second);
      if ((curr + x) > (oth + y)) {
        curr += x;
        oth += y;
        ++temp;
      }
    }
    ans = max(ans, temp);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(10);
  long long tests;
  cin >> tests;
  for (long long tc = 1; tc <= tests; tc++) Test();
  return 0;
}
