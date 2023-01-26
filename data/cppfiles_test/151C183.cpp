#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const long long N = 0;
class dsu {
 public:
  vector<long long> parent;
  vector<long long> size;
  vector<long long> rank;
  vector<long long> val;
  explicit dsu(long long a) {
    parent.resize(a);
    size.resize(a);
    rank.resize(a);
    val.resize(a);
    for (long long i = 0; i < a; i++) {
      parent[i] = i;
      size[i] = 1;
      rank[i] = 0;
      val[i] = -1;
    }
  }
  long long par(long long i) {
    if (i == parent[i]) return i;
    return parent[i] = par(parent[i]);
  }
  bool unite(long long a, long long b, long long c) {
    a = par(a);
    b = par(b);
    if (a != b) {
      if (rank[a] > rank[b]) swap(a, b);
      parent[a] = b;
      size[b] += size[a];
      size[a] = 0;
      val[b] = c;
      val[a] = -1;
      if (rank[a] == rank[b]) rank[b]++;
      return true;
    }
    return false;
  }
};
void solve() {
  long long n;
  cin >> n;
  map<long long, long long> mp;
  dsu d(n + 5);
  long long cur = 0;
  long long temp = n;
  while (n--) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long last;
      cin >> last;
      if (!mp.count(last)) {
        mp[last] = cur;
        d.val[cur] = last;
      } else {
        d.unite(cur, mp[last], last);
      }
      cur++;
    } else {
      long long x, y;
      cin >> x >> y;
      if (!mp.count(x)) continue;
      if (!mp.count(y)) {
        mp[y] = mp[x];
        long long par = d.par(mp[y]);
        d.val[par] = y;
      } else {
        long long xx = mp[x];
        long long yy = mp[y];
        d.unite(xx, yy, y);
      }
      if (x != y) mp.erase(x);
    }
  }
  for (long long i = 0; i < cur; i++) {
    long long par = d.par(i);
    cout << d.val[par] << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
