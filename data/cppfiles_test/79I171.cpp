#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string arr;
    cin >> arr;
    if ((arr[0] == '2' && arr[1] == '3' && arr[2] == '7') ||
        (arr[0] == '2' && arr[1] == '7' && arr[2] == '3')) {
      cout << 2 << endl << 27 << endl;
      continue;
    } else if ((arr[0] == '5' && arr[1] == '3' && arr[2] == '7') ||
               (arr[0] == '5' && arr[1] == '7' && arr[2] == '3')) {
      cout << 2 << endl << 57 << endl;
      continue;
    }
    int i = 0;
    int c[10] = {};
    for (int i = 0; i < k; i++) {
      if (arr[i] == '4' || arr[i] == '1' || arr[i] == '9' || arr[i] == '6' ||
          arr[i] == '8') {
        cout << 1 << endl << arr[i] << endl;
        goto A;
      }
      c[int(arr[i]) - 48]++;
    }
    for (int i = 0; i < k; i++) {
      if ((arr[i] == '2') && (i >= 1)) {
        cout << 2 << endl << (int(arr[i - 1]) - 48) * 10 + 2 << endl;
        goto A;
      } else if (arr[i] == '5' && i >= 1) {
        cout << 2 << endl << (int(arr[i - 1]) - 48) * 10 + 5 << endl;
        goto A;
      } else if (c[arr[i]] > 1) {
        cout << 2 << endl
             << (int(arr[i]) - 48) * 10 + (int(arr[i]) - 48) << endl;
        goto A;
      }
    }
    cout << k << endl << arr << endl;
  A:;
  }
}
