#include <bits/stdc++.h>
using namespace std;
long long int query(vector<long long int> a) {
  long long int response;
  cout << "? ";
  for (auto i : a) cout << i << " ";
  cout << endl;
  cin >> response;
  return response;
}
int32_t main() {
  long long int n;
  cin >> n;
  long long int t = 0;
  vector<long long int> a(n, n), ans(n, 1);
  while (++t <= n) {
    a[n - 1] = n - t;
    long long int i = query(a) - 1;
    if (i == -1) {
      ans[n - 1] = t;
      break;
    }
    if (i < n - 1) ans[i] = -t;
  }
  t = 0;
  a.clear();
  a.resize(n, 1);
  while (a[n - 1] + ++t <= n) {
    a[n - 1] = 1 + t;
    long long int i = query(a) - 1;
    if (i == -1) {
      break;
    }
    if (i < n - 1) ans[i] = t;
  }
  cout << "! ";
  for (long long int i = 0; i < n - 1; i++) cout << ans[i] + ans[n - 1] << " ";
  cout << ans[n - 1];
}
