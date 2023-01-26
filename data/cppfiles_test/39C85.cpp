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
void testmetal() {
  int n;
  cin >> n;
  bool flag = true;
  vector<int> a(n + 1, 0);
  for (long long i = 1; i < n; i++) {
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
      flag = false;
      break;
    } else {
      a[x] = (-i);
    }
  }
  if (flag) {
    a[n] = n;
  }
  for (long long i = 1; i < n; i++) {
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
