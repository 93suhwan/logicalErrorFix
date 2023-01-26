#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int a[N];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int l[N];
    int r[N];
    int k = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n - i; j++) {
        if (a[j] < a[j - 1]) {
          l[k] = j - 1 + 1;
          r[k] = j + 1;
          k++;
          swap(a[j], a[j - 1]);
        }
      }
    }
    cout << k << endl;
    for (int i = 0; i < k; i++) cout << l[i] << ' ' << r[i] << ' ' << 1 << endl;
  }
  return 0;
}
