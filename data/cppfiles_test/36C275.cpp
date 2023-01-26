#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
int odd(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 != 0) {
      return i;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
    }
    int fodd = odd(arr, n);
    if (isPrime(sum)) {
      cout << n - 1 << endl;
      for (int i = 0; i < n; i++) {
        if (i == fodd) {
          continue;
        }
        cout << (i + 1) << " ";
      }
      cout << endl;
    }
    if (!(isPrime(sum))) {
      cout << n << endl;
      for (int i = 0; i < n; i++) {
        cout << (i + 1) << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
