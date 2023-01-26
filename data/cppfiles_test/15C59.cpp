#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    char arr[n][m];
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
        if (arr[i][j] == '*') count++;
      }
    }
    set<pair<int, int>> s;
    set<pair<int, int>> temp;
    for (int i = k; i < n; i++) {
      for (int j = k; j < m - k; j++) {
        if (arr[i][j] == '*') {
          int l = 0;
          int c = 0;
          int f = 0;
          temp.clear();
          while ((i - c >= 0) and (j - c >= 0) and (i - c < n) and
                 (j + c < m) and f == 0) {
            if (arr[i - c][j - c] != arr[i - c][j + c] ||
                arr[i - c][j + c] == '.')
              f = 1;
            if (f == 0) {
              temp.insert({i - c, j - c});
              temp.insert({i - c, j + c});
              l++;
              c++;
            }
          }
          if (l - 1 >= k) {
            s.insert(temp.begin(), temp.end());
          }
        }
      }
    }
    if (s.size() == count)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
