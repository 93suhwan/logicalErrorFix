#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 0x3f3f3f3f;
const int64_t INFLL = 0x3f3f3f3f3f3f3f3f;
const int64_t MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int64_t rand(int64_t x, int64_t y) {
  return uniform_int_distribution<int64_t>(x, y)(rng);
}
int64_t mul(int64_t a, int64_t b) {
  int64_t ret = (1ll * (a % MOD) * (b % MOD)) % MOD;
  return (ret + MOD) % MOD;
}
int64_t add(int64_t a, int64_t b) {
  int64_t ret = (1ll * (a % MOD) + (b % MOD)) % MOD;
  return (ret + MOD) % MOD;
}
int64_t pow_exp(int64_t n, int64_t p) {
  if (!p) return 1;
  if (p & 1) return mul(n, pow_exp(n, p - 1));
  int64_t tmp = pow_exp(n, p / 2);
  return mul(tmp, tmp);
}
const int64_t MAX = 2e5 + 10;
const int64_t NMAX = 2e5 + 10;
const int64_t MMAX = 2e5 + 10;
const int64_t LOG_MAX = ceil(log2(double(NMAX)));
const int64_t BLOCK = ceil(sqrt(double(NMAX)));
int64_t n;
string str[20];
map<int64_t, vector<int64_t> > mp[20];
int64_t tot[20];
int64_t mem[1 << 20];
int64_t go(int64_t msk, int64_t sm) {
  if (msk + 1 == 1 << n) {
    return 0;
  }
  int64_t &ret = mem[msk];
  if (ret + 1) return ret;
  int64_t ans = 0;
  for (int64_t i = 0; i < n; i++)
    if (((msk >> i) & 1) == 0) {
      int64_t mn = mp[i].begin()->first;
      if (sm + mn >= 0) {
        int64_t cans = 0;
        cans += go(msk ^ (1 << i), sm + tot[i]);
        auto it = mp[i].find(-sm);
        if (it != mp[i].end()) cans += it->second.size();
        ans = max(ans, cans);
      } else {
        auto it = mp[i].find(-sm);
        if (it == mp[i].end()) {
          continue;
        }
        if (it == mp[i].begin()) {
          int64_t cans = it->second.size();
          ans = max(ans, cans);
        } else {
          auto &v = mp[i][-sm];
          int64_t r = (--it)->second.front();
          int64_t cans = lower_bound(v.begin(), v.end(), r) - v.begin();
          ans = max(ans, cans);
        }
      }
    }
  return ret = ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int64_t i = 0; i < n; i++) {
    cin >> str[i];
  }
  for (int64_t i = 0; i < n; i++) {
    int64_t sm = 0;
    for (int64_t j = 0; j < str[i].size(); j++) {
      sm += str[i][j] == '(' ? +1 : -1;
      mp[i][sm].push_back(j);
    }
    tot[i] = sm;
  }
  memset(mem, -1, sizeof mem);
  cout << go(0, 0) << '\n';
}
