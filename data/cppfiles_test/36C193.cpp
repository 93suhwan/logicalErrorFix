#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long sum) {
  if (sum < 2) {
    return false;
  }
  if (sum == 2 || sum == 3) {
    return true;
  }
  if (sum % 2 == 0 || sum % 3 == 0) {
    return false;
  }
  for (long long i = 5; i * i <= sum; i += 6) {
    if (sum % i == 0 || sum % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    long long sum = 0;
    int odd_index;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      sum += arr[i];
      if (arr[i] % 2 != 0) {
        odd_index = i;
      }
    }
    if (sum % 2 == 0) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
    } else if (isPrime(sum) == false) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      cout << n - 1 << endl;
      for (int i = 1; i <= n; i++) {
        if (i != odd_index) {
          cout << i << " ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}
