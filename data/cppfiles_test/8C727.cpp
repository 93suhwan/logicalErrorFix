#include <bits/stdc++.h>
using namespace std;
template <typename T>
void emilia_mata_tenshi(const char *s, T l, T r) {
  cerr << "\e[1;33m" << s << " = [";
  while (l != r) {
    cerr << *l;
    cerr << (++l == r ? ']' : ',');
  }
  cerr << "\e[0m\n";
}
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS = 1e-8;
const int INF = 0x3F3F3F3F;
const ll LINF = 4611686018427387903;
const int MOD = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int g = n % 3;
    if (g <= 1)
      cout << (n / 3 + g) << ' ' << (n / 3) << '\n';
    else
      cout << (n / 3 + n % 3 - 2) << ' ' << (n / 3 + 1) << '\n';
  }
}
