#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] & 1) {
        pos = i;
      }
      sum += a[i];
    }
    if (sum % 2 == 0) {
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
    } else if (isPrime(sum) == true) {
      for (int i = 1; i <= n; i++) {
        if (i - 1 == pos) continue;
        cout << i << " ";
      }
    } else {
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
