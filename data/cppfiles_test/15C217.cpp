#include <bits/stdc++.h>
using namespace std;
long long a, b, c[200][100], d[200][100], n, m = -1, k, h, l, r, t, kk, hr;
long long ans, sum, mxx[200200], mnn[200200], mn = 1e9, mx = -1e9, ans2;
string second[50], ss, sc;
bool was[200200], ch;
vector<int> v, vv;
vector<pair<int, int> > vp;
deque<int> de;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        c[i][j] = 0;
      }
      if (ch) break;
    }
    for (int i = 0; i < n; i++) {
      cin >> second[i];
    }
    for (int i = k; i < n; i++) {
      for (int j = k; j < m - k; j++) {
        if (second[i][j] == '*') {
          int l = 1;
          h = 0;
          while (1) {
            if (i - l >= 0 && j - l >= 0 && j + l < m &&
                second[i - l][j - l] == '*' && second[i - l][j + l] == '*') {
              h++;
            } else
              break;
            l++;
          }
          l = 1;
          if (h >= k) {
            while (1) {
              if (i - l >= 0 && j - l >= 0 && j + l < m &&
                  second[i - l][j - l] == '*' && second[i - l][j + l] == '*') {
                c[i - l][j - l] = 1;
                c[i - l][j + l] = 1;
                c[i][j] = 1;
              } else
                break;
              l++;
            }
          }
        }
      }
    }
    ch = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (second[i][j] == '*' && c[i][j] != 1) {
          ch = 1;
          break;
        }
      }
      if (ch) break;
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        c[i][j] = 0;
      }
      if (ch) break;
    }
    if (ch)
      cout << "NO\n";
    else
      cout << "YES\n";
    ch = 0;
  }
  return 0;
}
