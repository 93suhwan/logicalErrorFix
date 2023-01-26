#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int N;
int C[23][26];
signed long long dp[1 << 23];
signed long long F[1 << 23];
signed long long G[1 << 23];
const signed long long mo = 998244353;
signed long long comb(int P_, int Q_) {
  static const int N_ = 1020;
  static signed long long C_[N_][N_];
  if (C_[0][0] == 0) {
    int i, j;
    for (i = 0; i < (N_); i++) C_[i][0] = C_[i][i] = 1;
    for (i = 1; i < N_; i++)
      for (j = 1; j < i; j++) C_[i][j] = (C_[i - 1][j - 1] + C_[i - 1][j]) % mo;
  }
  if (P_ < 0 || P_ > N_ || Q_ < 0 || Q_ > P_) return 0;
  return C_[P_][Q_];
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N;
  for (i = 0; i < (N); i++) {
    cin >> s;
    for (auto &c : s) C[i][c - 'a']++;
  }
  int mask, mask2;
  for (mask = 0; mask < (1 << N); mask++)
    if (mask) {
      int C2[26];
      for (j = 0; j < (26); j++) C2[j] = 1 << 20;
      for (i = 0; i < (N); i++)
        if (mask & (1 << i)) {
          for (j = 0; j < (26); j++) C2[j] = min(C2[j], C[i][j]);
        }
      F[mask] = 1;
      for (j = 0; j < (26); j++) (F[mask] *= C2[j] + 1) %= mo;
      x = __builtin_popcount(mask);
      if (x % 2 == 0) F[mask] = mo - F[mask];
    }
  for (i = 0; i < (N); i++) {
    for (mask = 0; mask < (1 << N); mask++)
      if (mask & (1 << i)) (F[mask] += F[mask ^ (1 << i)]) %= mo;
  }
  signed long long ret = 0;
  for (mask = 0; mask < (1 << N); mask++) {
    int k = 0;
    int s = 0;
    for (i = 0; i < (N); i++)
      if (mask & (1 << i)) k++, s += i + 1;
    ret ^= F[mask] * k * s;
  }
  cout << ret << endl;
}
int main(int argc, char **argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
