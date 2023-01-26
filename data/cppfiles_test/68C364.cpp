#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const int inf = 1e9;
const int N = 1e3 + 2;
bool flag;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  long long k;
  cin >> k;
  long long x = 0, y = 0, tmp = 1, sm = 3, i = 1;
  while (tmp < k) {
    tmp += sm;
    sm += 2;
    i++;
  }
  if (k > tmp - i) {
    y = i;
    sm = tmp - i + 1;
    x = i - (k - sm);
  } else {
    x = i;
    sm = tmp - i + 1;
    y = i - (sm - k);
  }
  cout << y << ' ' << x;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    flag = 0;
    solve();
    cout << '\n';
  }
  return 0;
}
