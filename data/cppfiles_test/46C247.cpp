#include <bits/stdc++.h>
using namespace std;
long long int gcd(long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int power(long long int x, long long int y) {
  if (y == 0) return 1;
  long long int p = power(x, y / 2) % 1000000007;
  p = (p * p) % 1000000007;
  return (y % 2 == 0) ? p : (x * p) % 1000000007;
}
long long int modInverse(long long int a) {
  long long int g = gcd(a, 1000000007);
  long long int x = power(a, 1000000007 - 2);
  return x;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int count = 0;
    long long curr = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] > curr) {
        count++;
        curr = arr[i];
      }
    }
    cout << count << endl;
  }
  return 0;
}
