#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = (1 << 23) - 1;
int n, m, cntseg;
int fa[20000000];
map<pair<long long, long long>, int> segid;
map<long long, int> lg;
int root(int x) { return fa[x] = (fa[x] == x ? x : root(fa[x])); }
void merge(int u, int v) { fa[root(u)] = root(v); }
set<pair<long long, long long> > alive;
set<pair<pair<long long, long long>, int> > alive2;
vector<pair<long long, long long> > segs;
void get(long long A, long long B, long long L = 0, long long R = 1ll << n) {
  if (R <= B && L >= A) {
    segs.push_back(make_pair(L, R - 1));
    return;
  }
  if (R <= A || L >= B) return;
  long long mid = (L + R) >> 1;
  get(A, B, L, mid);
  get(A, B, mid, R);
}
void add(long long l, long long r) {
  alive.insert(make_pair(l, r));
  segid[make_pair(l, r)] = ++cntseg;
  auto ite2 = alive2.lower_bound(make_pair(make_pair(r + 1, 0), 0));
  if (ite2 != alive2.begin() && prev(ite2)->first.first <= l &&
      prev(ite2)->first.second >= r)
    merge(cntseg, prev(ite2)->second);
  else
    alive2.insert(make_pair(make_pair(l, r), cntseg));
  int now = cntseg;
  int d_ = lg[r - l + 1];
  for (int d = d_; d <= n - 1; ++d) {
    l ^= 1ll << d;
    r ^= 1ll << d;
    auto ite = alive.lower_bound(make_pair(r + 1, 0));
    bool z = 0;
    if (ite != alive.begin()) {
      --ite;
      if (ite->first <= l && ite->second >= r) {
        merge(now, segid[*ite]);
        z = 1;
      }
      ite++;
    }
    if (!z && ite != alive.begin() && prev(ite)->second >= l) {
      auto ite3 = alive2.lower_bound(make_pair(make_pair(r + 1, 0), 0));
      if (ite3 != alive2.begin() && prev(ite3)->first.first <= l &&
          prev(ite3)->first.second >= r)
        merge(cntseg, prev(ite3)->second);
      else {
        auto ite = alive2.lower_bound(make_pair(make_pair(l, 0), 0));
        while (ite != alive2.end()) {
          if (ite->first.first > r) break;
          merge(cntseg, ite->second);
          ite = alive2.erase(ite);
        }
        alive2.insert(make_pair(make_pair(l, r), cntseg));
      }
    }
    l ^= 1ll << d;
    r ^= 1ll << d;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  vector<pair<string, pair<long long, long long> > > op;
  vector<int> ans;
  map<long long, int> lp;
  for (int i = 0; i < 60; ++i) lg[1ll << i] = i;
  lp[0] = 1;
  int cnt_ask = 0;
  for (int i = 1; i <= m; ++i) {
    string s;
    long long l, r;
    cin >> s;
    scanf("%lld%lld", &l, &r);
    op.push_back(make_pair(s, make_pair(l, r)));
    cnt_ask += (s[0] == 'a');
    if (s == "block") lp[l] = lp[r + 1] = 1;
  }
  if (cnt_ask == 0) {
    return 0;
  }
  if (cnt_ask == 1 && op[0].first == "ask") {
    cout << 1 << endl;
    return 0;
  }
  lp[1ll << n] = 1;
  for (auto ite = lp.begin(); next(ite) != lp.end(); ite++) {
    segs.clear();
    get(ite->first, next(ite)->first);
    for (auto it : segs) alive.insert(it);
  }
  for (int i = 0; i < 20000000; ++i) fa[i] = i;
  reverse(op.begin(), op.end());
  for (auto it : op) {
    if (it.first == "block") {
      segs.clear();
      get(it.second.first, it.second.second + 1);
      for (auto it : segs) alive.erase(it);
    }
  }
  vector<pair<long long, long long> > Tmp;
  for (auto ite = alive.begin(); ite != alive.end(); ite++) Tmp.push_back(*ite);
  alive.clear();
  for (auto it : Tmp) {
    add(it.first, it.second);
  }
  for (auto it : op) {
    if (it.first == "ask") {
      long long a, b;
      a = it.second.first;
      b = it.second.second;
      auto itea = alive.lower_bound(make_pair(a + 1, 0));
      itea--;
      auto iteb = alive.lower_bound(make_pair(b + 1, 0));
      iteb--;
      ans.push_back(root(segid[*itea]) == root(segid[*iteb]));
    }
    if (it.first == "block") {
      segs.clear();
      get(it.second.first, it.second.second + 1);
      for (auto it : segs) add(it.first, it.second);
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto it : ans) {
    printf("%d\n", it);
  }
  return 0;
}
