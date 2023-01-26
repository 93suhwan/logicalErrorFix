#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  unordered_set<long long int> set;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    set.insert(arr[i]);
  }
  sort(arr, arr + n);
  long long int mod = 1;
  for (int i = 0; i < n; i++) {
    if (mod == arr[i]) {
      mod++;
    } else {
      break;
    }
  }
  long long int count = 0;
  for (long long int i = 0; i < n; i++) {
    if (set.find(arr[i] + mod) != set.end()) {
      cout << arr[i] << " " << arr[i] + mod << "\n";
      count++;
    }
    if (count == n / 2) {
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
