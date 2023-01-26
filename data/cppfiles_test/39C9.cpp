#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn];
int n;
int main() {
  cin >> n;
  int num = 1;
  for (int i = n; i >= 1; i--) {
    cout << "? ";
    for (int j = 1; j < n; j++) {
      cout << i << " ";
    }
    cout << 1 << '\n';
    int x;
    cin >> x;
    if (x) {
      num = i;
      break;
    }
  }
  a[n] = num;
  for (int i = 1; i <= n; i++) {
    if (i == num) continue;
    cout << "? ";
    for (int j = 1; j <= n - 1; j++) {
      cout << num << " ";
    }
    cout << i << "\n";
    int x;
    cin >> x;
    a[x] = i;
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
