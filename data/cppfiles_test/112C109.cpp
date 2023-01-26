#include <bits/stdc++.h>
using namespace std;
int solve(long long int a, long long int b, long long int c, long long int m) {
  vector<long long int> arr(3);
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;
  sort(arr.begin(), arr.end());
  long long int s = 0;
  long long int z = arr[0] + arr[1];
  z++;
  long long int mn = max(s, arr[2] - z);
  long long int mx =
      max(s, arr[0] - 1) + max(s, arr[1] - 1) + max(s, arr[2] - 1);
  if (m >= mn && m <= mx) {
    cout << "YES" << endl;
    return 0;
  } else {
    cout << "NO" << endl;
    return 0;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, m;
    cin >> a >> b >> c >> m;
    solve(a, b, c, m);
  }
}
