#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
mt19937 mt(736);
void solve_test(istream &cin = std::cin, ostream &cout = std::cout) {
  int n, s;
  cin >> n >> s;
  auto q = (n + 2) / 2;
  cout << s / q << endl;
}
void solve(istream &cin = std::cin, ostream &cout = std::cout) {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve_test(cin, cout);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed;
  solve();
  return 0;
}
