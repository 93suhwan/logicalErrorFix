#include <bits/stdc++.h>
using namespace std;
long long int gcd(long int a, long long int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  if (a == b) {
    return a;
  }
  if (a > b) {
    return gcd(a - b, b);
  } else {
    return gcd(a, b - a);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  while (t != 0) {
    long long int n, gcd1, gcd2, c1 = 0, c2 = 0;
    cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n == 2) {
      if (arr[0] == arr[1]) {
        cout << 0 << "\n";
      } else {
        cout << max(arr[0], arr[1]) << "\n";
      }
    } else if (n == 3) {
      if (arr[0] % arr[1] != 0 && arr[2] % arr[1] != 0) {
        cout << arr[1] << "\n";
      } else {
        gcd1 = gcd(arr[0], arr[2]);
        if (arr[1] % gcd1 == 0) {
          cout << 0 << "\n";
        } else {
          cout << gcd1 << "\n";
        }
      }
    } else {
      gcd1 = gcd(arr[0], arr[2]);
      gcd2 = gcd(arr[1], arr[3]);
      for (long long int i = 2; i < n; i = i + 2) {
        gcd1 = gcd(gcd1, arr[i]);
      }
      for (long long int i = 3; i < n; i = i + 2) {
        gcd2 = gcd(gcd2, arr[i]);
      }
      for (long long int i = 2; i < n; i = i + 2) {
        if (arr[i] % gcd2 == 0) {
          c1++;
          break;
        }
      }
      for (long long int i = 3; i < n; i = i + 2) {
        if (arr[i] % gcd1 == 0) {
          c2++;
          break;
        }
      }
      if (c1 == 0) {
        cout << gcd2 << "\n";
      } else if (c2 == 0) {
        cout << gcd1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    }
    t--;
  }
}
