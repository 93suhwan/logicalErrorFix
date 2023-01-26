#include <bits/stdc++.h>
using namespace std;
long long findx(string s, long long n) {
  long long lo = 1, hi = n;
  long long ans;
  long long counter = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == 'L') {
      counter--;
      lo = min(n, max(1 - counter, lo));
      hi = max((long long)1, min(n - counter, hi));
    } else if (s[i] == 'R') {
      counter++;
      lo = min(n, max(1 - counter, lo));
      hi = max((long long)1, min(n - counter, hi));
    }
    if (lo == hi) break;
  }
  ans = lo;
  return ans;
}
long long findy(string s, long long n) {
  long long lo = 1, hi = n;
  long long ans;
  long long counter = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == 'D') {
      counter++;
      lo = min(n, max(1 - counter, lo));
      hi = max((long long)1, min(n - counter, hi));
    } else if (s[i] == 'U') {
      counter--;
      lo = min(n, max(1 - counter, lo));
      hi = max((long long)1, min(n - counter, hi));
    }
    if (lo == hi) break;
  }
  ans = lo;
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long x = findy(s, n);
    long long y = findx(s, m);
    cout << x << " " << y << '\n';
  }
}
