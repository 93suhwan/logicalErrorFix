#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const long long INFll = 4e18;
const long long INFi = 1e9 + 63;
const double pi = acos(-1);
const int maxn = 1e5;
const int maxd = 16;
const long long mod = 1e9 + 7;
const int sqrtN = 300;
int caseNo = 1;
void E() {}
template <class A, class... B>
void E(A $, B... _) {
  cerr << ' ' << $;
  E(_...);
}
int field[2005][2005];
int sx[2005][2005];
int sy[2005][2005];
struct line {
  long long a, b;
  long long f(long long x) const { return a * x + b; }
};
double inters(const line& l, const line& r) {
  return ((double)r.b - l.b) / ((double)l.a - r.a);
}
struct LiChao {
  const static int size = 2005;
  line mas[4 * size];
  LiChao() {
    for (int i = 0; i < 4 * size; i++) {
      mas[i] = {0, INFi};
    }
  }
  void addLine(line newL, int v = 1, int l = 0, int r = size - 1) {
    int m = (l + r) / 2;
    if (newL.f(m) < mas[v].f(m)) {
      swap(newL, mas[v]);
    }
    if (l == r) return;
    if (newL.f(l) < mas[v].f(l)) {
      addLine(newL, 2 * v, l, m);
    } else {
      addLine(newL, 2 * v + 1, m + 1, r);
    }
  }
  long long rq(int x, int v = 1, int l = 0, int r = size - 1) {
    if (l == r) {
      return mas[v].f(x);
    }
    int m = (l + r) / 2;
    if (x <= m) {
      return min(mas[v].f(x), rq(x, 2 * v, l, m));
    } else {
      return min(mas[v].f(x), rq(x, 2 * v + 1, m + 1, r));
    }
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  n++;
  m++;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    assert(((int)(s).size()) == m);
    for (int j = 0; j < m; j++) {
      field[i][j] = s[j] - '0';
      sx[i][j] = sy[i][j] = INFi;
    }
  }
  for (int i = 0; i < n; i++) {
    LiChao cht1;
    for (int j = 0; j < m; j++) {
      if (field[i][j]) cht1.addLine({-2 * j, j * j});
      sx[i][j] = min(sx[i][j], (int)(cht1.rq(j) + j * j));
    }
    LiChao cht2;
    for (int j = m - 1; j >= 0; j--) {
      if (field[i][j]) cht2.addLine({-2 * j, j * j});
      sx[i][j] = min(sx[i][j], (int)(cht2.rq(j) + j * j));
    }
  }
  for (int j = 0; j < m; j++) {
    LiChao cht1;
    for (int i = 0; i < n; i++) {
      if (sx[i][j] < INFi) cht1.addLine({-2 * i, i * i + sx[i][j]});
      sy[i][j] = min(sy[i][j], (int)(cht1.rq(i) + i * i));
    }
    LiChao cht2;
    for (int i = n - 1; i >= 0; i--) {
      if (sx[i][j] < INFi) cht2.addLine({-2 * i, i * i + sx[i][j]});
      sy[i][j] = min(sy[i][j], (int)(cht2.rq(i) + i * i));
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res += sy[i][j];
    }
  }
  cout << res;
}
int main(int argc, char** argv) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  int t = 1;
  clock_t start = clock();
  for (int i = 0; i < t; i++) solve();
  return 0;
}
