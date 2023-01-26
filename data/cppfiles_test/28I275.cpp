#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
long long int MOD1 = 998244353;
void printarr(vector<long long int>& arr) {
  for (auto i : arr) cout << i << " ";
  cout << endl;
}
long long int powermod(long long int n, long long int p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  if (p % 2 == 0) {
    long long int smallans = powermod(n, p / 2);
    return (smallans * smallans) % MOD;
  } else {
    long long int smallans = powermod(n, p / 2);
    return ((smallans * smallans) % MOD * n) % MOD;
  }
}
long long int GCD(long long int a, long long int b) {
  if (a == 0) {
    return b;
  }
  return GCD(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    c = c % 2;
    b = b % 2;
    a = a % 2;
    if (a == 1 && b == 1 && c == 1) {
      cout << 0 << endl;
    } else if (c == 0) {
      if (a == 0 && b == 0) {
        cout << 0 << endl;
      } else if (b == 0) {
        cout << 1 << endl;
      } else if (a == 0) {
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    } else if (b == 0) {
      if (a == 0) {
        cout << 3 << endl;
      } else if (c == 0) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    } else if (a == 0) {
      if (b == 0) {
        cout << 3 << endl;
      } else if (c == 0) {
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    }
  }
  return 0;
}
