#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int mod) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b = b / 2;
  }
  return ans;
}
vector<long long int> fact(100);
void pre_fact(long long int m) {
  fact[0] = 1;
  for (long long int i = 1; i < 100; i++) fact[i] = (fact[i - 1] * i) % m;
}
long long int ncr(long long int n, long long int r, long long int m) {
  return (fact[n] * (power((fact[n - r] * fact[r]) % m, m - 2, m))) % m;
}
void print(long long int n) {
  for (long long int i = 1; i <= n; i++) {
    cout << '(';
  }
  for (long long int i = 1; i <= n; i++) {
    cout << ")";
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int n;
    cin >> n;
    for (long long int i = 1; i <= n; i++) {
      print(i);
      print(n - i);
      cout << endl;
    }
  }
}
