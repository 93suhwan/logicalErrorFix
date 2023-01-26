#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using pii = std::pair<long long, long long>;
using namespace std;
long long t, n, m, rb, cb, rd, cd, p;
long long ok_mod(long long x) { return x >= 0 && x < MOD; }
long long mod_expo(long long x, long long p) {
  assert(ok_mod(x) && ok_mod(p));
  if (!p) return 1;
  long long res = mod_expo(x, p / 2);
  res *= res;
  res %= MOD;
  if (p & 1) res *= x;
  return res % MOD;
}
long long mod_inv(long long x) { return mod_expo(x, MOD - 2); }
long long calc_inf_agp(long long a1, long long g1, long long d, long long r) {
  assert(ok_mod(a1) && ok_mod(g1) && ok_mod(d) && ok_mod(r));
  long long fi_num = (a1 * g1) % MOD;
  long long fi_denom = (1 - r + MOD) % MOD;
  long long se_num = (((d * r) % MOD) * g1) % MOD;
  long long se_denom = mod_expo((1 - r + MOD) % MOD, 2);
  long long fi_res = (fi_num * mod_inv(fi_denom)) % MOD;
  long long se_res = (se_num * mod_inv(se_denom)) % MOD;
  return (fi_res + se_res) % MOD;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (long long cases = 0; cases < t; cases++) {
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    long long clean_prob = (p * mod_inv(100)) % MOD;
    long long not_clean_prob = ((100 - p) * mod_inv(100)) % MOD;
    rb--;
    cb--;
    rd--;
    cd--;
    vector<vector<vector<vector<long long>>>> visited(
        n, vector<vector<vector<long long>>>(
               m, vector<vector<long long>>(2, vector<long long>(2, 0))));
    vector<pii> cycle_elements;
    long long cur_r = rb, cur_c = cb;
    long long dir_r = (rb == 0) ? -1 : 1, dir_c = (cb == 0) ? -1 : 1;
    while (!visited[cur_r][cur_c][(dir_r + 1) / 2][(dir_c + 1) / 2]) {
      visited[cur_r][cur_c][(dir_r + 1) / 2][(dir_c + 1) / 2] = 1;
      cycle_elements.push_back({cur_r, cur_c});
      if (cur_r == 0 || cur_r == n - 1) dir_r *= -1;
      if (cur_c == 0 || cur_c == m - 1) dir_c *= -1;
      cur_r += dir_r;
      cur_c += dir_c;
    }
    assert(cycle_elements.front() == make_pair(cur_r, cur_c));
    long long ans = 0;
    long long cycle_good = 0;
    for (auto x : cycle_elements)
      if (x.first == rd || x.second == cd) cycle_good++;
    long long prob_ap_ratio = cycle_elements.size();
    long long prob_gp_ratio = mod_expo(not_clean_prob, cycle_good);
    long long prob_ap_base = 0;
    long long prob_gp_base = 1;
    for (auto x : cycle_elements) {
      if (x.first == rd || x.second == cd) {
        ans += calc_inf_agp(prob_ap_base, prob_gp_base, prob_ap_ratio,
                            prob_gp_ratio);
        ans %= MOD;
        prob_gp_base *= not_clean_prob;
        prob_gp_base %= MOD;
      }
      prob_ap_base++;
      prob_ap_base %= MOD;
    }
    cout << (ans * clean_prob) % MOD << "\n";
  }
  return 0;
}
