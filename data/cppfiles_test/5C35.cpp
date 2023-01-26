#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s, p;
    long long st = 0, sd = 0;
    cin >> s >> p;
    long long ans = 0;
    long long a[n], b[n], c[n], d[n];
    for (long long i = 0; i < n; i++) {
      a[i] = s[i] - '0';
      b[i] = p[i] - '0';
      c[i] = a[i];
      d[i] = b[i];
      if (s[i] == '1') {
        st++;
      }
      if (p[i] == '1') {
        sd++;
      }
    }
    if (st == 0) {
      ans = sd;
    } else if (sd == 0) {
      ans = 0;
    } else {
      for (long long i = 0; i < n - 1; i++) {
        long long tl = a[i], tr = a[i + 1], bl = b[i], br = b[i + 1];
        if (bl == 1) {
          if (tl == 0) {
            ans++;
            tl = -1;
            a[i] = -1;
            b[i] = 0;
          } else if (tr == 1) {
            ans++;
            tr == -1;
            a[i + 1] = -1;
            b[i] = 0;
          }
        }
        if (br == 1) {
          if (tr == 0) {
            ans++;
            tr = -1;
            a[i + 1] = -1;
            b[i + 1] = 0;
          } else if (tl == 1) {
            ans++;
            tl = -1;
            a[i] = -1;
            b[i + 1] = 0;
          }
        }
      }
      long long mx = 0;
      for (long long i = n - 1; i >= 1; i--) {
        long long tl = c[i], tr = c[i - 1], bl = d[i], br = d[i - 1];
        if (bl == 1) {
          if (tl == 0) {
            mx++;
            tl = -1;
            c[i] = -1;
            d[i] = 0;
          } else if (tr == 1) {
            mx++;
            tr == -1;
            c[i - 1] = -1;
            d[i] = 0;
          }
        }
        if (br == 1) {
          if (tr == 0) {
            mx++;
            tr = -1;
            c[i - 1] = -1;
            d[i - 1] = 0;
          } else if (tl == 1) {
            mx++;
            tl = -1;
            c[i] = -1;
            d[i - 1] = 0;
          }
        }
      }
      ans = max(ans, mx);
    }
    cout << ans << "\n";
  }
}
