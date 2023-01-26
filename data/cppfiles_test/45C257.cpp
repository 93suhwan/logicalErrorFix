#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (auto &x : v) {
    cin >> x;
  };
  long long int len = 1;
  len += v[0];
  for (long long int i = 1; i < n; i++) {
    if (v[i] == 0 && v[i - 1] == 0) {
      len = -1;
      break;
    }
    if (v[i] > 0 && v[i - 1] > 0) {
      len += 5;
    } else if (v[i] > 0) {
      len++;
    }
  }
  cout << len << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int _ = 0;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
