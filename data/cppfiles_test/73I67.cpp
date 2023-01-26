#include <bits/stdc++.h>
const long long INF = 1e18;
using namespace std;
void f() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  f();
  int test = 1;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    long long ans = 0, r = 1;
    while (1) {
      bool yes = false;
      if (r % 2) {
        for (int i = n - 1; i >= 0; i -= 2) {
          if (i - 1 >= 0) {
            if (v[i] < v[i - 1]) {
              yes = true;
              swap(v[i], v[i - 1]);
            }
          }
        }
        if (yes) {
          ans++;
        }
      } else {
        for (int i = n - 2; i >= 0; i -= 2) {
          if (i - 1 >= 0) {
            if (v[i] < v[i - 1]) {
              yes = true;
              swap(v[i], v[i - 1]);
            }
          }
        }
        if (yes) {
          ans++;
        }
      }
      r++;
      bool ok = true;
      for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    cout << ans << '\n';
  }
}
