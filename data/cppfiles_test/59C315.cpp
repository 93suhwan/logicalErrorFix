#include <bits/stdc++.h>
using namespace std;
const long long N = 5e4 + 100;
long long n;
vector<long long> v[N], p, q;
map<long long, long long> mp;
signed main() {
  long long T = 1;
  cin >> T;
  while (T--) {
    cin >> n;
    for (long long i = 0; i < n; i++) v[i].clear();
    for (long long i = 0; i < n; i++) {
      long long x;
      for (long long j = 0; j < 5; j++) {
        cin >> x;
        v[i].push_back(x);
      }
    }
    long long F = 0;
    for (long long i = 0; i < 5; i++) {
      for (long long j = i + 1; j < 5; j++) {
        long long s1 = 0, s2 = 0, s = 0;
        for (long long k = 0; k < n; k++) {
          if (v[k][i] == 1 && v[k][j] == 0) s1++;
          if (v[k][i] == 0 && v[k][j] == 1) s2++;
          if (v[k][i] == 1 && v[k][j] == 1) s++;
        }
        if (s1 + s2 + s == n && s1 <= n / 2 && s2 <= n / 2) {
          F = 1;
          break;
        }
      }
      if (F) break;
    }
    if (F)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}
