#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res % M * a % M) % M;
    a = (a % M * a % M) % M;
    b >>= 1;
  }
  return res % M;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void testmetal() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  for (long long i = 1; i < n + 1; i++) {
    int x;
    cout << "? ";
    for (long long j = 0; j < n - 1; j++) {
      cout << i + 1 << " ";
    }
    cout << 1 << " ";
    cout << endl;
    cin >> x;
    if (x == 0) {
      a[n] = i;
      break;
    } else {
      a[x] = (-i);
    }
  }
  for (long long i = 1; i < n + 1; i++) {
    int x;
    cout << "? ";
    for (long long j = 0; j < n - 1; j++) {
      cout << 1 << " ";
    }
    cout << i + 1 << endl;
    cin >> x;
    if (x == 0) {
      break;
    } else {
      a[x] = i;
    }
  }
  cout << "! ";
  for (long long i = 1; i < n; i++) {
    cout << a[i] + a[n] << " ";
  }
  cout << a[n] << endl;
}
int main() {
  long long t;
  t = 1;
  while (t--) {
    testmetal();
  }
  return 0;
}
