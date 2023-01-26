#include <bits/stdc++.h>
using namespace std;
int n, m1, m2;
struct ans {
  int s, y;
};
vector<ans> vec;
const int maxn = 1300;
int f[2 * maxn];
int find(int x) {
  if (f[x] == x) return x;
  return f[x] = find(f[x]);
}
bool is_com(int a, int b) {
  if (find(a) != find(b)) return true;
  return false;
}
void combine(int a, int b) {
  int fa, fb;
  fa = find(a);
  fb = find(b);
  f[fa] = fb;
}
int head[maxn];
void solve() {
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) {
    f[i] = i;
    f[i + n] = i + n;
  }
  int a, b;
  for (int i = 0; i < m1; i++) {
    cin >> a >> b;
    combine(a, b);
  }
  for (int i = 0; i < m2; i++) {
    cin >> a >> b;
    combine(n + a, n + b);
  }
  for (int i = 1; i <= n; i++) {
    for (int u = 1; u <= n; u++) {
      if (is_com(i, u) && is_com(i + n, u + n)) {
        ans anw;
        anw.s = i;
        anw.y = u;
        combine(i, u);
        combine(i + n, u + n);
        vec.push_back(anw);
      }
    }
  }
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i].s << " " << vec[i].y << endl;
  }
}
int main() { solve(); }
