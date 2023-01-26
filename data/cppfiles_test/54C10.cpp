#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<double, double>;
const int N = (int)2e5 + 5;
const int M = (int)1e5 + 5;
const ll mod = 1e9 + 7, mod2 = 1e9 + 9;
const ull base = 131;
const double pi = acos(-1.0);
int _, CNT = -1;
int n, m, ans;
int fa[N * 2], size[N * 2], sum[N * 2];
bool vis[N * 2];
int get(int a) {
  if (fa[a] == a) return a;
  return fa[a] = get(fa[a]);
}
void link(int a, int b) {
  int r1 = get(a), r2 = get(b);
  if (r1 == r2) return;
  fa[r1] = r2;
  size[r2] += size[r1];
  sum[r2] += sum[r1];
}
void work(std::istream& in, std::ostream& out) {
  ans = 0;
  in >> n >> m;
  for (int i = 1; i <= 2 * n; i++) vis[i] = false;
  for (int i = 1; i <= 2 * n; i++) {
    fa[i] = i;
    size[i] = (i <= n);
    sum[i] = 1;
  }
  int flag = 1;
  for (int i = 1, a, b; i <= m; i++) {
    string c;
    in >> a >> b >> c;
    if (c == "imposter") {
      if (get(a) == get(b) || get(a + n) == get(b + n)) {
        flag = 0;
      } else {
        link(a, b + n);
        link(a + n, b);
      }
    } else {
      if (get(a) == get(b + n) || get(a + n) == get(b)) {
        flag = 0;
      } else {
        link(a, b);
        link(a + n, b + n);
      }
    }
  }
  if (!flag) {
    out << -1 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++)
    if (!vis[get(i)]) {
      vis[get(i)] = vis[get(i + n)] = true;
      ans += max(size[get(i)], sum[get(i)] - size[get(i)]);
    }
  out << ans << '\n';
}
class TaskD {
 public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    _ = 1;
    in >> _;
    while (_--) {
      work(in, out);
    }
  }
};
int main() {
  TaskD solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
