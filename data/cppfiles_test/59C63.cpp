#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<long long>> v;
    for (long long i = 0; i < n; i++) {
      vector<long long> temp;
      for (long long j = 0; j < 5; j++) {
        long long x;
        cin >> x;
        temp.push_back(x);
      }
      v.push_back(temp);
      temp.clear();
    }
    long long ans1 = 0;
    long long ans2 = 0;
    long long ans = 0;
    for (long long j = 0; j < 5; j++) {
      for (long long k = j + 1; k < 5; k++) {
        ans = 0;
        ans1 = 0;
        ans2 = 0;
        for (long long i = 0; i < n; i++) {
          if (v[i][j] == 0 && v[i][k] == 0) {
            ans = 1;
            break;
          } else if (v[i][j] == 1 && v[i][k] == 0) {
            ans1++;
          } else if (v[i][j] == 0 && v[i][k] == 1) {
            ans2++;
          }
        }
        if (ans == 0 && ans1 <= (n / 2) && ans2 <= (n / 2)) {
          ans = 2;
          cout << "YES" << endl;
          break;
        }
      }
      if (ans == 2) {
        break;
      }
    }
    if (ans != 2) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
