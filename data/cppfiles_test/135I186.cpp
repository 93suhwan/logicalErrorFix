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
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < n - 2 * k; i++) {
      sum += num[i];
    }
    int l = n - 2 * k, r = n - 1;
    for (int i = 0; i < k; i++) {
      res += num[l++] / num[r--];
    }
    int j = n - 1;
    for (int i = 0; i < k; i++) {
      cnt += num[j - 1] / num[j];
      num[j] = 0, num[j - 1] = 0;
      j = j - 2;
    }
    cout << min(sum + cnt, sum + res) << endl;
  }
}
