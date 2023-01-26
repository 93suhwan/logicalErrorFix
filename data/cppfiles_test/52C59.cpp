#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<double> elements(n);
  for (auto &i : elements) {
    cin >> i;
  }
  double m = *max_element(elements.begin(), elements.end());
  for (auto &i : elements) {
    i /= (n - 1);
  }
  double s = accumulate(elements.begin(), elements.end(), 0.0);
  s -= m / (n - 1);
  std::fixed(cout);
  cout.precision(10);
  cout << (m + s) << endl;
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
