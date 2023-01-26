#include <bits/stdc++.h>
using namespace std;
void find(int a, int b, vector<int> &x_0, vector<int> &_0_y, vector<int> &x_b,
          vector<int> &a_y) {
  sort(x_0.begin(), x_0.end());
  sort(_0_y.begin(), _0_y.end());
  sort(x_b.begin(), x_b.end());
  sort(a_y.begin(), a_y.end());
  int m1 = x_0.at(x_0.size() - 1) - x_0.at(0);
  int m2 = _0_y.at(_0_y.size() - 1) - _0_y.at(0);
  int m3 = x_b.at(x_b.size() - 1) - x_b.at(0);
  int m4 = a_y.at(a_y.size() - 1) - a_y.at(0);
  int ans = max(max(m1 * b, m2 * a), max(m3 * b, m4 * a));
  cout << ans;
}
int main() {
  int t, k;
  cin >> t;
  while (t--) {
    vector<int> x_0, _0_y, x_b, a_y;
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    while (n--) {
      cin >> k;
      x_0.push_back(k);
    }
    cin >> n;
    while (n--) {
      cin >> k;
      x_b.push_back(k);
    }
    cin >> n;
    while (n--) {
      cin >> k;
      _0_y.push_back(k);
    }
    cin >> n;
    while (n--) {
      cin >> k;
      a_y.push_back(k);
    }
    find(a, b, x_0, _0_y, x_b, a_y);
  }
}
