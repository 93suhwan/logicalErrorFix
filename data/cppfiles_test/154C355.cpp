#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long arr[3];
    for (int i = 0; i < 3; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + 3);
    if (arr[2] == arr[0] + arr[1])
      cout << "YES" << '\n';
    else if (arr[0] == arr[1] && arr[2] % 2 == 0)
      cout << "YES" << '\n';
    else if (arr[1] == arr[2] && arr[0] % 2 == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
