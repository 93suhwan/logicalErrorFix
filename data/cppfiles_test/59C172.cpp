#include <bits/stdc++.h>
using namespace std;
const long long md = 1000000007;
long long icase = 1;
void google(long long t) { cout << "Case #" << t << ": "; }
void subMain() {
  long long m, n, k;
  cin >> n;
  long long arr[5];
  char ch;
  memset(arr, -1, sizeof(arr));
  long long mat[5][n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> ch;
      mat[j][i] = ch == '1';
    }
  }
  long long flag = 0;
  for (long long i = 0; i < 5; i++) {
    for (long long j = i + 1; j < 5; j++) {
      long long a = 0;
      long long b = 0;
      long long ab = 0;
      for (long long k = 0; k < n; k++) {
        if (mat[i][k]) {
          a++;
        }
        if (mat[j][k]) {
          b++;
        }
        if (mat[i][k] && mat[j][k]) ab++;
      }
      if (a >= n / 2 && b >= n / 2 && (a + b - ab) >= n) {
        flag = 1;
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    subMain();
  }
  return 0;
}
