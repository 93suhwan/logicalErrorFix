#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10, inf = 0x3f3f3f3f, llinf = 0x3f3f3f3f3f3f3f3f;
const int M = 2e7 + 5;
long long n, m, k;
long long a, b;
void solve() {
  cin >> a >> b;
  if (a == b) {
    cout << a + 1 << '\n';
    for (int i = 0; i <= a + b; i += 2) {
      cout << i << " ";
    }
    cout << '\n';
    return;
  }
  long long x1 = (a + b + 1) / 2;
  long long x2 = (a + b) / 2;
  long long tx1 = a - x1, tx2 = b - x2;
  if (tx1 < 0) tx1 = 0;
  if (tx2 < 0) tx2 = 0;
  long long hx1 = min(x2, a), hx2 = min(x1, b);
  vector<long long> vec;
  for (int i = 0; i <= a + b; ++i) {
    if (tx2 + tx1 <= i && i <= hx2 + hx1) {
      vec.push_back(i);
    }
  }
  swap(x1, x2);
  tx1 = a - x1, tx2 = b - x2;
  if (tx1 < 0) tx1 = 0;
  if (tx2 < 0) tx2 = 0;
  hx1 = min(x2, a), hx2 = min(x1, b);
  for (int i = 0; i <= a + b; ++i) {
    if (tx2 + tx1 <= i && i <= hx2 + hx1) {
      vec.push_back(i);
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
