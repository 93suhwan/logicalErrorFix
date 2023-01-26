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
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool chkmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
int n, m, k;
int sizbig, sizsmall;
int cntbig, cntsmall;
void main0() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    sizbig = (n - 1) / m + 1;
    sizsmall = n / m;
    cntbig = n % m;
    cntsmall = m - cntbig;
    int p = 1;
    int pbig = 0, psmall = 0;
    for (int round = 1; round <= k; ++round) {
      for (int i = 1; i <= cntbig; ++i) {
        cout << sizbig << ' ';
        for (int j = 1; j <= sizbig; ++j, p = p % n + 1) {
          cout << p << ' ';
        }
        cout << endl;
      }
      for (int i = 1; i <= cntsmall; ++i) {
        cout << sizsmall << ' ';
        for (int j = 1; j <= sizsmall; ++j, p = p % n + 1) {
          cout << p << ' ';
        }
        cout << endl;
      }
      p = ((p - sizsmall * cntsmall - 1) % n + n) % n + 1;
    }
  }
}
