#include <bits/stdc++.h>
using namespace std;
void Solution() {
  vector<long long> arr(3);
  cin >> arr[0] >> arr[1] >> arr[2];
  if (arr[0] == 0 || arr[1] == 0 || arr[2] == 0) {
    cout << "NO" << endl;
    return;
  }
  sort(arr.begin(), arr.end());
  if (arr[2] == arr[1] + arr[0]) {
    cout << "YES" << endl;
  } else if (arr[2] == arr[1]) {
    if (arr[0] % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else if (arr[1] == arr[0]) {
    if (arr[2] % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    Solution();
  }
}
