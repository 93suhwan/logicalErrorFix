#include <bits/stdc++.h>
using namespace std;
const int maxn = 40000;
int b[maxn], a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      sum += b[i];
    }
    if (sum * 2 % (1ll * n * (n + 1)) != 0) {
      cout << "NO" << endl;
      continue;
    }
    sum = sum * 2 / n / (n + 1);
    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
      if ((b[(i + n - 1) % n] + sum - b[i]) % n != 0) ok = false;
      a[i] = (b[(i + n - 1) % n] + sum - b[i]) / n;
      if (a[i] <= 0) ok = false;
    }
    if (!ok) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) cout << a[i] << " ";
      cout << endl;
    }
  }
}
