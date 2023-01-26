#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 200005, MOD = 1000000007;
ll t, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    ll vl6 = n - (n % 6);
    if (n % 6 != 0) vl6 += 6;
    ll vl8 = n - (n % 8);
    if (n % 8 != 0) vl8 += ((n % 8) != 7 ? 6 : 8);
    ll vl10 = n - (n % 10);
    if (n % 10 != 0) vl10 += ((n % 10) < 7 ? 6 : ((n % 10) == 9 ? 10 : 8));
    cout << (min({vl6, vl8, vl10}) * 5) / 2 << '\n';
  }
  return 0;
}
