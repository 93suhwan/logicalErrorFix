#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int num[n];
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    int sum = 0;
    for (int i = 0; i < n - 2 * k; i++) {
      sum += num[i];
    }
    for (int i = 0; i < k; i++) sum += num[n - 2 * k + i] / num[n - k + i];
    cout << sum << endl;
  }
}
