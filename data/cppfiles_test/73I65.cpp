#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, cnt = 0, j, p = -1, f = 0;
    cin >> n;
    long long int ar[n + 2];
    std::vector<long long int> v;
    for (i = 1; i <= n; i++) {
      cin >> ar[i];
      v.push_back(ar[i]);
    }
    sort(v.begin(), v.end());
    for (i = 1; i <= n; i++) {
      if (ar[i] != v[i - 1]) f = 1;
    }
    if (f == 0)
      cout << "0" << endl;
    else {
      sort(v.begin(), v.end());
      while (1) {
        long long int flg = 0;
        for (j = 1; j < n; j++) {
          if (ar[j] > ar[j + 1]) {
            p = j;
            break;
          }
        }
        if (p % 2 == 0) {
          for (j = 2; j <= (n - 1); j += 2) {
            if (ar[j] > ar[j + 1]) swap(ar[j], ar[j + 1]);
          }
        } else {
          for (j = 1; j <= (n - 2); j += 2) {
            if (ar[j] > ar[j + 1]) swap(ar[j], ar[j + 1]);
          }
        }
        for (i = 1; i <= n; i++) {
          if (ar[i] != v[i - 1]) flg = 1;
        }
        if (flg)
          cnt++;
        else
          break;
      }
      cout << cnt + 1 << endl;
    }
  }
  return 0;
}
