#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, sum = 0;
    cin >> n;
    string arr;
    string brr;
    cin >> arr >> brr;
    for (int i = 0; i < n; i++) {
      if (brr[i] == '0') {
        continue;
      }
      if (arr[i] == '0') {
        sum++;
        arr[i] = '2';
        continue;
      }
      if (i == 0 && arr[1] == '1') {
        sum++;
        arr[1] = '2';
        continue;
      }
      if (i == 0 && arr[1] != '1') {
        continue;
      }
      if (arr[i - 1] == '1') {
        sum++;
        arr[i - 1] = '2';
        continue;
      }
      if (i == n - 1) {
        break;
      }
      if (arr[i + 1] == '1') {
        sum++;
        arr[i + 1] = '2';
      }
    }
    cout << sum << endl;
  }
  return 0;
}
