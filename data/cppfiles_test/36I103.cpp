#include <bits/stdc++.h>
using namespace std;
bool checkSNT(int n) {
  int can = sqrt(n);
  for (int i = 2; i < can; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    int count = 0;
    if (checkSNT(sum)) {
      for (int i = 0; i < n; i++) {
        if (!checkSNT(sum - arr[i])) {
          count = i + 1;
          break;
        }
      }
      cout << n - 1 << endl;
      for (int i = 1; i <= n; i++) {
        if (i != count) cout << i << " ";
      }
    } else {
      cout << n << endl;
      for (int i = 1; i <= n; i++) cout << i << " ";
    }
  }
}
