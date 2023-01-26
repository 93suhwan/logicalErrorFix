#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10, inf = 0x3f3f3f3f, llinf = 0x3f3f3f3f3f3f3f3f;
const int M = 2e7 + 5;
long long n, m, k;
long long a, b;
void solve() {
  cin >> a >> b;
  long long x1 = (a + b + 1) / 2;
  long long x2 = (a + b) / 2;
  vector<long long> vec;
  for (int x = 0; x <= x2; ++x) {
    int y = x - a + x1;
    if (y <= x1 && y >= 0 && x >= 0) {
      vec.push_back(x + y);
    }
  }
  swap(x1, x2);
  for (int x = 0; x <= x2; ++x) {
    int y = x - a + x1;
    if (y <= x1 && y >= 0 && x >= 0) {
      vec.push_back(x + y);
    }
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  cout << vec.size() << '\n';
  for (long long v : vec) {
    cout << v << " ";
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
