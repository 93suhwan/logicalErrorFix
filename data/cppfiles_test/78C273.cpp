#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
inline void smax(int &x, int y) { x = max(x, y); }
inline void smin(int &x, int y) { x = min(x, y); }
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tcase;
  cin >> tcase;
  for (__typeof(tcase + 1) tc = (1) - ((1) > (tcase + 1));
       tc != (tcase + 1) - ((1) > (tcase + 1));
       tc += 1 - 2 * ((1) > (tcase + 1))) {
    int l, r;
    cin >> l >> r;
    l = max(l, r / 2 + 1);
    cout << r % l << "\n";
  }
}
