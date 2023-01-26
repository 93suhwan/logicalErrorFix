#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    cout << (arr[6] - arr[5]) << " " << arr[1] << " " << (arr[5] - arr[1])
         << endl;
  }
}
