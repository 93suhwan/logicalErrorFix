#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int arr[7] = {0};
  for (int i = 0; i < t; i++) {
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    cout << arr[0] << " " << arr[1] << " " << arr[6] - arr[0] - arr[1] << "\n";
  }
  return 0;
}
