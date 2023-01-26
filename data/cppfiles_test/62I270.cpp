#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n + 1; ++i) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
