#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long arr[2][n];
    for (long i = 0; i < 2; i++) {
      for (long j = 0; j < n; j++) {
        cin >> arr[i][j];
      }
    }
    int flag = 0;
    for (long i = 0; i < n; i++) {
      if (arr[0][i] == 1 && arr[1][i] == 1) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
