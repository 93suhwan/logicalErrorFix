#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1 << 20;
int cnt[24][26];
int n;
int ma[24][26];
unsigned long long ans;
int dp[1 << 23];
void dfs(int id, int seed) {
  if (id == n) {
    int v = 1;
    for (int i = 0; i < (26); ++i) {
      v = v * (long long)ma[id][i] % MOD;
    }
    dp[seed] = v;
    return;
  }
  memcpy(ma[id + 1], ma[id], sizeof(int) * 26);
  dfs(id + 1, seed | (1 << id));
  for (int i = 0; i < (26); ++i) {
    ma[id + 1][i] = min(ma[id][i], cnt[id][i]);
  }
  dfs(id + 1, seed);
}
int get_bit(long long x, int v) { return (x >> v) & 1; }
void solve() {
  for (int i = 0; i < (26); ++i) ma[0][i] = MOD;
  dfs(0, 0);
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      if (get_bit(j, i)) {
        dp[j] -= dp[j ^ (1 << i)];
        if (dp[j] < 0) dp[j] += MOD;
      }
    }
  }
  int AA = 0;
  for (int i = 0; i < ((1 << n) - 1); ++i) {
    AA += dp[i];
    if (AA >= MOD) AA -= MOD;
  }
  dp[(1 << n) - 1] = 0;
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      if (get_bit(j, i)) {
        dp[j ^ (1 << i)] += dp[j];
        if (dp[j ^ (1 << i)] >= MOD) dp[j ^ (1 << i)] -= MOD;
      }
    }
  }
  for (int i = (1); i < ((1 << n)); ++i) {
    int me = i;
    int num = 0;
    int sum = 0;
    for (int j = 0; j < (n); ++j) {
      if (me & 1) {
        num++;
        sum += j;
      }
      me >>= 1;
    }
    int dd = AA - dp[i];
    if (dd < 0) dd += MOD;
    ans ^= dd * (long long)(num + sum) * num;
  }
  W(ans);
}
void input() {
  R(n);
  for (int i = 0; i < (n); ++i) {
    string s;
    R(s);
    for (int j = 0; j < (26); ++j) cnt[i][j] = 1;
    for (char c : s) {
      cnt[i][c - 'a']++;
    }
  }
}
int main() {
  MOD = 998244353;
  input();
  solve();
  return 0;
}
