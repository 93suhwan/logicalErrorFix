#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
using pii = pair<int, int>;
int DB[61] = {
    0,         1,         16,        4096,      268435456, 536396504, 829977023,
    174552830, 963649099, 50795912,  525602746, 702924858, 569547144, 485905719,
    666822377, 685849181, 570353452, 899118382, 62414555,  377263818, 10259398,
    945369883, 837827574, 456643269, 613517530, 719593623, 200980458, 442204075,
    244712433, 129444287, 114361693, 748417155, 638342199, 748644482, 92294856,
    150917654, 70891986,  301511690, 124656161, 863741005, 937126335, 649470305,
    985780905, 764337989, 425219517, 952509357, 146159477, 78006097,  25260018,
    78301512,  817092115, 547145395, 786071314, 893277629, 179955566, 123077080,
    244650040, 448417738, 527798077, 158436354, 489580313};
int n, m, ans;
map<pii, int> cache;
int GetDep(int n) {
  int ret = 0;
  for (int i = 1; n; n >>= 1, i++)
    if (n & 1) ret = i;
  return ret;
}
int Sol(int cur, int color, vector<pii> v) {
  int flag = 1, dep = GetDep(cur);
  if (v.empty()) return DB[n - dep + 1];
  for (auto& [a, b] : v)
    if (a == cur && b != color) flag = 0;
  if (!flag) return 0;
  if (dep == n) return 1;
  if (cache.count({cur, color})) return cache[{cur, color}];
  vector<pii> L, R;
  for (const auto& [a, b] : v) {
    if (a == cur) continue;
    int t_dep = GetDep(a);
    int t = a >> (t_dep - dep - 1);
    if (t == (cur << 1))
      L.push_back({a, b});
    else
      R.push_back({a, b});
  }
  int l = 0, r = 0;
  for (int i = 0; i < 6; i++)
    if (i / 2 != color / 2) l = (l + Sol(cur << 1, i, L)) % MOD;
  for (int i = 0; i < 6; i++)
    if (i / 2 != color / 2) r = (r + Sol(cur << 1 | 1, i, R)) % MOD;
  return cache[{cur, color}] = 1LL * l * r % MOD;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  vector<pii> v;
  while (m--) {
    int t;
    string s;
    cin >> t >> s;
    v.push_back({t, string("wygbro").find(s[0])});
  }
  for (int i = 0; i < 6; i++) ans = (ans + Sol(1, i, v)) % MOD;
  cout << ans << '\n';
}
