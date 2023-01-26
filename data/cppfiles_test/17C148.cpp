#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, k, m, cnt;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    long long ans;
    cnt = 0;
    vector<vector<long long>> v(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        long long x;
        cin >> x;
        v[i].push_back(x);
      }
    }
    for (int i = 1; i < n; i++) {
      ans = 0;
      for (int j = 0; j < 5; j++) {
        if (v[i][j] < v[cnt][j]) {
          ans++;
        }
      }
      if (ans >= 3) {
        cnt = i;
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      ans = 0;
      if (i != cnt) {
        for (int j = 0; j < 5; j++) {
          if (v[cnt][j] < v[i][j]) {
            ans++;
          }
        }
        if (ans < 3) {
          ok = false;
        }
      }
    }
    if (n == 1) {
      cout << 1 << endl;
    } else {
      if (ok) {
        cout << cnt + 1 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
