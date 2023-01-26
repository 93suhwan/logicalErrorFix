#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50, NN = 1005, mod = 1e9 + 7;
void solve() {
  long long n, m, k, nn;
  cin >> n >> m >> k;
  nn = n;
  int r = round((1.0 * n) / m);
  vector<long long> v;
  if ((r * m) >= n) {
    while (n > (r - 1)) {
      v.push_back(r);
      n -= r;
    }
    while (n > 0) {
      v.push_back(r - 1);
      n -= (r - 1);
    }
  } else {
    while (n > r) {
      v.push_back(r - 1);
      n -= (r - 1);
    }
    v.pop_back();
    n += (r - 1);
    while (n > 0) {
      v.push_back(r);
      n -= (r);
    }
  }
  while (k--) {
    int i = 1;
    for (auto item : v) {
      cout << item << " ";
      for (int ij = 0; ij < item; ij++) cout << i << " ", ++i;
      cout << endl;
    }
    reverse(v.begin(), v.end());
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
