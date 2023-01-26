#include <bits/stdc++.h>
using namespace std;
const int N = 1100000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const double eps = 1e-9;
int n, q, a[N], f[N];
vector<int> g[N], h[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) f[fx] = fy;
}
int ys[N];
const int maxsz = 2e7 + 3;
template <typename key, typename val>
class hash_map {
 public:
  struct node {
    key u;
    val v;
    int next;
  };
  vector<node> e;
  int head[maxsz], nume, numk, id[maxsz];
  bool count(key u) {
    int hs = (u % maxsz + maxsz) % maxsz;
    for (int i = head[hs]; i; i = e[i].next)
      if (e[i].u == u) return 1;
    return 0;
  }
  val& operator[](key u) {
    int hs = (u % maxsz + maxsz) % maxsz;
    for (int i = head[hs]; i; i = e[i].next)
      if (e[i].u == u) return e[i].v;
    if (!head[hs]) id[++numk] = hs;
    if (++nume >= e.size()) e.resize(nume << 1);
    return e[nume] = (node){u, 0, head[hs]}, head[hs] = nume, e[nume].v;
  }
  void clear() {
    for (int i = 0; i <= numk; i++) head[id[i]] = 0;
    numk = nume = 0;
    e.clear();
  }
};
hash_map<long long, int> rec;
long long cal(int x, int y) { return (x - 1) * n + y - 1; }
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i] = i;
    int x = a[i];
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        g[i].push_back(j), h[j].push_back(i);
        while (x % j == 0) x /= j;
      }
    }
    if (x > 1) g[i].push_back(x), h[x].push_back(i);
  }
  for (int i = 2; i < N; i++) {
    if (h[i].size() > 1) {
      for (int j = 1; j < h[i].size(); j++) merge(h[i][0], h[i][j]);
    }
  }
  for (int i = 2; i < N; i++) {
    if (h[i].size() > 0) ys[i] = find(h[i][0]);
  }
  for (int i = 1; i <= n; i++) {
    long long x = a[i];
    vector<int> tmp;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        tmp.push_back(j);
        while (x % j == 0) x /= j;
      }
    }
    if (x > 1) tmp.push_back(x);
    x = a[i] + 1;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        tmp.push_back(j);
        while (x % j == 0) x /= j;
      }
    }
    if (x > 1) tmp.push_back(x);
    for (int j = 0; j < tmp.size(); j++)
      if (ys[tmp[j]]) {
        for (int k = j + 1; k < tmp.size(); k++)
          if (ys[tmp[k]]) {
            rec[cal(ys[tmp[j]], ys[tmp[k]])] = 1;
            rec[cal(ys[tmp[k]], ys[tmp[j]])] = 1;
          }
      }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (find(x) == find(y))
      cout << 0 << "\n";
    else if (rec.count(cal(find(x), find(y))))
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
  return 0;
}
