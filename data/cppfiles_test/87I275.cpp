#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  pair<int, int> maxElement;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > maxElement.first) {
      maxElement.first = arr[i];
      maxElement.second = i;
    }
  }
  if (maxElement.second == n - 1) {
    cout << maxElement.first - n << endl;
  } else {
    cout << maxElement.first - n + (n - 1 - maxElement.second) << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
