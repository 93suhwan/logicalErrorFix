#include <bits/stdc++.h>
using namespace std;
int add(int x, int y) { return (1ll * x + 1ll * y) % 1000000007; }
int del(int x, int y) {
  return ((1ll * x - 1ll * y) % 1000000007 + 1000000007) % 1000000007;
}
int mul(int x, int y) { return (1ll * x * 1ll * y) % 1000000007; }
bool isPrime(long long int n) {
  if (n <= 1) return false;
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long int mx = arr[n - 1];
  long long int count = 0;
  for (long long int i = n - 1; i >= 0; i--)
    if (arr[i] > mx) count++, mx = arr[i];
  cout << count << "\n";
}
int main() {
  long long int t;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
