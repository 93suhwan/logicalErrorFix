#include <bits/stdc++.h>
using namespace std;
using str = string;
using ll = long long;
using ld = long double;
template <typename T>
using vec = vector<T>;
template <typename A, typename B>
using pr = pair<A, B>;
struct Solver {
  void run() {
    ll n;
    cin >> n;
    ll count = 1;
    for (int i = 3; i <= 2 * n; i++) count = (count * i) % 1000000007;
    cout << count << '\n';
  }
};
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
int main() {
  boost();
  int t = 1;
  cin >> t;
  while (t--) {
    Solver s;
    s.run();
  }
}
