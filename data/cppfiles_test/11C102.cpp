#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  for (int t = (0); t <= ((int)(T)-1); ++t) {
    long long n;
    cin >> n;
    vector<string> W(n);
    for (int i = (0); i <= ((int)(n)-1); ++i) cin >> W[i];
    long long res = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      vector<long long> S(n);
      for (int i = (0); i <= ((int)(n)-1); ++i) {
        S[i] = 2 * (long long)count(W[i].begin(), W[i].end(), c) - W[i].size();
      }
      sort(S.rbegin(), S.rend());
      long long nb = 0, i = 0;
      while (i < n and nb + S[i] > 0) {
        nb += S[i];
        ++i;
      }
      res = max(res, i);
    }
    cout << res << "\n";
  }
  return 0;
}
