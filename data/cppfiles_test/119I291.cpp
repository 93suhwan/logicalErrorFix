#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool isPrime(int n) {
  if (n == 1 || n == 0) return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solvecase() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        a[i]++;
        a[j]--;
      }
      sort(a, a + n);
    }
  }
  sort(a, a + n);
  cout << a[n - 1] - a[0] << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    solvecase();
  }
  return 0;
}
