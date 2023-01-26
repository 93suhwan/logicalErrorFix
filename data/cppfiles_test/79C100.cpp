#include <bits/stdc++.h>
using namespace std;
int n;
string a;
bool check[10];
int countA[10];
int nt[3] = {2, 3, 5};
int notNt[] = {1, 4, 5, 6, 8, 9};
bool isPrime(int n) {
  if (n == 2 || n == 3 || n == 7 || n == 5 || n == 23 || n == 37 || n == 53 ||
      n == 73)
    return true;
  else
    return false;
}
void solve() {
  cin >> n >> a;
  for (int i = 0; i < 10; i++) countA[i] = 0;
  for (int i = 0; i < n; i++) {
    if (!isPrime(a[i] - '0')) {
      cout << 1 << endl;
      cout << a[i] << endl;
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      int k = (a[i] - '0') * 10 + (a[j] - '0');
      if (!isPrime(k)) {
        cout << 2 << endl;
        cout << k << endl;
        return;
      }
    }
  }
  cout << a << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
