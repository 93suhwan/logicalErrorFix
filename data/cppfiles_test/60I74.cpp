#include <bits/stdc++.h>
using namespace std;
const int MAX = 100004;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, ans = 0, sum = 0;
    cin >> n;
    long long arr[n];
    map<long long, long long> m;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
      m[arr[i]]++;
    }
    if ((2 * sum) % n != 0)
      cout << "0" << '\n';
    else {
      long long temp = 2 * sum / n;
      for (int i = 0; i < n; i++) {
        ans += m[temp - arr[i]];
        if ((temp / 2) == arr[i]) ans--;
      }
      cout << ans / 2 << '\n';
    }
  }
  return 0;
}
