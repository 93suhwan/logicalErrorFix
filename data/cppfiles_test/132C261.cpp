#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  long long int t, i, n = 7;
  cin >> t;
  long long int arr[7];
  while (t--) {
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << arr[0] << " " << arr[1] << " " << arr[6] - (arr[0] + arr[1])
         << endl;
  }
  return 0;
}
