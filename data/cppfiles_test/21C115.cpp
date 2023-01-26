#include <bits/stdc++.h>
using namespace std;
mt19937 mr(time(0));
struct LL {
  static long long int m;
  long long int val;
  LL(long long int v) { val = reduce(v); };
  LL(int v) { val = reduce((long long int)v); };
  LL() { val = 0; };
  ~LL(){};
  LL(const LL& l) { val = l.val; };
  LL& operator=(int l) {
    val = l;
    return *this;
  }
  LL& operator=(long long int l) {
    val = l;
    return *this;
  }
  LL& operator=(LL l) {
    val = l.val;
    return *this;
  }
  static void setMod(long long int m) { LL::m = m; }
  static long long int reduce(long long int x, long long int md = m) {
    x %= md;
    while (x >= md) x -= md;
    while (x < 0) x += md;
    return x;
  }
  bool operator<(const LL& b) { return val < b.val; }
  bool operator<=(const LL& b) { return val <= b.val; }
  bool operator!=(const LL& b) { return val != b.val; }
  bool operator==(const LL& b) { return val == b.val; }
  bool operator>=(const LL& b) { return val >= b.val; }
  bool operator>(const LL& b) { return val > b.val; }
  LL operator+(const LL& b) { return LL(val + b.val); }
  LL operator+(const long long int& b) { return (*this + LL(b)); }
  LL& operator+=(const LL& b) { return (*this = *this + b); }
  LL& operator+=(const long long int& b) { return (*this = *this + b); }
  LL operator-(const LL& b) { return LL(val - b.val); }
  LL operator-(const long long int& b) { return (*this - LL(b)); }
  LL& operator-=(const LL& b) { return (*this = *this - b); }
  LL& operator-=(const long long int& b) { return (*this = *this - b); }
  LL operator*(const LL& b) { return LL(val * b.val); }
  LL operator*(const long long int& b) { return (*this * LL(b)); }
  LL& operator*=(const LL& b) { return (*this = *this * b); }
  LL& operator*=(const long long int& b) { return (*this = *this * b); }
  static LL exp(const LL& x, const long long int& y) {
    long long int z = y;
    z = reduce(z, m - 1);
    LL ret = 1;
    LL w = x;
    while (z) {
      if (z & 1) ret *= w;
      z >>= 1;
      w *= w;
    }
    return ret;
  }
  LL& operator^=(long long int y) { return (*this = LL(val ^ y)); }
  LL operator/(const LL& b) { return ((*this) * exp(b, -1)); }
  LL operator/(const long long int& b) { return (*this / LL(b)); }
  LL operator/=(const LL& b) { return ((*this) *= exp(b, -1)); }
  LL& operator/=(const long long int& b) { return (*this = *this / LL(b)); }
};
ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
long long int LL::m = 1000000007;
using namespace std;
long long int cases, N, M, Q, K, X, Y;
long long int rd() {
  long long int x;
  cin >> x;
  return x;
}
double rdd() {
  double x;
  cin >> x;
  return x;
}
void fl() { cout.flush(); }
template <class T>
void panic(T out) {
  cout << out << endl;
  exit(0);
}
LL C[105][105];
LL DP[105][105][105];
bool V[105][105][105];
LL F[105];
LL dp(int n, int m, int k) {
  if (V[n][m][k]) return DP[n][m][k];
  if (k == 0) {
    V[n][m][k] = 1;
    return DP[n][m][k] = 0;
  }
  if ((m == 1) && (k == 1)) {
    V[n][m][k] = 1;
    return DP[n][m][k] = F[n];
  }
  DP[n][m][k] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = max(0, m - n + 1 + i); j <= min(i, m); ++j) {
      DP[n][m][k] +=
          C[n - 1][i] * dp(i, j, k - 1) * dp(n - 1 - i, m - j, k - 1);
    }
  V[n][m][k] = 1;
  return DP[n][m][k];
}
void read() {
  N = rd();
  M = rd();
  K = rd();
  LL::setMod(rd());
  F[0] = 1;
  for (int i = 1; i <= 105 - 1; ++i) F[i] = F[i - 1] * i;
  for (int i = 0; i < 105; ++i) C[i][0] = C[i][i] = 1;
  for (int i = 0; i < 105; ++i)
    for (int j = 1; j < i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  for (int n = 0; n < 105; ++n)
    for (int m = 0; m < 105; ++m)
      for (int k = 0; k < 105; ++k) DP[n][m][k] = V[n][m][k] = 0;
  for (int i = 0; i < 105; ++i) DP[0][0][i] = V[0][0][i] = 1;
  DP[1][1][1] = V[1][1][1] = 1;
  for (int i = 2; i < 105; ++i) DP[1][0][i] = V[1][0][i] = 1;
  for (int n = 0; n < 105; ++n)
    for (int m = 0; m < 105; ++m)
      for (int k = 0; k < 105; ++k) {
        if (k > n) {
          if (m == 0)
            DP[n][m][k] = F[n];
          else
            DP[n][m][k] = 0;
          V[n][m][k] = 1;
        }
      }
  for (int n = 0; n < 2; ++n)
    for (int m = 0; m < 105; ++m)
      for (int k = 0; k < 105; ++k) V[n][m][k] = 1;
  cout << dp(N, K, M) << endl;
}
int main() {
  bool trials = 0;
  bool interactive = 0;
  if (!interactive) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  if (trials)
    cases = rd();
  else
    cases = 1;
  while (cases--) {
    read();
  }
}
