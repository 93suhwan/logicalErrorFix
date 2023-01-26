#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pd = pair<double, double>;
using pld = pair<ld, ld>;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int occ[26]{};
    for (const char chr : s) {
      ++occ[chr - 'a'];
    }
    int nr_red{}, nr_green{};
    for (int chr = 0; chr < 26; ++chr) {
      if (occ[chr] == 0) {
        continue;
      }
      if (occ[chr] >= 2) {
        ++nr_red, ++nr_green;
      } else if (nr_red > nr_green) {
        ++nr_green;
      } else {
        ++nr_red;
      }
    }
    cout << min(nr_red, nr_green) << '\n';
  }
}
