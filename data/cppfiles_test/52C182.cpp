#include <bits/stdc++.h>
using namespace std;
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
void K_K() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  K_K();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<double> arr(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    double mx = *max_element(arr.begin(), arr.end());
    cout << fixed << setprecision(9) << mx + ((sum - mx) / (n - 1)) << "\n";
  }
}
