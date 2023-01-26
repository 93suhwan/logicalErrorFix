#include <bits/stdc++.h>
using namespace std;
void FAST_IO(string filein = "", string fileout = "", string fileerr = "") {
  if (fopen(filein.c_str(), "r")) {
    freopen(filein.c_str(), "r", stdin);
    freopen(fileout.c_str(), "w", stdout);
  }
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
}
void Hollwo_Pelw();
signed main() {
  FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
  int testcases = 1;
  for (int test = 1; test <= testcases; test++) {
    Hollwo_Pelw();
  }
  return 0;
}
long long n, m;
vector<long long> a[10];
struct node {
  long long p[10], tot;
  node() { memset(p, 0, sizeof p), tot = 0; }
};
bool operator<(const node &a, const node &o) { return a.tot < o.tot; }
set<node> ban, used;
priority_queue<node> pq;
void Hollwo_Pelw() {
  cin >> n;
  for (long long i = 0, c; i < n; i++) {
    cin >> c, a[i].resize(c);
    for (auto &v : a[i]) cin >> v;
  }
  for (cin >> m; m--;) {
    node cur;
    for (long long i = 0; i < n; i++) cin >> cur.p[i], cur.p[i]--;
    for (long long i = 0; i < n; i++) cur.tot += a[i][cur.p[i]];
    ban.insert(cur);
  }
  node cur;
  for (long long i = 0; i < n; i++)
    cur.p[i] = a[i].size() - 1, cur.tot += a[i].back();
  pq.push(cur);
  while (!pq.empty()) {
    node cur = pq.top();
    pq.pop();
    if (!ban.count(cur)) {
      for (long long i = 0; i < n; i++) cout << cur.p[i] + 1 << ' ';
      return;
    }
    for (long long i = 0; i < n; i++)
      if (cur.p[i]) {
        node nxt = cur;
        nxt.tot += a[i][cur.p[i] - 1] - a[i][cur.p[i]];
        nxt.p[i]--;
        if (!used.count(nxt)) pq.push(nxt), used.insert(nxt);
      }
  }
}
