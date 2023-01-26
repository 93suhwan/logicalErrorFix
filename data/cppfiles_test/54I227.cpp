#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<double, double>;
const int N = (int)3e5 + 5;
const int M = (int)1e5 + 5;
const ll mod = 1e9 + 7, mod2 = 1e9 + 9;
const ull base = 131;
const double pi = acos(-1.0);
int _, CNT = -1;
int n;
char c, s[N];
void work(std::istream& in, std::ostream& out) {
  in >> n >> c;
  in >> s + 1;
  int num = 0;
  for (int i = 1; i <= n; i++) num += (s[i] != c);
  if (!num)
    out << 0 << '\n';
  else {
    if (s[n] == c)
      out << 1 << '\n' << n << '\n';
    else {
      if (num == 1)
        out << 1 << '\n' << n - 1 << '\n';
      else {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
          sum = 0;
          for (int j = i; j <= n; j += i) {
            sum += (s[j] != c);
          }
          if (!sum) {
            out << 1 << '\n';
            out << i << '\n';
            return;
          }
        }
        out << 2 << '\n';
        out << n << " " << n - 1 << '\n';
      }
    }
  }
}
class TaskC {
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
  TaskC solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
