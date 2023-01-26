#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 4;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  for (int qw = 1; qw <= test; qw++) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    if (!isPrime(sum)) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
    } else {
      int flag = 0;
      for (int i = 0; i < n; i++) {
        if (!isPrime(sum - a[i])) {
          cout << n - 1 << endl;
          flag = 1;
          for (int j = 0; j < n; j++) {
            if (i != j) cout << j + 1 << " ";
          }
          cout << endl;
        }
        if (flag == 1) break;
      }
    }
  }
  return 0;
}
