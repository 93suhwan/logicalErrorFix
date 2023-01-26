#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  int n;
  for (int tt = 0; tt < t; ++tt) {
    cin >> n;
    std::vector<int> a(n);
    for (int ii = 0; ii < n; ++ii) {
      cin >> a[ii];
    }
    int answ = a[0];
    for (int ii = 1; ii < n; ++ii) {
      answ = answ & a[ii];
    }
    cout << answ << endl;
  }
  return 0;
}
