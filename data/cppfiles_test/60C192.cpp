#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int sum = arr[0];
  for (int i = 1; i < n; i++) {
    sum = sum & arr[i];
  }
  cout << sum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
