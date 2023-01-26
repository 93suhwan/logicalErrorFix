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
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == 0) val = 1;
    }
    set<long long int> all;
    long long int total = pow(2, n);
    if (val) cout << "YES" << endl;
    for (long long int i = 1; i < total; i++) {
      long long int sum = 0;
      for (long long int j = 0; j < n; j++) {
        if (i & (1 << j)) sum += arr[j];
      }
      if (all.find(sum) != all.end()) {
        val = 1;
        cout << "YES" << endl;
        break;
      } else
        all.insert(sum);
    }
    if (val == 0) cout << "NO" << endl;
  }
  return 0;
}
