#include <bits/stdc++.h>
using namespace std;
int n;
string a;
bool check[10];
int countA[10];
int nt[3] = {2, 3, 5};
int notNt[] = {1, 4, 5, 6, 8, 9};
bool isPrime(int n) {
  if (n == 2 || n == 3 || n == 7 || n == 5)
    return true;
  else
    return false;
}
void solve() {
  cin >> n >> a;
  for (int i = 0; i < 10; i++) countA[i] = 0;
  for (int i = 0; i < n; i++) {
    countA[a[i] - '0']++;
    if (!isPrime(a[i] - '0')) {
      cout << 1 << endl;
      cout << a[i] << endl;
      return;
    }
  }
  if (countA[2] > 0 && countA[7] > 0) {
    cout << 2 << endl;
    cout << 27 << endl;
    return;
  }
  bool check = false;
  for (int i = 0; i < n - 1; i++) {
    if ((a[i] != '2' && a[i + 1] != '3') || (a[i] != '3' && a[i + 1] != '7') ||
        (a[i] != '7' && a[i + 1] != '3') || (a[i] != '5' && a[i] != '3')) {
      cout << 2 << endl;
      cout << a[i] << a[i + 1] << endl;
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
  return 0;
}
