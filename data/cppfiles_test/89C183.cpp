#include <bits/stdc++.h>
using namespace std;
const string YES = "YES";
const string NO = "NO";
void solve() {
  long long n;
  cin >> n;
  long long a[n + 1];
  long long flag = 1;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % (i + 1) != 0) flag = 0;
  }
  if (flag == 1) {
    cout << NO << endl;
    return;
  }
  if (n == 1) {
    if (a[1] % 2 != 0) {
      cout << YES << endl;
    } else {
      cout << NO << endl;
    }
    return;
  }
  if (a[1] % 2 == 0) {
    cout << NO << endl;
    return;
  }
  unordered_map<long long, long long> z;
  for (long long i = 1; i <= n; i++) {
    z[i + 1] = a[i];
  }
  long long cp = n + 1;
  while (cp != 1) {
    if (z[cp] % cp != 0) {
      z.erase(cp);
      cp--;
      continue;
    }
    long long flag = 0;
    for (long long i = cp - 1; i >= 2; i--) {
      if (z[i] % i != 0) {
        flag = 1;
        for (long long j = i; j < cp; j++) {
          z[j] = z[j + 1];
        }
        z.erase(cp);
        cp--;
        break;
      }
    }
    if (flag == 0) {
      cout << NO << endl;
      return;
    }
  }
  cout << YES << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
