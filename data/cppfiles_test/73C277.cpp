#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  while (true) {
    bool sorted = true;
    for (long long i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        sorted = false;
      }
    }
    if (sorted) {
      cout << ans << endl;
      return;
    }
    long long l;
    if (ans % 2 == 0) {
      l = 0;
    } else {
      l = 1;
    }
    for (long long i = l; i + 1 < n; i += 2) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
      }
    }
    ans++;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
