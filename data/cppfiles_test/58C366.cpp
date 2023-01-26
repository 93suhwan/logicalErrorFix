#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long arr[2][n];
    long long i, j;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < n; j++) {
        if (i == 0)
          arr[i][j] = s1[j] - '0';
        else
          arr[i][j] = s2[j] - '0';
      }
    }
    long long flag = 0;
    pair<long long, long long> start = {0, 0};
    while (1) {
      if (start.first == 1 && start.second == n - 1) {
        flag = 1;
        break;
      }
      long long x = start.first;
      long long y = start.second;
      arr[x][y] = -1;
      if (x == 0) {
        if (arr[x][y + 1] == 0 && y + 1 < n)
          start = {x, y + 1};
        else if (arr[x + 1][y + 1] == 0 && y + 1 < n)
          start = {x + 1, y + 1};
        else if (arr[x + 1][y] == 0)
          start = {x + 1, y};
        else
          break;
      } else {
        if (arr[x][y + 1] == 0 && y + 1 < n)
          start = {x, y + 1};
        else if (arr[x - 1][y + 1] == 0 && y + 1 < n)
          start = {x - 1, y + 1};
        else if (arr[x - 1][y] == 0)
          start = {x - 1, y};
        else
          break;
      }
    }
    if (flag)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
