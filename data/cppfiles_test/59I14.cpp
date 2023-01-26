#include <bits/stdc++.h>
using namespace std;
string solve() {
  long long n;
  cin >> n;
  long long a[n][5];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  for (long long i = 0; i < 4; i++) {
    set<long long> s;
    long long count = 0;
    for (long long k = 0; k < n; k++) {
      if (a[k][i]) {
        count++;
        s.insert(i);
      }
    }
    if (count < n / 2) continue;
    for (long long j = i + 1; j < 5; j++) {
      long long pre = 0, abs = 0;
      for (long long k = 0; k < n; k++) {
        if (a[k][j]) {
          if (s.find(k) != s.end())
            pre++;
          else
            abs++;
        }
      }
      if (abs + pre < n / 2) continue;
      if (abs >= n / 2) return "YES";
      long long req = n / 2 - abs;
      if (req > pre) return "NO";
      count = count - req;
      if (count >= n / 2) return "YES";
    }
  }
  return "NO";
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) cout << solve() << "\n";
}
