#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long tt = 0; tt < t; tt++) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    vector<long long> blue(n + 1, 0);
    vector<long long> red(n + 1, 0);
    vector<long long> perm(n + 1, 0);
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'B' && a[i] <= 0) {
        continue;
      } else if (s[i] == 'B') {
        long long temp = min(a[i], n);
        blue[temp] += 1;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'R' && a[i] > n) {
        continue;
      } else if (s[i] == 'R') {
        long long temp = max((long long)1, a[i]);
        red[temp] += 1;
      }
    }
    long long j = 1;
    for (long long i = 1; i < n + 1; i++) {
      if (red[i] != 0) {
        for (long long k = 0; k < red[i]; k++) {
          if (j <= n) {
            j = max(i, j);
            perm[j++] = 1;
          }
        }
      }
    }
    j = n;
    for (long long i = n; i > 0; i--) {
      if (blue[i] != 0) {
        for (long long k = 0; k < blue[i]; k++) {
          if (j >= 0) {
            j = min(j, i);
            perm[j--] += 1;
          }
        }
      }
    }
    long long ct2 = 0, ct0 = 0;
    for (long long i = 1; i <= n; i++) {
      if (perm[i] == 2) {
        ct2++;
      } else if (perm[i] == 0) {
        ct0++;
      }
    }
    if (ct2 >= ct0) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
