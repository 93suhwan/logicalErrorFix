#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    long long int arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
  }
  return 0;
}
