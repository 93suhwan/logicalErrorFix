#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
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
    int out[n];
    if (isPrime(sum)) {
      int count = 0;
      while (isPrime(sum)) {
        sum = sum - arr[count];
        for (int i = 0; i < n; i++) {
          if (i == count) {
            continue;
          } else {
            out[i] = i + 1;
          }
        }
        count++;
      }
      cout << n - 1 << endl;
      for (int i = 0; i < (n - 1); i++) {
        cout << out[i] << " ";
      }
      cout << endl;
    } else {
      cout << n << endl;
      for (int i = 0; i < n; i++) {
        cout << (i + 1) << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
