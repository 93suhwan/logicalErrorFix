#include <bits/stdc++.h>
using namespace std;
char mat[1001][1001];
char path[1001][1001];
bool vis[1001][1001];
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
long long int power(long long int a, long long int n) {
  long long int ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans = (ans * a) % 1000001;
    }
    n = n / 2;
    a = (a * a) % 1000001;
  }
  return ans;
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
void solve() {
  long long int n, j = 2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << j + i << " ";
  }
  cout << endl;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
