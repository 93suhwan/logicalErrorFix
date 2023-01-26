#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
int a[N];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int sum = 0, flag = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    int k = sum / n * 2;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i] + a[j] == k) flag++;
    cout << flag << endl;
  }
  return 0;
}
