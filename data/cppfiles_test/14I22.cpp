#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; ++z) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> help_a(n);
    cout << n - 1 << endl;
    for (int i = 0; i < n - 1; ++i) {
      int maxId = 0;
      for (int j = 0; j < n - i; ++j) {
        if (a[maxId] < a[j]) maxId = j;
      }
      int d = maxId + 1;
      for (int j = 0; j < n - i; ++j) {
        if (j - d >= 0)
          help_a[j - d] = a[j];
        else {
          help_a[n + j - i - d] = a[j];
        }
      }
      a = help_a;
      cout << "1 " << n - i << " " << d << endl;
    }
  }
  return 0;
}
