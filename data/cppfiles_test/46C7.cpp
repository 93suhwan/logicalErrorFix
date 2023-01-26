#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n; i++) cin >> num[i];
  long long res = 0;
  for (int i = 0; i < n; i += 2) {
    if (i == n - 1) break;
    res += (num[i] > num[i + 1] ? num[i + 1] : num[i]);
    long long min = 0, max = num[i] - num[i + 1];
    if (min > max) continue;
    for (int j = i + 2; j < n; j += 2) {
      if (j == n - 1) break;
      min += num[j];
      max += num[j];
      if (num[j + 1] > max) {
        res += (max - min + 1);
        break;
      }
      if (num[j + 1] < min) {
        min -= num[j + 1];
        max -= num[j + 1];
        continue;
      }
      res += (num[j + 1] - min + 1);
      min = 0;
      max -= num[j + 1];
    }
  }
  cout << res;
}
