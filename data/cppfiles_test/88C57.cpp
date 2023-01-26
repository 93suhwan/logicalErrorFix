#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> v(n * m);
    vector<long long> v2(n * m);
    for (long long i = 0; i < (n * m); i++) {
      long long x;
      cin >> x;
      v[i] = x;
      v2[i] = x;
    }
    long long ans = 0;
    sort(v2.begin(), v2.end());
    vector<vector<long long>> c(n, vector<long long>(m, 0));
    unordered_map<long long, long long> mp;
    unordered_map<long long, long long> mp2;
    unordered_map<long long, long long> mp3;
    for (long long i = 0; i < (n * m); i++) {
      mp[v2[i]] = i;
      mp2[v2[i]]++;
    }
    for (long long i = (n * m) - 1; i >= 0; i--) {
      mp3[v2[i]] = i;
    }
    for (long long i = 0; i < (n * m); i++) {
      long long x = v[i];
      if (mp2[x] > 1) {
        long long z = mp[x];
        long long z2 = mp3[x];
        long long ch = z / m;
        long long y = z % m;
        long long ch2 = z2 / m;
        long long y2 = z2 % m;
        if (ch == ch2) {
          mp[x] = z - 1;
          mp2[x]--;
          for (long long j = 0; j < y; j++) {
            if (c[ch][j] == 1) {
              ans++;
            }
          }
          c[ch][y] = 1;
        } else {
          for (long long j = 0; j < y2; j++) {
            if (c[ch2][j] == 1 && v2[ch2 * m + j] != x) {
              ans++;
            }
          }
          mp2[x]--;
          mp3[x]++;
        }
      } else {
        long long z = mp[x];
        long long ch = z / m;
        long long y = z % m;
        for (long long j = 0; j < y; j++) {
          if (c[ch][j] == 1) {
            ans++;
          }
        }
        c[ch][y] = 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
