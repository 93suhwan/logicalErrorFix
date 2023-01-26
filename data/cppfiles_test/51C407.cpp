#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, a;
  cin >> t;
  long long int arr[t];
  for (i = 0; i < t; i++) {
    cin >> arr[i];
  }
  for (i = 0; i < t; i++) {
    if (arr[i] == 1) {
      cout << 0 << " " << 1 << endl;
    } else {
      a = -(arr[i] - 1);
      cout << a << " " << arr[i] << endl;
    }
  }
  return 0;
}
