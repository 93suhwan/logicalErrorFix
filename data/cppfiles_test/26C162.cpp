#include <bits/stdc++.h>
using namespace std;
int cal(long long int a, long long int b, long long int mod) {
  long long int ans = 1;
  long long int temp = a;
  while (b > 0) {
    if (b & 1) ans = (ans % mod * temp % mod) % mod;
    temp = (temp % mod * temp % mod) % mod;
    b = b / 2;
  }
  return ans;
}
int XOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  if (n % 4 == 3) return 0;
}
void sieve(int n) {
  int a[n];
  for (int i = 0; i < n; i++) {
    a[i] = 1;
    a[0] = 0;
    a[1] = 0;
  }
  for (int i = 2; i * i < n; i++) {
    if (a[i] == 1) {
      for (int j = i * i; j < n; j = j + i) a[j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) cout << i << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, x, mod = 1000000007;
    cin >> n;
    long long int f = 1, i = 1;
    x = 2 * n - 1;
    while (x--) {
      f = (f % mod * i % mod) % mod;
      i++;
    }
    cout << (f * n) % mod << endl;
  }
}
