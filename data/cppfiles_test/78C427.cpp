#include <bits/stdc++.h>
using namespace std;
long long int T;
const long long int mod = 1e9 + 7;
const long long int maxn = 1e5 + 7;
void srinite() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
}
signed main() {
  srinite();
  for (long long int test = 1; test < T + 1; test++) {
    long long int l, r;
    cin >> l >> r;
    long long int v = r / 2 + 1;
    if (l > v)
      cout << r % l << endl;
    else
      cout << r % v << endl;
  }
  return 0;
}
