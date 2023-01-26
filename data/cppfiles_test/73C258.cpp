#include <bits/stdc++.h>
using namespace std;
bool is_sorted(int *a, int n) {
  bool sorted = true;
  for (int j = 1; j < n; j++)
    if (a[j] > a[j + 1]) sorted = false;
  return sorted;
}
int solve(int *a, int n) {
  if (is_sorted(a, n)) return 0;
  int i = 1;
  while (!is_sorted(a, n)) {
    if (i & 1) {
      for (int j = 1; j < n - 1; j += 2)
        if (a[j] > a[j + 1]) {
          a[j] = a[j] ^ a[j + 1];
          a[j + 1] = a[j] ^ a[j + 1];
          a[j] = a[j] ^ a[j + 1];
        }
    } else {
      for (int j = 2; j < n; j += 2)
        if (a[j] > a[j + 1]) {
          a[j] = a[j] ^ a[j + 1];
          a[j + 1] = a[j] ^ a[j + 1];
          a[j] = a[j] ^ a[j + 1];
        }
    }
    i++;
  }
  return i - 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << solve(a, n) << '\n';
  }
  return 0;
}
