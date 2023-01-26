#include <bits/stdc++.h>
using namespace std;
void Err() {}
template <class T, class... A>
void Err(T a, A... x) {
  cerr << a << ',';
  Err(x...);
}
template <class X, class Y, class... A>
void Err(pair<X, Y> a, A... x) {
  cerr << '(' << a.first << ',' << a.second << ')';
  Err(x...);
}
template <template <class...> class T, class t, class... A>
void Err(T<t> a, A... x) {
  cerr << a.size() << ":{";
  for (auto v : a) Err(v);
  cerr << "}";
  Err(x...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
template <class T>
void Min(T &a, const T b) {
  if (a > b) a = b;
}
template <class T>
void Max(T &a, const T b) {
  if (a < b) a = b;
}
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int N = 100 + 10, M = 400;
const long long mod = 998244353;
long long n, m, k, p;
long long f[N][N][N];
long long C[N][N];
long long solve(int i, int j, int x) {
  if (x > i || j > i) return 0;
  if (f[i][j][x] == -1) {
    f[i][j][x] = 0;
    for (int a = 1; a <= i; a++) {
      for (int b = 0; b <= x; b++) {
        (f[i][j][x] += C[i - 1][a - 1] * solve(a - 1, j - 1, b) % p *
                       solve(i - a, j - 1, x - b) % p) %= p;
      }
    }
  }
  return f[i][j][x];
}
int main() {
  memset(f, -1, sizeof(f));
  ios::sync_with_stdio(0), cin.tie(0);
  ;
  cin >> n >> m >> k >> p;
  for (int i = 0; i < N; i++) C[i][0] = 1 % p;
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
  for (int i = 0; i < N; i++) {
    f[0][i][0] = 1;
    for (int j = 1; j < N; j++) {
      f[0][i][j] = 0;
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < N; j++) f[i][1][j] = 0;
    if (i == 1)
      f[i][1][1] = 1;
    else
      f[i][1][1] = f[i - 1][1][1] * i % p;
  }
  cout << solve(n, m, k);
}
