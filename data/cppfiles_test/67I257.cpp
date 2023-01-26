#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin >> num;
  int arr[3];
  while (num--) {
    for (int i = 0; i < 3; i++) {
      cin >> arr[i];
    }
    int temp;
    temp = abs(arr[1] - arr[0]);
    if (temp * 2 < arr[2]) {
      cout << "-1"
           << "\n";
    } else {
      if (temp == 1 || *max_element(arr, arr + 3) > 2 * temp) {
        cout << "-1"
             << "\n";
      } else if (arr[2] <= *max_element(arr, arr + 3) &&
                 arr[2] >= *min_element(arr, arr + 3) &&
                 abs(arr[2] - temp) > 0) {
        cout << arr[2] - temp << "\n";
      } else if (arr[2] <= *max_element(arr, arr + 3) &&
                 arr[2] >= *min_element(arr, arr + 3) &&
                 (arr[2] + temp) <= temp * 2) {
        cout << arr[2] + temp << "\n";
      } else {
        cout << arr[2] - 2 * (temp - 1) << "\n";
      }
    }
  }
}
