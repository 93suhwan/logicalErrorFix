#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < 3; i++) {
      cout << arr[i];
    }
  }
  return 0;
}
