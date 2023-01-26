#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000;
const int N = 1e6 + 7, M = N * 2;
const int inf = 0x3f3f3f3f;
const long long INF = 0xFFFFFFFFFF;
const long long mod = 1e9 + 7;
inline long long read();
void solve() {
  long long a;
  cin >> a;
  if (a == 1) {
    cout << 1 << '\n';
    return;
  }
  if (a == 2) {
    cout << 12 << '\n';
  }
  long long ans = 1;
  for (int i = a * 2; i >= 3; i--) {
    ans = ans * i % mod;
  }
  ans %= mod;
  cout << ans << '\n';
}
int main() {
  int T = 1;
  T = read();
  for (int cas = 1; cas <= T; cas++) {
    solve();
  }
  return 0;
}
inline long long read() {
  char ch_read = getchar();
  long long p_read = 1, data_read = 0;
  while (ch_read < '0' || ch_read > '9') {
    if (ch_read == '-') p_read = -1;
    ch_read = getchar();
  }
  while (ch_read >= '0' && ch_read <= '9') {
    data_read = data_read * 10 + (ch_read ^ 48);
    ch_read = getchar();
  }
  return p_read * data_read;
}
