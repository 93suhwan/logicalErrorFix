#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long power(long long n, long long p) {
  long long res = 1;
  while (p) {
    if (p % 2)
      res *= n, p--;
    else
      n *= n, p /= 2;
  }
  return res;
}
long long max3(long long n1, long long n2, long long n3) {
  if (n1 >= n2 && n1 >= n3) return n1;
  if (n2 >= n1 && n2 >= n3) return n2;
  if (n3 >= n1 && n3 >= n2) return n3;
}
void print_vector(vector<long long> v) {
  for (auto i : v) cout << i << ' ' << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 3 == 0)
      cout << n / 3 << " " << n / 3 << endl;
    else {
      if (n / 3 + 2 * (n / 3 + 1) == n)
        cout << n / 3 << " " << n / 3 + 1 << endl;
      else
        cout << n / 3 + 1 << " " << n / 3 << endl;
    }
  }
}
