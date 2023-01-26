#include <bits/stdc++.h>
using namespace std;
clock_t time_p = clock();
void time_taken() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
const long long mod = 1e9 + 7;
const long long INF = 1e18;
long long modinv(long long a, long long m) {
  assert(m > 0);
  if (m == 1) return 0;
  a %= m;
  if (a < 0) a += m;
  assert(a != 0);
  if (a == 1) return 1;
  return m - modinv(m, a) * m / a;
}
template <int MOD_>
struct modnum {
 private:
  int v;

 public:
  static const int MOD = MOD_;
  modnum() : v(0) {}
  modnum(long long v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend bool operator==(const modnum &a, const modnum &b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum &a, const modnum &b) {
    return a.v != b.v;
  }
  modnum operator~() const {
    modnum res;
    res.v = modinv(v, MOD);
    return res;
  }
  modnum &operator+=(const modnum &o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum &operator-=(const modnum &o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum &operator*=(const modnum &o) {
    v = int(long long(v) * long long(o.v) % MOD);
    return *this;
  }
  modnum &operator/=(const modnum &o) { return *this *= (~o); }
  friend modnum operator+(const modnum &a, const modnum &b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum &a, const modnum &b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum &a, const modnum &b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum &a, const modnum &b) {
    return modnum(a) /= b;
  }
};
using num = modnum<998244353>;
vector<num> fact;
vector<num> ifact;
void init() {
  fact = {1};
  for (int i = 1; i < 300005; i++) fact.push_back(i * fact[i - 1]);
  for (num x : fact) ifact.push_back(1 / x);
}
num ncr(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * ifact[k] * ifact[n - k];
}
num powmod(num x, int a) {
  if (a == 0) return 1;
  if (a & 1) return x * powmod(x, a - 1);
  return powmod(x * x, a / 2);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  struct stnode {
    int ind;
    num sum[2][2];
  };
  vector<vector<num>> dp(n, vector<num>(2));
  vector<stnode> stk;
  for (int i = 0; i < n; i++) {
    vector<vector<num>> sum(2, vector<num>(2));
    while (!stk.empty() and a[stk.back().ind] > a[i]) {
      for (int k = 0; k < 2; k++) {
        for (int j = 0; j < 2; j++) {
          sum[k][j] += stk.back().sum[k][j];
        }
      }
      stk.pop_back();
    }
    if (i % 2 == 0) {
      dp[i][0] = sum[0][1];
      dp[i][0] += sum[1][0];
      dp[i][1] = sum[1][1];
      dp[i][1] += sum[0][0];
    } else {
      dp[i][0] = sum[1][1];
      dp[i][0] += sum[0][0];
      dp[i][1] = sum[0][1];
      dp[i][1] += sum[1][0];
    }
    dp[i][0] *= a[i];
    dp[i][1] *= a[i];
    if (!stk.empty()) {
      int ind = stk.back().ind;
      if (ind % 2 == i % 2) {
        dp[i][0] += (a[i]) * dp[ind][1] + dp[ind][0];
        dp[i][1] += (a[i]) * dp[ind][0] + dp[ind][1];
      } else {
        dp[i][0] += (a[i]) * dp[ind][0] + dp[ind][1];
        dp[i][1] += (a[i]) * dp[ind][1] + dp[ind][0];
      }
    } else {
      if (i % 2 == 0) {
        dp[i][0] += a[i];
      } else
        dp[i][1] += a[i];
    }
    sum[i % 2][0] += dp[i][0];
    sum[i % 2][1] += dp[i][1];
    stnode foo;
    foo.ind = i;
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) foo.sum[j][k] = sum[j][k];
    stk.push_back(foo);
    ;
  }
  cout << int(dp[n - 1][0] - dp[n - 1][1]) << '\n';
  time_taken();
  return 0;
}
