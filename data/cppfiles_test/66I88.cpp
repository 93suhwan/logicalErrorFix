#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int ctn = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (!(arr[i] % 3 == 0) && !(arr[i] % 10 == 3)) {
      cout << arr[i] << "\n";
      ctn++;
    } else
      cout << arr[i] + 1 << "\n";
  }
  return 0;
}
