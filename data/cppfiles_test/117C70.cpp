#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
template <typename T>
void read(T& x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
template <typename T, typename... Arg>
void read(T& x, Arg&... args) {
  read(x);
  read(args...);
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; };
long long ksm(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans % mod;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
const int maxn = 1e6 + 10;
int t, n, m;
char in[maxn];
string mp[maxn];
vector<int> dp1[maxn];
vector<int> forbid[maxn];
vector<bool> ok[maxn];
int ex, ey;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
struct node {
  int x, y;
};
void solve() {
  queue<node> que;
  que.push({ex, ey});
  while (!que.empty()) {
    node a = que.front();
    que.pop();
    int x = a.x, y = a.y;
    for (int i = 0; i < 4; ++i) {
      int dx = x + dir[i][0];
      int dy = y + dir[i][1];
      if (dx < 0 || dy < 0 || dx >= n || dy >= m || mp[dx][dy] != '.' ||
          ok[dx][dy])
        continue;
      dp1[dx][dy]++;
      if (dp1[dx][dy] + forbid[dx][dy] >= 3) {
        ok[dx][dy] = 1;
        que.push({dx, dy});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (ok[i][j]) {
        mp[i][j] = '+';
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> mp[i];
      ok[i].resize(m, 0);
      forbid[i].resize(m, 0);
      dp1[i].resize(m, 0);
    }
    for (int i = 0; i <= n - 1; ++i) {
      for (int j = 0; j <= m - 1; ++j) {
        if (mp[i][j] == 'L') {
          ex = i;
          ey = j;
        }
        for (int k = 0; k < 4; ++k) {
          int dx = i + dir[k][0];
          int dy = j + dir[k][1];
          if (dx < 0 || dy < 0 || dx >= n || dy >= m) {
            forbid[i][j]++;
          } else if (mp[dx][dy] == '#') {
            forbid[i][j]++;
          }
        }
      }
    }
    solve();
    for (int i = 0; i < n; ++i) {
      cout << mp[i] << '\n';
    }
    for (int i = 0; i < n; ++i) {
      mp[i].clear();
      ok[i].clear();
      forbid[i].clear();
      dp1[i].clear();
    }
  }
  return 0;
}
