#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  int n;
  cin >> n;
  int arr[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (!isPrime(sum)) {
      int x = n - count;
      cout << x << endl;
      for (int j = 0; j < x; j++) {
        cout << j + 1 << " ";
      }
      cout << endl;
      return;
    } else if (isPrime(sum)) {
      count++;
      for (int k = n - 1; k >= 0; k--) {
        sum -= arr[k];
        break;
      }
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
