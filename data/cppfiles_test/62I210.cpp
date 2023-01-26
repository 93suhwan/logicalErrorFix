#include <bits/stdc++.h>
using namespace std;
const long long INF64 = (long long)(1e18) + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long q = 1, i, j, test;
  cin >> q;
  for (test = 1; test < (q + 1); test++) {
    long long n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < (n); i++) cin >> v[i];
    for (i = 0; i < (n); i++) {
      if (v[i] == 0) cnt++;
    }
    if (cnt == n) {
      cout << -1 << '\n';
      continue;
    }
    bool flag = true;
    for (i = 0; i < n; i++) {
      if ((v[i] == 1) && flag) {
        cout << n + 1 << " ";
        flag = false;
      }
      cout << i + 1 << " ";
    }
    cout << '\n';
  }
}
