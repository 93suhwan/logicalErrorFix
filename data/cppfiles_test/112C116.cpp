#include <bits/stdc++.h>
template <typename T>
using vc = std::vector<T>;
template <class T>
using vc = std::vector<T>;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using ll = long long;
using namespace std;
const int MOD = 1000000007;
void inline preCampute() {}
void solve() {
  int m;
  int a[3];
  cin >> a[0] >> a[1] >> a[2] >> m;
  sort(a, a + 3);
  cout << (m >= a[2] - a[0] - a[1] - 1 && m <= a[0] + a[1] + a[2] - 3 ? "YES\n"
                                                                      : "NO\n");
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  preCampute();
  int ctc = 1;
  cout << "\n\n";
  cin >> ctc;
  while (ctc--) {
    solve();
  }
}
