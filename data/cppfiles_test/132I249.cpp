#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int x24e;
  cin >> x24e;
  for (long long int TC = 1; TC <= x24e; TC++) {
    long long int arr[7];
    for (long long int i = 0; i < 7; i++) cin >> arr[i];
    cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
  }
  return 0;
}
