#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const long long LLINF = (1LL << 60);
using namespace std;
const double pi = acos(-1.0);
const int mod = 998244353;
long long fast_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return (ans % mod);
}
inline long long read() {
  long long X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
inline void write(long long X) {
  if (X < 0) {
    X = ~(X - 1);
    putchar('-');
  }
  if (X > 9) write(X / 10);
  putchar(X % 10 + '0');
}
inline void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
inline void time_cost(clock_t start_time, clock_t end_time) {
  cout << "The run time is: "
       << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
}
inline void init() {}
long long a, b;
int b1[777], b2[777], suff[777], pref[777];
int idx1 = 0, idx2 = 0;
bool check() {
  if (idx2 < idx1) return 0;
  for (int i = 1; i <= idx2 - idx1 + 1; i++) {
    bool f = 1;
    for (int j = i; j <= i + idx1 - 1; j++) {
      if (b1[j - i + 1] != b2[j]) {
        f = 0;
        break;
      }
    }
    if (f) {
      if (pref[i - 1] && suff[i + idx1]) return 1;
    }
  }
  return 0;
}
void show(long long a) {
  if (!a) return;
  show(a >> 1);
  if (a & 1)
    cout << 1;
  else
    cout << 0;
}
inline void solve() {
  init();
  cin >> a >> b;
  if (a == b) {
    puts("YES");
    return;
  }
  while (a) {
    ++idx1;
    if (a & 1)
      b1[idx1] = 1;
    else
      b1[idx1] = 0;
    a >>= 1;
  }
  while (b) {
    ++idx2;
    if (b & 1)
      b2[idx2] = 1;
    else
      b2[idx2] = 0;
    b >>= 1;
  }
  suff[idx2 + 1] = 1;
  pref[0] = 1;
  for (int i = 1; i <= idx2; i++) pref[i] = (b2[i] && pref[i - 1]);
  for (int i = idx2; i >= 1; i--) suff[i] = (b2[i] && suff[i + 1]);
  int z_cnt = 0;
  for (int i = 1; i <= idx1; i++) {
    if (b1[i] == 0)
      z_cnt++;
    else
      break;
  }
  if (z_cnt == 0) {
    if (check()) {
      puts("YES");
      return;
    }
    reverse(b1 + 1, b1 + idx1 + 1);
    if (check()) {
      puts("YES");
      return;
    }
    puts("NO");
    return;
  } else {
    reverse(b1 + 1, b1 + 1 + idx1);
    idx1 -= z_cnt;
    if (check()) {
      puts("YES");
      return;
    }
    reverse(b1 + 1, b1 + 1 + idx1);
    if (check()) {
      puts("YES");
      return;
    }
    reverse(b1 + 1, b1 + 1 + idx1);
    idx1 += z_cnt;
    reverse(b1 + 1, b1 + 1 + idx1);
    for (int i = idx1 + 1; i >= 2; i--) {
      b1[i] = b1[i - 1];
    }
    b1[1] = 1;
    idx1++;
    if (check()) {
      puts("YES");
      return;
    }
    reverse(b1 + 1, b1 + 1 + idx1);
    if (check()) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}
int main() {
  fastIO();
  solve();
  return 0;
}
