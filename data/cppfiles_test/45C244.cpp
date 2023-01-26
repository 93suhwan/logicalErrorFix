#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  fast();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n], brr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      arr[i] = arr[i] % 2;
      brr[i] = arr[i];
    }
    long long a0 = 0, a1 = 0;
    long long val = 0;
    long long j = 0;
    for (long long i = 0; i < n; i++) {
      if (arr[i] == val) {
        val = 1 - val;
        continue;
      }
      while (j < n) {
        if (j > i && arr[j] == val) break;
        j++;
      }
      if (j == n) {
        a0 = -1;
        break;
      }
      swap(arr[i], arr[j]);
      a0 += j - i;
      val = 1 - val;
    }
    val = 1, j = 0;
    for (long long i = 0; i < n; i++) {
      if (brr[i] == val) {
        val = 1 - val;
        continue;
      }
      while (j < n) {
        if (j > i && brr[j] == val) {
          break;
        }
        j++;
      }
      if (j == n) {
        a1 = -1;
        break;
      }
      swap(brr[i], brr[j]);
      a1 += j - i;
      val = 1 - val;
    }
    if (a0 == -1 && a1 == -1) {
      cout << -1 << "\n";
    } else if (a0 == -1) {
      cout << a1 << "\n";
    } else if (a1 == -1) {
      cout << a0 << "\n";
    } else {
      cout << min(a0, a1) << "\n";
    }
  }
  return 0;
}
