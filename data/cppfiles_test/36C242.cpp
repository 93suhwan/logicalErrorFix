#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  for (int i = n / 2; i > 1; i--) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  int l[n];
  int count1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    count1 += l[i];
  }
  if (!isprime(count1)) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << endl;
    return;
  }
  for (int j = 0; j < n; j++) {
    if (!isprime(count1 - l[j])) {
      cout << n - 1 << endl;
      for (int k = 0; k < n; k++) {
        if (k != j) {
          cout << k + 1 << " ";
        }
      }
      cout << endl;
      return;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
