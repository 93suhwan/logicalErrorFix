#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, val = 0;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    set<long long int> all;
    long long int total = pow(2, n);
    for (long long int i = 0; i < total; i++) {
      long long int sum = 0;
      for (long long int j = 0; j < n; j++) {
        if (i & (1 << j)) sum += arr[j];
      }
      if (all.find(sum) != all.end()) {
        val = 1;
        break;
      } else
        all.insert(sum);
    }
    if (val)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
