#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    if (arr[0] + arr[1] + arr[2] == arr[6] && arr[1] + arr[2] == arr[5] &&
        arr[0] + arr[2] == arr[4] && arr[0] + arr[1] == arr[3])
      cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    else if (arr[0] + arr[1] + arr[3] == arr[6] && arr[1] + arr[3] == arr[5] &&
             arr[0] + arr[3] == arr[4] && arr[0] + arr[1] == arr[2])
      cout << arr[0] << " " << arr[1] << " " << arr[3] << "\n";
  }
}
