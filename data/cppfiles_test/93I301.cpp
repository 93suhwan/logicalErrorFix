#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<long long int> v;
  map<long long int, long long int> mp;
  long long int e, i, j, l, m, x, y, z, r, k, n;
  cin >> n >> m;
  x = 0;
  long long int c = 0;
  if (m == 1) {
    if (n == 1) {
      cout << 3 << endl;
    } else if (n == 2)
      cout << 2 << endl;
    else
      cout << n + 1 << endl;
  } else
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
