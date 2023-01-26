#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 2e5 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
const double Pi = acos(-1.0);
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long qpow(long long n, long long m) {
  long long ret = 1;
  while (m) {
    if (m & 1) ret = ret * n % mod;
    n = n * n % mod;
    m >>= 1;
  }
  return ret;
}
long long getinv(long long a) { return qpow(a, mod - 2); }
void main0() {
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    n = max(6ll, n);
    n = (n + 1) / 2;
    cout << 5 * n << endl;
  }
}
