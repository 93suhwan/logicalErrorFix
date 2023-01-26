#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
void f_io() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  cout.tie(nullptr);
}
ll MOD = 998244353;
const ll INF = (1e18 + 10);
ll gc(ll a, ll b) {
  if (!a || !b) {
    return max(a, b);
  }
  assert(b != 0);
  ll r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}
inline ll mult(ll a, ll b) { return (a * 1LL * b) % MOD; }
inline ll add(ll a, ll b) {
  b = (b % MOD + MOD) % MOD;
  return (a + b) % MOD;
}
ll pw(ll a, ll b) {
  if (b < 0) {
    return 1;
  }
  ll r = 1;
  while (b) {
    if (b & 1) {
      r = (a * r) % MOD;
    }
    b >>= 1;
    a = (a * a) % MOD;
  }
  return r;
}
const ll MAX = 1e6 + 7;
int n, tim = 0, latest[MAX], cnt[MAX], curn = -1, su[MAX], wh[MAX], curc = 0;
vector<pair<int, int>> fin[MAX];
pair<int, int> ra[MAX];
void insert(int x) {
  int p = cnt[x]++;
  if (p == 0) {
    curn++;
    wh[curn] = 1;
    ra[1].second++;
  } else {
    su[p]--;
    int x = ra[p].first;
    wh[x] = p + 1;
    ra[p].first++;
    ra[p + 1].second = ra[p].first;
  }
  tim++;
  fin[p + 1].push_back(make_pair(x, tim));
  latest[x] = tim;
}
void remove(int x) {
  int p = --cnt[x];
  ra[p + 1].second--;
  if (p) {
    su[p]++;
    ra[p].first = ra[p + 1].second;
    wh[ra[p + 1].second] = p;
  } else {
    curn--;
  }
  tim++;
  latest[x] = tim;
}
int extract(int n) {
  while (fin[n].size()) {
    pair<int, int> p = fin[n].back();
    if (latest[p.first] == p.second) {
      break;
    }
    fin[n].pop_back();
  }
  if (fin[n].size() == 0) {
    return -1;
  }
  return fin[n].back().first;
}
vector<int> gr[MAX], ind[MAX];
vector<pair<int, int>> qq[MAX];
int a[MAX], sol[MAX];
vector<int> ve;
void dfs(int n) {
  insert(a[n]);
  ve.push_back(a[n]);
  for (int i = 0; i < qq[n].size(); ++i) {
    int l = qq[n][i].first, k = qq[n][i].second;
    int x = (l > 1 ? k + curn + 1 + su[l - 1] : k), an = -1;
    if (x - 1 <= curn) {
      an = extract(wh[curn - x + 1]);
    }
    sol[ind[n][i]] = an;
  }
  for (int x : gr[n]) {
    dfs(x);
  }
  ve.pop_back();
  remove(a[n]);
}
void ini(int n) {
  tim = 0;
  curn = -1;
  for (int i = 0; i <= n; ++i) {
    gr[i].clear();
    qq[i].clear();
    ind[i].clear();
    fin[i].clear();
    ra[i] = make_pair(0, 0);
    su[i] = 0;
  }
}
int main() {
  f_io();
  ll t = 1;
  cin >> t;
  while (t--) {
    ll q;
    cin >> n >> q;
    ini(n);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
      int p;
      cin >> p;
      gr[p].push_back(i);
    }
    for (int i = 0; i < q; ++i) {
      int v, l, k;
      cin >> v >> l >> k;
      ind[v].push_back(i);
      qq[v].push_back(make_pair(l, k));
    }
    dfs(1);
    for (int i = 0; i < q; ++i) {
      cout << sol[i] << " ";
    }
    cout << "\n";
  }
}
