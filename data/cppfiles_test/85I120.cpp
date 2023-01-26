#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int findGCD(int arr[], int n) {
  int result = arr[0];
  for (int i = 1; i < n; i++) {
    result = gcd(arr[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if ((y % 2) == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int ct = 0;
    for (int i = 0; i <= n - 1; i++) {
      if (s[i] == '0') {
        ct++;
      }
    }
    int ct0 = 0;
    for (int i = 0; i <= n - 1; i++) {
      if (s[i] == '1') {
        ct0++;
      }
    }
    if (s[0] == '0' && s[n - 1] == '0') {
      ct0++;
    } else if (s[0] == '1' && s[n - 1] == '1') {
      ct0--;
    }
    if (ct == 0) {
      cout << 0;
    } else if (ct == n) {
      cout << 1;
    } else if (ct0 > 2) {
      cout << 2;
    } else {
      cout << ct0;
    }
    cout << "\n";
  }
  return 0;
}
