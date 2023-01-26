#include <bits/stdc++.h>
long long int power(long long int x, long long int n) {
  long long int result = 1;
  while (n) {
    if (n % 2 == 1) result = result * x;
    n = n / 2;
    x = x * x;
  }
  return result;
}
long long int gcd(long long int a, long long int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int BS(long long int a[], long long int s, long long int n,
                 long long int val) {
  long long int mid, beg = s, end = n - 1;
  while (beg <= end) {
    mid = (beg + end) / 2;
    if (val == a[mid]) {
      break;
    } else if (val > a[mid]) {
      beg = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return mid;
}
using namespace std;
void start() {}
int main() {
  start();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if (l1 == l2 && l3 % 2 == 0)
      cout << "YES"
           << "\n";
    else if (l2 == l3 && l1 % 2 == 0)
      cout << "YES"
           << "\n";
    else if (l1 == l3 && l2 % 2 == 0)
      cout << "YES"
           << "\n";
    else {
      if (l1 + l2 == l3)
        cout << "YES"
             << "\n";
      else if (l3 + l2 == l1)
        cout << "YES"
             << "\n";
      else if (l1 + l3 == l2)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
  return 0;
}
