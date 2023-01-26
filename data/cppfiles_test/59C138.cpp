#include <bits/stdc++.h>
using namespace std;
bool isSquare(int x) {
  int y = sqrt(x);
  return y * y == x;
}
bool isPowerOfTwo(int n) {
  if (n == 0) {
    return false;
  }
  return (ceil(log2(n)) == floor(log2(n)));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long abc = 0; abc < t; abc++) {
    long long n;
    cin >> n;
    int arr[n][5];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 5; j++) {
        cin >> arr[i][j];
      }
    }
    int an = 0;
    long long p, q, r;
    for (long long i = 0; i < 4; i++) {
      for (long long j = i + 1; j < 5; j++) {
        p = 0, q = 0, r = 0;
        for (long long k = 0; k < n; k++) {
          if (arr[k][i] == 1 && arr[k][j] == 1) {
            r++;
            continue;
          }
          if (arr[k][i] == 1) {
            p++;
          }
          if (arr[k][j] == 1) {
            q++;
          }
        }
        if (p <= n / 2 && q <= n / 2 && p + q + r >= n) {
          cout << "YES" << endl;
          an = 1;
          break;
        }
      }
      if (an == 1) {
        break;
      }
    }
    if (an == 0) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
