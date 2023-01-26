#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B, typename C>
struct triple {
  A X;
  B Y;
  C Z;
  triple(A a = 0, B b = 0, C c = 0) : X(a), Y(b), Z(c) {}
};
template <typename A, typename B, typename C>
triple<A, B, C> make_triple(A a = 0, B b = 0, C c = 0) {
  return triple<A, B, C>(a, b, c);
}
template <typename A, typename B, typename C>
bool operator<(const triple<A, B, C>& a, const triple<A, B, C>& b) {
  if (a.X != b.X) return a.X < b.X;
  if (a.Y != b.Y) return a.Y < b.Y;
  return a.Z < b.Z;
}
template <typename T, typename SS>
ostream& operator<<(ostream& ofs, const pair<T, SS>& p) {
  ofs << "( " << p.first << " , " << p.second << " )";
  return ofs;
}
template <typename T>
void print(T a) {
  for (auto i : a) cout << i << ' ';
  cout << '\n';
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T, typename D>
D min(T a) {
  return *min_element(a.begin(), a.end());
}
template <typename T, typename D>
D max(T a) {
  return *max_element(a.begin(), a.end());
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
vector<int> a;
vector<vector<int> > g;
vector<vector<triple<int, int, int> > > ask;
vector<int> ans;
vector<int> cnt;
int n;
vector<unordered_set<int> > b;
vector<int> tree;
int m;
int sum(int r) {
  int res = 0;
  for (; r > 0; r -= r & -r) res += tree[r];
  return res;
}
int sum(int l, int r) {
  l++;
  r++;
  return sum(r) - sum(l - 1);
}
void add(int k, int x) {
  k++;
  for (; k <= m; k += k & -k) tree[k] += x;
}
int lower_bound(int s) {
  int k = 0;
  for (int l = 20; l >= 0; l--) {
    if (k + (1 << l) <= m && tree[k + (1 << l)] < s) {
      k += (1 << l);
      s -= tree[k];
    }
  }
  return k;
}
void dfs(int v) {
  b[cnt[a[v]]].erase(a[v]);
  add(cnt[a[v]], -1);
  cnt[a[v]]++;
  b[cnt[a[v]]].insert(a[v]);
  add(cnt[a[v]], +1);
  for (auto [l, k, id] : ask[v]) {
    int xd = sum(0, l - 1);
    int z = lower_bound(xd + k);
    if (z != m) ans[id] = *b[z].begin();
  }
  for (int to : g[v]) dfs(to);
  b[cnt[a[v]]].erase(a[v]);
  add(cnt[a[v]], -1);
  cnt[a[v]]--;
  b[cnt[a[v]]].insert(a[v]);
  add(cnt[a[v]], +1);
}
void solve() {
  int q;
  cin >> n >> q;
  a.assign(n, 0);
  for (int i = 0; i < (n); i++) cin >> a[i];
  cnt.assign(n + 1, 0);
  g = vector<vector<int> >(n);
  tree.assign(n + 10, 0);
  m = n + 9;
  for (int i = 0; i < (n - 1); i++) {
    int x;
    cin >> x;
    g[x - 1].push_back(i + 1);
  }
  ans = vector<int>(q, -1);
  ask = vector<vector<triple<int, int, int> > >(n);
  b = vector<unordered_set<int> >(n + 1);
  for (int x : a) b[0].insert(x);
  add(0, (int)(b[0].size()));
  for (int i = 0; i < (q); i++) {
    int v, l, k;
    cin >> v >> l >> k;
    ask[v - 1].push_back(make_triple<int, int, int>(l, k, i));
  }
  dfs(0);
  print(ans);
};
signed main() {
  if (0) {
    freopen(
        "che"
        ".in",
        "r", stdin);
    freopen(
        "che"
        ".out",
        "w", stdout);
  }
  srand(time(NULL));
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  for (int _ = 0; _ < (t); _++) solve();
}
