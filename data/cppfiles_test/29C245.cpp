#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, i = 0, cnt1 = 0, cnt2 = 0, sum = 0;
    cin >> n;
    long long arr[n];
    for (i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == 1)
        cnt1++;
      else if (arr[i] == 0)
        cnt2++;
      sum += arr[i];
    }
    long long x = pow(2, cnt2);
    cout << cnt1 * x << endl;
  }
  return 0;
}
