#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
const long long INF = 1e18 + 56;
const long long NINF = -1 * INF;
void solve(int q) {
  int n, m;
  cin >> n >> m;
  vector<string> arr(n);
  for (int j = 0; j < n; j++) {
    cin >> arr[j];
    for (int i = 0; i < m; i++) {
      if (i % 2) arr[j][i] = 65 + (90 - arr[j][i]);
    }
  }
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j % 2 == 0)
        cout << arr[i][j];
      else {
        arr[i][j] = 65 + (90 - arr[i][j]);
        cout << arr[i][j];
      }
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(), cout.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
