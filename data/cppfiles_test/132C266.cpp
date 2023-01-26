#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int arr[7];
    int n = 7;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << arr[0] << " " << arr[1] << " " << arr[6] - arr[0] - arr[1];
    cout << endl;
  }
  return 0;
}
