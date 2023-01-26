#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t, i, j, k, n, x, y, z, r, l, a, c, b, q, T, d, m;
  cin >> n;
  long long int first = ceil(double(n) / 3);
  long long int first1 = (n) / 3;
  long long int second = (n - first) / 2;
  if ((first * 1 + (second)*2) == n)
    cout << first << " " << second << "\n";
  else {
    cout << second << " " << first << "\n";
  }
}
int main() {
  long long int t;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
