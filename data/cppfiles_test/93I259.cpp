#include <bits/stdc++.h>
using namespace std;
long long int computeXOR(long long int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
void solve() {
  vector<long long int> v;
  map<long long int, long long int> mp;
  long long int e, i, j, l, m, x, y, z, r, k, n;
  cin >> n >> m;
  x = computeXOR(n - 1);
  if (x ^ n == m)
    cout << n + 2 << endl;
  else if (x == m)
    cout << n << endl;
  else
    cout << n + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
