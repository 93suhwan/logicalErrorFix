#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, MOD = 1e9 + 7;
template <class A, class B>
pair<A, B> operator+(pair<A, B>& a, pair<A, B>& b) {
  return {a.first + b.first, a.second + b.second};
}
template <class A, class B>
pair<A, B> operator-(pair<A, B>& a, pair<A, B>& b) {
  return {a.first - b.first, a.second - b.second};
}
template <class A, class B>
istream& operator>>(istream& is, pair<A, B>& a) {
  return is >> a.first >> a.second;
}
template <class A, class B>
ostream& operator<<(ostream& os, const pair<A, B>& a) {
  return os << "< " << a.first << " , " << a.second << " >";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
  os << '[';
  if (!v.empty()) {
    os << v[0];
    for (int i = (1); i < (v.size()); i++) os << ',' << v[i];
  }
  return os << ']';
}
template <class T>
ostream& operator<<(ostream& os, set<T> v) {
  os << '{';
  if (!v.empty()) {
    os << *v.begin();
    for (auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it;
  }
  return os << '}';
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);
const int MAX = 1e6 + 10;
int c, n;
int divs[MAX];
void precalc() {
  fill(divs, divs + MAX + 1, -1);
  for (int i = (2); i < (MAX + 1); i++) {
    if (divs[i] != -1) continue;
    for (int j = i; j <= MAX; j += i) divs[j] = i;
  }
}
int f(int first) {
  int xx = first;
  vector<int> d;
  while (first > 1) {
    d.push_back(divs[first]), first /= divs[first];
  }
  sort(d.begin(), d.end()), d.resize(unique(d.begin(), d.end()) - d.begin());
  for (int dd : d) first *= dd;
  return first;
}
vector<vector<int>> solve(vector<int>& a, int need) {
  const int M = 300;
  int n = a.size();
  vector<bitset<20>> mat(n);
  vector<bitset<M>> who(n);
  for (int i = (0); i < (n); i++) mat[i] = a[i], who[i][i] = 1;
  int row = 0;
  vector<int> col(20, -1);
  for (int j = (0); j < (20); j++) {
    int good = -1;
    for (int i = (row); i < (n); i++)
      if (mat[i][j]) {
        good = i;
        break;
      }
    if (good == -1) continue;
    col[j] = row;
    swap(mat[row], mat[good]);
    swap(who[row], who[good]);
    for (int i = (row + 1); i < (n); i++)
      if (mat[i][j]) mat[i] ^= mat[row], who[i] ^= who[row];
    row++;
  }
  vector<bool> can(M);
  vector<vector<int>> res;
  for (int it = (0); it < (50); it++) {
    bitset<M> w;
    bitset<20> b = need;
    for (int i = (row); i < (n); i++)
      if (rng() % 2) {
        w ^= who[i], b ^= mat[i];
      }
    for (int j = (0); j < (20); j++) {
      if (b[j]) {
        int i = col[j];
        assert(i != -1);
        w ^= who[i], b ^= mat[i];
      }
    }
    assert(b == 0);
    int sz = w.count();
    if (!can[sz]) {
      can[sz] = 1;
      res.push_back(vector<int>(0));
      for (int i = (0); i < (n); i++)
        if (w[i]) res.back().push_back(a[i]);
    }
    if (mat.back() == 0) break;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin >> c >> n;
  precalc();
  vector<vector<int>> gs(c + 1);
  for (int i = (1); i < (c + 1); i++) {
    gs[f(i)].push_back(i);
  }
  vector<int> ask;
  for (int i = (1); i < (c + 1); i++)
    if (gs[i].size()) ask.push_back(i);
  vector<int> ans(c + 1);
  cout << ask.size() << " ";
  for (auto i : ask) cout << i << " ";
  cout << endl;
  for (int i : ask) {
    int first;
    cin >> first;
    ans[i] = first;
  }
  int all = ans[1];
  vector<int> lrg = ans;
  for (int i = (1); i < (c + 1); i++) {
    if (!gs[i].size()) continue;
    if (i > 1) lrg[i] ^= all;
    for (int j = 2 * i; j <= c; j += i) lrg[j] ^= (ans[i] ^ all);
  }
  vector<int> exc = lrg;
  for (int i = (c + 1) - 1; i >= (1); i--) {
    if (!gs[i].size()) continue;
    for (int j = 2 * i; j <= c; j += i)
      if (gs[j].size()) exc[i] ^= exc[j];
  }
  vector<int> res;
  vector<vector<vector<int>>> opt;
  for (int i = (1); i < (c + 1); i++) {
    if (!gs[i].size()) continue;
    vector<vector<int>> vec = solve(gs[i], exc[i]);
    if (vec.size() == 1)
      for (int first : vec[0]) res.push_back(first);
    else
      opt.push_back(vec);
  }
  int m = opt.size();
  const int SZ = 50000;
  vector<bitset<SZ>> knapsack(m + 1);
  knapsack[0][0] = 1;
  for (int i = (0); i < (m); i++) {
    for (auto& g : opt[i]) knapsack[i + 1] |= knapsack[i] << (g.size());
  }
  return 0;
  int cur = n - res.size();
  assert(cur < SZ);
  assert(knapsack[m][cur]);
  for (int i = (m)-1; i >= (0); i--) {
    for (auto& g : opt[i])
      if (cur >= g.size() && knapsack[i][cur - g.size()]) {
        cur -= g.size();
        for (int first : g) res.push_back(first);
        break;
      }
  }
  assert(res.size() == n);
  sort(res.begin(), res.end());
  for (int i = (0); i < (n); i++) cout << res[i] << " ";
  cout << endl;
  return 0;
}
