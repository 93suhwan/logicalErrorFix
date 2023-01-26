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
const int N = 2e6 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
mt19937_64 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool chkmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T &x, T y) {
  return y > x ? x = y, 1 : 0;
}
int d[N];
unsigned long long w[N];
unsigned long long wfac[N];
void init() {
  for (int i = 2; i <= N - 1; ++i)
    if (d[i] == 0) {
      for (int j = 1; i * j <= N - 1; ++j) {
        if (d[i * j] == 0) d[i * j] = i;
      }
    }
  for (int i = 1; i <= N - 1; ++i) {
    if (d[i] == i) w[i] = rnd();
  }
  for (int i = 1; i <= N - 1; ++i) {
    wfac[i] = wfac[i - 1];
    int cur = i;
    while (cur > 1) {
      wfac[i] ^= w[d[cur]];
      cur /= d[cur];
    }
  }
}
int n;
int ban[N];
void output() {
  cout << count(ban + 1, ban + n + 1, 0) << endl;
  for (int i = 1; i <= n; ++i) {
    if (ban[i] == 0) cout << i << ' ';
  }
  cout << endl;
}
void main0() {
  init();
  cin >> n;
  unsigned long long xorsum = 0;
  for (int i = 1; i <= n; ++i) {
    xorsum ^= wfac[i];
  }
  if (xorsum == 0) {
    return output();
  }
  for (int i = 1; i <= n; ++i) {
    if ((wfac[i] ^ xorsum) == 0) {
      ban[i] = 1;
      return output();
    }
  }
  map<unsigned long long, int> pos;
  for (int i = 1; i <= n; ++i) {
    pos[wfac[i]] = i;
    if (pos.count(wfac[i] ^ xorsum)) {
      ban[i] = ban[pos[wfac[i] ^ xorsum]] = 1;
      return output();
    }
  }
  ban[n / 2] = ban[n] = ban[2] = 1;
  return output();
}
