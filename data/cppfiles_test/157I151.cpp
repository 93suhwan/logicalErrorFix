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
LL C(LL n, LL m) { return fac[n] * inv[m] % MOD * inv[n - m] % MOD; }
void process() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  {
    for (auto& x : arr) {
      char ch;
      cin >> ch;
      x = ch - '0';
    }
  }
  auto permute = [&](LL l, LL r, LL one) {
    LL len = r - l + 1;
    LL cnt[] = {len - one, one};
    cnt[1 - arr[l]] -= 1;
    return C(len - 1, cnt[0]);
  };
  LL ans = 1, r = 0, cnt = arr[0];
  for (LL i = 0; i < n; cnt -= arr[i], i += 1) {
    while (r + 1 < n && cnt + arr[r + 1] <= k) {
      cnt += arr[r + 1], r += 1;
    }
    if (cnt != k) break;
    if (r == n - 1) {
      ans = (ans + MOD - 1 + C(r - i + 1, cnt)) % MOD;
      break;
    } else {
      ans = (ans + permute(i, r, cnt)) % MOD;
    }
  }
  cout << ans << '\n';
}
