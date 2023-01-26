#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 1, iend = n >> 1; i <= iend; ++i)
      cout << a[i] << ' ' << *a << '\n';
  }
}
