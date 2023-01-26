#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, n;
  cin >> x >> n;
  int pp = n % 4;
  long long z;
  if (pp == 0)
    z = 0;
  else if (pp == 1)
    z = -n;
  else if (pp == 2)
    z = 1;
  else
    z = n + 1;
  long long dre = x % 2 == 0 ? 1 : -1;
  x += dre * z;
  cout << x << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
