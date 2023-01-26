#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    long long a[n];
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    stack<long long> q;
    q.push(a[n - 1]);
    for (long long i = n - 2; i >= 0; i--) {
      if (a[i] > q.top()) q.push(a[i]);
    }
    cout << q.size() - 1 << '\n';
  }
}
