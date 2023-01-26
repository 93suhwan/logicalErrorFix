#include <bits/stdc++.h>
using namespace std;
void want() {
  long long n;
  cin >> n;
  long long i, j;
  long long A[2][n];
  long long sum1 = 0;
  long long sum2 = 0;
  for (j = 0; j < 2; j++) {
    for (i = 0; i < n; i++) {
      cin >> A[j][i];
      if (j == 0) {
        sum1 += A[j][i];
      } else {
        sum2 += A[j][i];
      }
    }
  }
  sum1 -= A[0][0];
  sum2 -= A[1][n - 1];
  for (i = 0; i < n; i++) {
    if (sum1 > sum2) {
      sum1 -= A[0][i];
    } else {
      break;
    }
  }
  for (j = i; j < n; j++) {
    sum2 -= A[1][j];
  }
  cout << max(sum1, sum2) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    want();
  }
}
