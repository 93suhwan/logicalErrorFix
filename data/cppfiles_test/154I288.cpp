#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    if (arr[0] < 1 || arr[1] < 1 || arr[2] < 1) {
      cout << "NO" << endl;
      continue;
    }
    if (arr[2] == arr[1] + arr[0]) {
      cout << "YES" << endl;
    } else if (arr[2] == arr[1] && arr[0] % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
