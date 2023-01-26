#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int testcase;
  cin >> testcase;
  while (testcase--) {
    long long int n;
    cin >> n;
    long long int i;
    long long int arr[n];
    long long int temp = 0;
    long long int overall = 0;
    long long int flag = 0;
    long long int last = 0;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    while (overall < n) {
      for (i = n - 1; i >= 0; i--) {
        if (arr[i] != 0) {
          if (arr[i] % (i + 2 - temp) != 0) {
            arr[i] = 0;
            overall++;
          }
        } else {
          temp--;
        }
      }
      if (last == overall) {
        flag = 1;
        break;
      } else {
        temp = overall;
        last = overall;
      }
    }
    if (flag == 1) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
  }
  return 0;
}
