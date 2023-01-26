#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<vector<long long> > a(n, vector<long long>(m));
    for (long long i = 0; i < (n); i++)
      for (long long j = 0; j < (m); j++) cin >> a[i][j];
    for (long long x = 0; x < (k); x++) {
      long long j;
      cin >> j;
      j--;
      long long i = 0;
      while (i < n) {
        if (a[i][j] == 1) {
          a[i][j] = 2;
          j++;
        } else if (a[i][j] == 2)
          i++;
        else {
          a[i][j] = 2;
          j--;
        }
      }
      cout << j + 1 << ' ';
    }
  }
  return 0;
}
