#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
void prec() {}
void solve(istream &cin, ostream &cout) {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int x = 0, y = 0;
  int minx = 0, maxx = 0, miny = 0, maxy = 0;
  int sx = 0, sy = 0;
  for (char c : s) {
    if (c == 'L') y--;
    if (c == 'R') y++;
    if (c == 'U') x--;
    if (c == 'D') x++;
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
    if (maxx - minx < n && maxy - miny < m) {
      sx = -minx;
      sy = -miny;
    }
  }
  sx++;
  sy++;
  cout << sx << ' ' << sy << '\n';
}
struct ERobotOnTheBoard1 {
  int case_num = 0;
  void solve(std::istream &in, std::ostream &out) { ::solve(in, out); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  prec();
  ERobotOnTheBoard1 solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  int n;
  in >> n;
  for (int i = 0; i < n; ++i) {
    solver.solve(in, out);
  }
  return 0;
}
