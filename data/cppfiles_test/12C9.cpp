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
template <bool reverseX = false>
struct CHT {
  vector<line> lines;
  vector<long long> ints;
  void add(const line& l) {
    while (lines.size() >= 2) {
      double xl = inters(lines[((int)(lines).size()) - 2],
                         lines[((int)(lines).size()) - 1]);
      double xr = inters(lines[((int)(lines).size()) - 1], l);
      if ((xl > xr && !reverseX) || (xl < xr && reverseX))
        lines.pop_back();
      else
        break;
    }
    ints.resize(lines.size());
    ints.push_back(((int)(ints).size()));
    lines.push_back(l);
  }
  long long rq(long long x) {
    assert(!lines.empty());
    auto it = *lower_bound(ints.begin(), ints.end() - 1, x,
                           [this](long long id, long long x) {
                             if (!reverseX)
                               return inters(lines[id], lines[id + 1]) < x;
                             else
                               return inters(lines[id], lines[id + 1]) > x;
                           });
    return lines[it].f(x);
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
    CHT<false> cht1;
    for (int j = 0; j < m; j++) {
      if (field[i][j]) cht1.add({-2 * j, j * j});
      if (!cht1.lines.empty()) {
        sx[i][j] = min(sx[i][j], (int)(cht1.rq(j) + j * j));
      }
    }
    CHT<true> cht2;
    for (int j = m - 1; j >= 0; j--) {
      if (field[i][j]) cht2.add({-2 * j, j * j});
      if (!cht2.lines.empty()) {
        sx[i][j] = min(sx[i][j], (int)(cht2.rq(j) + j * j));
      }
    }
  }
  for (int j = 0; j < m; j++) {
    CHT<false> cht1;
    for (int i = 0; i < n; i++) {
      if (sx[i][j] < INFi) cht1.add({-2 * i, i * i + sx[i][j]});
      if (!cht1.lines.empty()) {
        sy[i][j] = min(sy[i][j], (int)(cht1.rq(i) + i * i));
      }
    }
    CHT<true> cht2;
    for (int i = n - 1; i >= 0; i--) {
      if (sx[i][j] < INFi) cht2.add({-2 * i, i * i + sx[i][j]});
      if (!cht2.lines.empty()) {
        sy[i][j] = min(sy[i][j], (int)(cht2.rq(i) + i * i));
      }
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
