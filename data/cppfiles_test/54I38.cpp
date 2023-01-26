#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:360777216")
using LL = long long;
using ld = long double;
const int INF = 2 * 1000 * 1000 * 1000;
LL MOD = 1e9 + 7;
LL LINF = (LL)4e18;
double EPS = 1e-7;
using namespace std;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }
const LL max_er = 1e2;
vector<LL> min_div(max_er + 1, 0);
vector<int> pp(max_er + 1, 1);
vector<LL> res(max_er + 1, -1);
vector<LL> primes;
void eratosfen() {
  pp[0] = pp[1] = 0;
  for (LL i = 2; i <= max_er; ++i) {
    if (!pp[i]) continue;
    primes.push_back(i);
    min_div[i] = i;
    for (LL j = i * i; j <= max_er; j += i) {
      pp[j] = 0;
      if (!min_div[j]) min_div[j] = i;
    }
  }
}
vector<pair<int, int> > divs;
void get_divs(LL n) {
  while (n != 1) {
    LL cur = min_div[n];
    LL cnt = 0;
    while (n % cur == 0) {
      n /= cur;
      cnt++;
    }
    divs.push_back({cur, cnt});
  }
}
LL dp[200100][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  srand(time(nullptr));
  LL __ = 1, n, m, k, r, g, b;
  LL mod = 1e9 + 7;
  cin >> __;
  for (int(_) = 0; (_) < __; (_)++) {
    cin >> n >> k;
    if (k == 0) {
      cout << 1 << endl;
      continue;
    }
    memset(dp, 0, sizeof(dp));
    LL p2n = 1, p2n_1 = 1;
    for (int(i) = 0; (i) < n - 1; (i)++) {
      p2n_1 *= 2ll;
      p2n_1 %= mod;
    }
    p2n = p2n_1 * 2;
    p2n %= mod;
    if (n % 2 == 0) {
      dp[0][0] = (p2n_1 - 1 + mod) % mod;
      dp[0][1] = 1;
    } else {
      dp[0][0] = (p2n_1 + 1) % mod;
    }
    for (int(i) = 1; (i) < k; (i)++) {
      LL cur0 = 0;
      if (n % 2 == 0)
        cur0 = (p2n_1 - 1 + mod) % mod;
      else
        cur0 = (p2n_1 + 1) % mod;
      dp[i][0] = (dp[i - 1][0] * cur0) % mod;
      dp[i][1] = (cur0 * dp[i - 1][1]) % mod;
      LL cur1 = 0;
      if (n % 2 == 0)
        cur1 = 1;
      else
        cur1 = 0;
      dp[i][1] += (cur1 * (dp[i - 1][0] + dp[i - 1][1])) % mod;
      dp[i][1] %= mod;
    }
    LL ans = (dp[k - 1][1] + dp[k - 1][0]) % mod;
    cout << ans << endl;
  }
  return 0;
}
