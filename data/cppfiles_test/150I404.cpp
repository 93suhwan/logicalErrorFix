#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e11;
const long long mod = 1e9 + 7;
const long long inf = 1000000000000000000;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long mx = a[n - 1];
  bool f0 = 0;
  bool f1 = 0;
  bool f2 = 0;
  for (long long i = 0; i < n; i++) {
    long long x = a[i] % 3;
    if (x == 0) {
      f0 = 1;
    }
    if (x == 1) {
      f1 = 1;
    }
    if (x == 2) {
      f2 = 1;
    }
  }
  long long ans = -1;
  if (f1 == 0 && f2 == 0) {
    ans = mx / 3;
  }
  if (f1 == 1 && f2 == 0) {
    if (mx % 3 == 0) {
      ans = (mx / 3) - 1 + 2;
    } else if (mx % 3 == 1) {
      ans = (mx / 3) + 1;
    }
  }
  if (f1 == 0 && f2 == 1) {
    if (mx % 3 == 0) {
      ans = (mx / 3) - 1 + 2;
    } else if (mx % 3 == 2) {
      ans = (mx / 3) + 1;
    }
  }
  if (f1 == 1 && f2 == 1) {
    if (mx % 3 == 0) {
      ans = (mx / 3) - 1 + 2;
    } else if (mx % 3 == 1) {
      bool find = false;
      for (long long i = 0; i < n; i++) {
        if (a[i] != mx && a[i] % 3 == 1) {
          find = true;
          break;
        }
      }
      if (find == false) {
        ans = (mx / 3) - 1 + 2;
      } else {
        ans = (mx / 3) + 2;
      }
    } else if (mx % 3 == 2) {
      ans = (mx / 3) + 2;
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
