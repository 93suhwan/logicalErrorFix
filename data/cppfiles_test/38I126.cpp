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
    if (n & 1) {
      ++n;
    }
    cout << (n * 5) / 2 << '\n';
  }
  return 0;
}
