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
  cout << maxElement.first - n + (n - (maxElement.second + 1)) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
