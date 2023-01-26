#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long MAX = a[0];
    for (int i = 1; i < n; i++) {
      MAX = max(a[i] - a[i - 1], MAX);
    }
    cout << MAX << endl;
  }
}
