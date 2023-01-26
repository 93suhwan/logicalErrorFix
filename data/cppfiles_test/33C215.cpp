#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  long long int res = 0, k;
  cin >> n;
  vector<long long int> t;
  for (int i = 0; i < n; i++) {
    cin >> k;
    t.push_back(k);
  }
  for (int i = 0; i < n; i++) {
    if (i - 1 >= 0) {
      if (t[i - 1] * t[i] > res) {
        res = t[i - 1] * t[i];
      }
    }
    if (i + 1 < n) {
      if (t[i + 1] * t[i] > res) {
        res = t[i + 1] * t[i];
      }
    }
  }
  cout << res;
}
int main() {
  int t, cont = 0;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
    ;
  }
}
