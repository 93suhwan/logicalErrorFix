#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (auto &x : v) {
    cin >> x;
  };
  long long int h = *max_element(v.begin(), v.end());
  long long int s = -1;
  for (auto &x : v) {
    if (x > s && x < h) {
      s = x;
    }
  }
  long long int ch = 0;
  long long int cs = 0;
  long long int j = 0;
  long long int i = 0;
  for (auto &x : v) {
    if (x == h) {
      ch = 1;
    }
    if (x == s) {
      cs = 1;
    }
    if (ch) {
      i++;
    }
    if (cs) {
      j++;
    }
  }
  cout << min(i - 1, j) << '\n';
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
