#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
  string s, t;
  cin >> s >> t;
  long long n = s.length();
  long long d = t.length();
  long long flag = 0;
  for (long long i = 0; i < n; i++) {
    long long right = min(d - 1, n - i - 1);
    for (long long j = 0; j <= right; j++) {
      long long left = d - j - 1;
      if (left > i + j) {
        continue;
      } else {
        string rev = string(s.begin() + i + j - left, s.begin() + i + j);
        reverse(rev.begin(), rev.end());
        string check = string(s.begin() + i, s.begin() + i + j + 1) + rev;
        if (t == check) {
          flag = 1;
        }
      }
    }
  }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
