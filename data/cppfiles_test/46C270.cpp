#include <bits/stdc++.h>
using namespace std;
bool isprime(long long int a) {
  for (int i = 2; i <= sqrt(a); i++)
    if (a % i == 0) return false;
  return true;
}
long long int findGCD(long long int a, long long int b) {
  if (b == 0) return a;
  return findGCD(b, a % b);
}
long long int n, m;
long long int pow(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  long long int x = pow(a, b / 2, m);
  x = (x * x) % m;
  if (b % 2 == 1) x = (x * a) % m;
  return x;
}
bool issubseq(string a, string b) {
  long long int i = 0, j = 0;
  for (i = 0; i < b.length(); i++) {
    while (j < a.length()) {
      if (b[i] == a[j]) i++;
      j++;
      if (j == a.length() && i < b.length()) return 0;
    }
    return 1;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  long long int i, j, k;
  cin >> t;
  long long int x = t;
  while (t--) {
    long long int n, h, f = 0;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    h = a[n - 1];
    for (i = n - 2; i >= 0; i--) {
      if (a[i] > h) {
        f++;
        h = a[i];
      }
    }
    cout << f;
    cout << endl;
  }
}
