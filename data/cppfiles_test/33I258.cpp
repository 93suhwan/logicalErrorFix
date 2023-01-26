#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i, j, k, l, r, m;
  cin >> n;
  vector<long long int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  ;
  auto itr = max_element(a.begin(), a.end());
  long long int di = distance(a.begin(), itr);
  long long int left = -1;
  if (di == 0)
    cout << a[0] * a[1] << "\n";
  else if (di == n - 1)
    cout << a[n - 1] * a[n - 2] << "\n";
  else
    cout << max(a[di + 1], a[di - 1]) * a[di] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, k, n, m;
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
