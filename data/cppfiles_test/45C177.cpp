#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[101], t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, pre = 1, cur, ht = 1, test = 1;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    for (int j = 0; j < n; j++) {
      if (arr[j] == 0 && arr[j - 1] == 0 && j > 0) {
        test = 0;
        break;
      } else if (arr[j] == 1 && arr[j - 1] == 0 && j > 0) {
        ht += 1;
      } else if (arr[j] == 1 && arr[j - 1] == 1 && j > 0) {
        ht += 5;
      } else if (j == 0 && arr[j] == 1) {
        ht += 1;
      }
    }
    if (test == 0) {
      cout << -1 << endl;
    } else {
      cout << ht << endl;
    }
  }
  return 0;
}
