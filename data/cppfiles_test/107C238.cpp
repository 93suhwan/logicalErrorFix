#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  if ((abs(a - b) > 1) || (a + b > n - 2)) {
    cout << "-1\n";
    return;
  }
  vector<long long> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  if (a > b) {
    for (int i = n - 1; i > 0, a > 0; i -= 2) {
      swap(v[i], v[i - 1]);
      a--;
    }
  } else if (b > a) {
    for (int i = 0; i<n - 1, b> 0; i += 2) {
      swap(v[i], v[i + 1]);
      b--;
    }
  } else {
    for (int i = 1; i<n - 1, a> 0; i += 2) {
      swap(v[i], v[i + 1]);
      a--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  for (; t--;) {
    solve();
  }
  return 0;
}
