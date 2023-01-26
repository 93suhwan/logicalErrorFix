#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int result = 0;
    int a[105];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] - result - i > 0) {
        result += a[i] - result - i;
      }
    }
    cout << result << endl;
  }
  return 0;
}
