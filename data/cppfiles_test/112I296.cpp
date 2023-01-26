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
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  int mx = max(a, max(b, c));
  int sum = a + b + c;
  if (mx >= sum || m >= mx || sum - mx < mx) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
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
