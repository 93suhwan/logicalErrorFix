#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int n = 10007;
  int a[10007] = {0};
  int num = 1;
  int primeCount = 0;
  int r = 0;
  for (int j = 1; j <= n; j++) {
    num++;
    primeCount = 0;
    for (int i = 1; i <= num; i++) {
      if (num % i == 0) {
        primeCount++;
      }
    }
    if (primeCount == 2) {
      a[r] = num;
      r++;
    }
  }
  for (int i = 0; i < k; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
