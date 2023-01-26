#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int cnt = 0;
    sort(arr, arr + n);
    if (arr[0] != 1) {
      cnt++;
    }
    bool b = 1;
    for (int i = 1; i < n; i++) {
      int a = arr[i] - i - 1;
      if (arr[i] == i + 1) {
        continue;
      } else if (arr[i] % a == i + 1) {
        cnt++;
      } else {
        cout << -1 << endl;
        b = 0;
        break;
      }
    }
    if (b) {
      cout << cnt << endl;
    }
  }
  return 0;
}
