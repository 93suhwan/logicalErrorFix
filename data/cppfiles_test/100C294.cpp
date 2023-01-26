#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    arr.push_back(v);
  }
  sort(arr.begin(), arr.end());
  int ma = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    int v = (arr[i] - arr[i - 1]);
    if (v > ma) ma = v;
  }
  cout << ma << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
