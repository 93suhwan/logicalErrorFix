#include <bits/stdc++.h>
using namespace std;
void solve() {
  bool f = false;
  long long cp = 0;
  long long h = 1;
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) {
    if (a[i] == 1) {
      cp = 0;
      if (h > 0) {
        if (f) {
          h += 5;
          f = false;
        } else {
          h += 1;
          f = true;
        }
      } else
        ;
    } else {
      f = false;
      cp++;
      if (cp == 2) h = -1;
    }
  }
  cout << h << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
