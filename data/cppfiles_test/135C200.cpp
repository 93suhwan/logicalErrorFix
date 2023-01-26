#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int t = 0, i = n - k - 1, end = arr.size() - 1;
    while (t < k) {
      t++;
      sum += (arr[i--] / arr[end--]);
    }
    for (int i = 0; i < n - 2 * k; i++) sum += arr[i];
    cout << sum << endl;
  }
  return 0;
}
