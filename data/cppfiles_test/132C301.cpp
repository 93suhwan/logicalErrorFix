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
    int a1 = arr[0];
    int a2 = arr[1];
    int a3 = arr[6] - a1 - a2;
    cout << a1 << " " << a2 << " " << a3 << endl;
  }
  return 0;
}
