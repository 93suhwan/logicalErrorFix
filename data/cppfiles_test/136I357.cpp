#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool not1 = false;
    long long num[n + 5];
    long long num2[n + 5];
    long long num3[n + 5];
    long long total1 = 0;
    long long total2 = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
      cin >> num[i];
      total1 += num[i];
    }
    num[0] = num[n];
    int d = total1 / total2;
    bool fail = false;
    if (total1 % total2 != 0) fail = true;
    for (int i = 1; i <= n; i++) {
      num2[i] = num[i] - d;
      if (num2[i] < 0) {
        fail = true;
      }
    }
    for (int i = 1; i <= n; i++) {
      num3[i] = num[i - 1] - num2[i];
      if (num3[i] < n) {
        fail = true;
      }
      num3[i] /= n;
    }
    if (fail)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (int i = 1; i <= n; i++) {
        cout << num3[i] << " ";
      }
      cout << endl;
    }
  }
}
