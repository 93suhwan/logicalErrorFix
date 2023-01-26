#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  int arr[205];
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) arr[i + 1] = -1;
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      arr[x] = y;
      arr[y] = x;
    }
    vector<int> v;
    for (int i = 0; i < 2 * n; i++) {
      if (arr[i + 1] == -1) v.push_back(i + 1);
    }
    for (int j = 0; j < n - k; j++) {
      arr[v[j]] = v[j + n - k];
      arr[v[j + n - k]] = v[j];
    }
    long long ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
      if (arr[i] > i) {
        for (int j = i + 1; j < arr[i]; j++) {
          if ((arr[j] < i) || (arr[j] > arr[i])) ++ans;
        }
      }
    }
    cout << ans / 2 << endl;
  }
  return 0;
}
