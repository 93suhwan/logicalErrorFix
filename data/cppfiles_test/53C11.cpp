#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int i;
  for (i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    int j;
    int a[n], c[n];
    for (j = 0; j < n; j++) {
      cin >> a[j];
    }
    unordered_map<int, int> m;
    for (j = 0; j < n; j++) {
      m[a[j]] = j;
    }
    for (j = 0; j < n; j++) c[j] = a[j];
    sort(c, c + n);
    int count = 0;
    for (j = 0; j < n; j++) {
      while (j < n - 1 && m[c[j + 1]] - m[c[j]] == 1) {
        j++;
      }
      count++;
    }
    if (count <= k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
