#include <bits/stdc++.h>
using namespace std;
bool prime(long long int a) {
  if (a == 1) {
    return false;
  } else {
    for (long long int i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        return false;
      }
    }
    return true;
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    long long int d = n / 2;
    long long int c = 0;
    for (long long int i = n - 1; i >= 1; i--) {
      cout << arr[i] << " " << arr[0] << endl;
      c++;
      if (c == d) {
        break;
      }
    }
  }
  return 0;
}
