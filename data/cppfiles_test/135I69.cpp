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
    int num1[n];
    for (int i = 0; i < n; i++) {
      cin >> num[i];
      num1[i] = num[i];
    }
    sort(num1, num1 + n);
    sort(num, num + n);
    int j = n - 1;
    int l = 0, r = n - 1;
    int sum = 0;
    int res = 0;
    for (int i = 0; i < k; i++) {
      sum += num[j - 1] / num[j];
      num[j] = 0, num[j - 1] = 0;
      j = j - 2;
    }
    for (int i = 0; i < k; i++) {
      res += num1[l++] / num1[r--];
      num1[l - 1] = 0, num1[r + 1] = 0;
    }
    for (int i = 0; i < n; i++) sum += num[i];
    for (int i = 0; i < n; i++) res += num1[i];
    cout << min(sum, res) << endl;
  }
}
