#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, d, i, j, k = 0, h, c, p1, p2, q1, q2, A, B, c1, c2, l, m = 0,
                           n, t = 1, q = 0, r, e, x = 0, y = 0, o, s, mx1,
                           mx2 = 0, mx = 0, p = 0, v, mn = 0, z, w;
  string s1, s2, s3, s4;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  x = arr[0];
  t = n / 2;
  i = 1;
  while (t--) {
    cout << arr[i] << " " << x << endl;
    i++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
