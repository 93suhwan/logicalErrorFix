#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long d1 = n / k;
  long long d2 = n % k;
  long long ans = 1;
  for (int i = 0; i < n - d1; i++) {
    for (int j = i + 1; j < i + d1; j++) {
      if (arr[j] < arr[j - 1]) {
        cout << "No\n";
        return;
      }
    }
  }
  for (int i = 0; i < n - d2; i++) {
    for (int j = i + 1; j < i + d2; j++) {
      if (arr[j] < arr[j - 1]) {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
