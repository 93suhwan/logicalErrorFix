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
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    sum += x;
  }
  long long h_min = sum / n;
  long long h_max = ceil((double)sum / n);
  cout << h_max - h_min << endl;
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
