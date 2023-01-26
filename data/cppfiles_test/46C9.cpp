#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long curr = a[n - 1], ans = 0;
    for (long long i = n - 2; i >= 0; i--) {
      if (a[i] > curr) {
        ans++;
        curr = a[i];
      }
    }
    cout << ans << "\n";
  }
}
