#include <bits/stdc++.h>
using namespace std;
int arr[7];
bool is_sum[7];
int main() {
  int n, num;
  cin >> n;
  for (int ii = 0; ii < n; ++ii) {
    for (int i = 0; i < 7; ++i) {
      cin >> arr[i];
    }
    for (int i = 0; i < 6; ++i) {
      if (is_sum[i] == false) {
        for (int j = i + 1; j < 6; ++j) {
          if (is_sum[j] == false) {
            for (int k = j + 1; k < 7; ++k) {
              if (is_sum[k] == false) {
                if (arr[i] + arr[j] == arr[k]) {
                  is_sum[k] = true;
                  break;
                }
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < 7; ++i) {
      if (is_sum[i] == false) {
        cout << arr[i] << ' ';
      }
    }
    cout << endl;
    for (int i = 0; i < 7; ++i) {
      is_sum[i] = false;
    }
  }
  return 0;
}
