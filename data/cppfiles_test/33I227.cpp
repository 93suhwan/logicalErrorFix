#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  long long int res = 0, sum = 0, k;
  cin >> n;
  vector<long long int> t;
  vector<long long int> test;
  for (int i = 0; i < n; i++) {
    cin >> k;
    t.push_back(k);
    test.push_back(k);
  }
  sort(test.begin(), test.end());
  for (int i = 0; i < n; i++) {
    if (t[i] == test[test.size() - 1]) {
      if (i - 1 >= 0) {
        res = t[i] * t[i - 1];
      }
      if (i + 1 < n) {
        if (t[i] * t[i + 1] > res) {
          res = t[i] * t[i + 1];
        }
      }
      break;
    }
  }
  cout << res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
