#include <bits/stdc++.h>
using namespace std;
int main() {
  int numTest;
  cin >> numTest;
  for (int num = 0; num < numTest; ++num) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    int temp = arr[0], temp2 = 0;
    for (int i = 1; i < n; ++i) {
      temp2 += arr[i - 1];
      arr[i] -= temp;
      temp += arr[i];
      if (arr[0] < arr[i]) arr[0] = arr[i];
    }
    cout << arr[0] << endl;
  }
}
