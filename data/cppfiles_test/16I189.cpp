#include <bits/stdc++.h>
using namespace std;
char arr[40];
char arr2[40];
int main() {
  int t, n, k = 0;
  char p;
  cin >> t;
  for (int g = 0; g < t; g++) {
    cin >> n >> arr;
    for (int i = 0; i < n; i++) {
      arr2[i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = i; j > 0; j--) {
        if (arr[j] < arr[j - 1]) {
          p = arr[j];
          arr[j] = arr[j - 1];
          arr[j - 1] = p;
        } else {
          break;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (arr[i] != arr2[i]) {
        k++;
      }
    }
    cout << arr << " " << arr2 << "\n";
    cout << k << "\n";
    k = 0;
  }
}
