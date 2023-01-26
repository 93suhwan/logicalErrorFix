#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
void solve() {
  long long n, odd = 0, even = 0, minodd = INT_MAX, mineven = INT_MAX;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] & 1)
      odd++;
    else
      even++;
  }
  if (abs(odd - even) > 1) {
    cout << -1;
    return;
  }
  if (odd >= even) {
    minodd = 0;
    long long c = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] & 1) {
        minodd += abs(i - c);
        c += 2;
      }
    }
  }
  if (even >= odd) {
    mineven = 0;
    long long c = 0;
    for (long long i = 0; i < n; i++) {
      if (!(a[i] & 1)) {
        mineven += abs(i - c);
        c += 2;
      }
    }
  }
  cout << min(minodd, mineven);
}
