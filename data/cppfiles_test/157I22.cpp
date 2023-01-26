#include <bits/stdc++.h>
template <typename Sep, typename Head, typename... Tail>
void fold_print(Sep sep, Head&& h, Tail&&... args) {
  ((std::cerr << h) << ... << (std::cerr << sep, args));
}
std::mt19937_64 myrand(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());
using namespace std;
using LL = long long int;
void init();
void process();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  init();
  for (int t = 1; t <= T; t++) {
    process();
  }
  cout.flush();
  return 0;
}
constexpr LL MOD = 998244353;
vector<LL> fac(5000 * 2 + 1), inv(5000 * 2 + 1);
LL fastpw(LL x, LL p) {
  if (p == 0) return 1;
  LL tmp = fastpw(x * x % MOD, p / 2);
  if (p % 2 == 0)
    return tmp;
  else
    return tmp * x % MOD;
}
LL modinv(LL x) { return fastpw(x, MOD - 2); }
void init() {
  fac[0] = 1;
  for (LL i = 1; i < fac.size(); i++) {
    fac[i] = i * fac[i - 1] % MOD;
  }
  for (size_t i = 0; i < inv.size(); i++) {
    inv[i] = modinv(fac[i]);
  }
}
void process() {
  LL n, k;
  cin >> n >> k;
  vector<int> arr(n + 1, 0);
  {
    for (int i = 1; i <= n; i++) {
      char ch;
      cin >> ch;
      arr[i] = ch - '0';
    }
  }
  vector<int> sum(n + 1, 0);
  {
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];
  }
  LL ans = 1;
  vector<tuple<LL, LL>> seg;
  LL l = 1, r = 1, cnt = (arr[1] == 1);
  while (r <= n) {
    if (r + 1 <= n && cnt < k) {
      if (arr[r + 1] == 1) {
        cnt += 1;
        r += 1;
        continue;
      }
    }
    if (r + 1 <= n && cnt == k) {
      if (arr[r + 1] == 0) {
        r += 1;
        continue;
      }
    }
    if (cnt != k) break;
    LL len = r - l + 1;
    LL one = cnt, zero = len - one;
    ans = (ans + MOD - 1 + fac[len] * inv[one] % MOD * inv[zero] % MOD) % MOD;
    if (!seg.empty()) {
      for (auto [prv_l, prv_r] : seg) {
        LL mx_l = max(prv_l, l), mn_r = min(prv_r, r);
        if (mn_r >= mx_l) {
          LL len = mn_r - mx_l + 1;
          LL one = sum[mn_r] - sum[mx_l - 1];
          LL zero = len - one;
          ans = (ans - fac[len] * inv[one] % MOD * inv[zero] % MOD + 1 + MOD) %
                MOD;
        }
      }
    }
    seg.emplace_back(l, r);
    while (cnt == k) {
      cnt -= (arr[l] == 1);
      l++;
    }
  }
  cout << ans << '\n';
}
