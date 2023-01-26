#include <bits/stdc++.h>
using namespace std;
bool check(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    if (sum % 2 == 0 || !check(sum)) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
    } else {
      cout << n - 1 << endl;
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] % 2 && !cnt)
          cnt++;
        else
          cout << i << " ";
      }
      cout << endl;
    }
  }
}
