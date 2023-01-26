#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")
using namespace std;
const long long mxn = 2e5 + 10;
long long pri(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    std::vector<long long> ans1;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long x = s[i] - '0';
      if (pri(x) == 0 || x == 1) {
        cout << 1 << "\n";
        cout << x << "\n";
        ans++;
        break;
      }
      ans1.push_back(x);
    }
    if (!ans) {
      cout << 2 << "\n";
      for (long long i = 0; i < ans1.size(); i++) {
        if (ans1[i] == 2) {
          for (long long j = i + 1; j < ans1.size(); j++) {
            if (ans1[j] == 5 || ans1[j] == 7 || ans1[j] == 2) {
              ans++;
              cout << ans1[i] << ans1[j] << "\n";
              break;
            }
          }
          if (ans) break;
        } else if (ans1[i] == 3) {
          for (long long j = i + 1; j < ans1.size(); j++) {
            if (ans1[j] == 5 || ans1[j] == 7 || ans1[j] == 9 || ans1[j] == 3) {
              ans++;
              cout << ans1[i] << ans1[j] << "\n";
              break;
            }
          }
          if (ans) break;
        } else if (ans1[i] == 5) {
          for (long long j = i + 1; j < ans1.size(); j++) {
            if (ans1[j] == 5 || ans1[j] == 7) {
              ans++;
              cout << ans1[i] << ans1[j] << "\n";
              break;
            }
          }
          if (ans) break;
        } else if (ans1[i] == 7) {
          for (long long j = i + 1; j < ans1.size(); j++) {
            if (ans1[j] == 9 || ans1[j] == 7) {
              ans++;
              cout << ans1[i] << ans1[j] << "\n";
              break;
            }
          }
          if (ans) break;
        }
      }
    }
  }
}
