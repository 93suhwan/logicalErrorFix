#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n * m);
    vector<int> v2(n * m);
    for (int i = 0; i < (n * m); i++) {
      int x;
      cin >> x;
      v[i] = x;
      v2[i] = x;
    }
    int ans = 0;
    sort(v2.begin(), v2.end());
    vector<vector<int>> c(n, vector<int>(m, 0));
    unordered_map<int, int> mp;
    unordered_map<int, int> mp2;
    unordered_map<int, int> mp3;
    for (int i = 0; i < (n * m); i++) {
      mp[v2[i]] = i;
      mp2[v2[i]]++;
    }
    for (int i = (n * m) - 1; i >= 0; i--) {
      mp3[v2[i]] = i;
    }
    for (int i = 0; i < (n * m); i++) {
      int x = v[i];
      if (mp2[x] > 1) {
        int z = mp[x];
        int z2 = mp3[x];
        int ch = z / m;
        int y = z % m;
        int ch2 = z2 / m;
        int y2 = z2 % m;
        if (ch == ch2) {
          mp[x] = z - 1;
          mp2[x]--;
          for (int j = 0; j < y; j++) {
            if (c[ch][j] == 1) {
              ans++;
            }
          }
          c[ch][y] = 1;
        } else {
          for (int j = 0; j < y2; j++) {
            if (c[ch2][j] == 1 && v[ch2 * m + j] != x) {
              ans++;
            }
          }
          mp2[x]--;
          mp3[x]++;
        }
      } else {
        int z = mp[x];
        int ch = z / m;
        int y = z % m;
        for (int j = 0; j < y; j++) {
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
