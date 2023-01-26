#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long c = 0, ans1 = 0, ans2 = 0;
  long long f = 0;
  while (!f) {
    f = 1;
    for (long long i = 0; i <= n - 2; i += 2) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
        f = 0;
        ans2 = 1;
      }
    }
    if (ans2) {
      c++;
      ans2 = 0;
    }
    for (long long i = 1; i <= n - 2; i += 2) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
        f = 0;
        ans1 = 1;
      }
    }
    if (ans1) {
      c++;
      ans1 = 0;
    }
  }
  cout << c << endl;
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
