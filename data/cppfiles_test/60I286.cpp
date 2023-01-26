#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  if (n == 1) {
    long long x;
    cin >> x;
    cout << x << "\n";
  } else if (n == 2) {
    long long a, b;
    cin >> a >> b;
    long long x = a & b;
    cout << x << "\n";
  } else {
    long long mini = INT_MAX;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < mini) {
        mini = a[i];
      }
    }
    cout << mini << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  for (long long t = 1; t <= tc; t++) {
    solve();
  }
}
