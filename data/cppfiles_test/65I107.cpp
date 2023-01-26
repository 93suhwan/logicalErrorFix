#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int boxproblem(int bounds[], int size, int m, int start = 0);
int solve(int lower[], int upper[], int n, int m);
int solveD(int lower[], int upper[], int n, int m, int d);
int expmod(long long int a, long long int b, int m);
int mu(int a);
int main() {
  int n, m;
  cin >> n >> m;
  int lower[n], upper[n];
  for (int i = 0; i < n; i++) {
    cin >> lower[i] >> upper[i];
  }
  cout << solve(lower, upper, n, m) << endl;
}
int solve(int lower[], int upper[], int n, int m) {
  int result = 0;
  for (int d = 1; d <= 10000; d++) {
    result += mu(d) * solveD(lower, upper, n, m, d);
    result %= P;
  }
  return result;
}
int solveD(int lower[], int upper[], int n, int m, int D) {
  int diffs[n];
  int newM = m / D;
  for (int i = 0; i < n; i++) {
    int new_lower = (lower[i] - 1) / D + 1;
    int new_upper = upper[i] / D;
    if (new_lower > new_upper) return 0;
    diffs[i] = new_upper - new_lower;
    newM -= new_lower;
  }
  int ans = boxproblem(diffs, n, newM);
  return boxproblem(diffs, n, newM);
}
int boxproblem(int bounds[], int size, int m, int start) {
  int min_element = 99999999;
  int sum = 0;
  long long prod = 1;
  if (m < 0) return 0;
  for (int i = start; i < size; i++) {
    int val = bounds[i];
    min_element = min(min_element, val);
    sum += val;
    prod = (prod * (bounds[i] + 1)) % P;
  }
  if (m >= sum) {
    return prod;
  }
  if (m <= min_element) {
    long long numerator = 1;
    long long denominator = 1;
    for (int i = 1; i <= size - start; i++) {
      numerator = (numerator * (m + i)) % P;
      denominator = (denominator * i) % P;
    }
    return (numerator * expmod(denominator, P - 2, P)) % P;
  }
  int result = 0;
  for (int i = 0; i <= bounds[i]; i++) {
    result += boxproblem(bounds, size, m - i, start + 1);
    result %= P;
  }
  return result;
}
int expmod(long long int a, long long int b, int m) {
  int res = 1;
  a = a % m;
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return res;
}
int mu(int a) {
  int primefactors = 0;
  if (a % 4 == 0)
    return 0;
  else if (a % 2 == 0)
    return -mu(a / 2);
  int p = 3;
  while (a > 1) {
    if (a % p == 0) {
      a = a / p;
      primefactors += 1;
      if (a % p == 0) {
        return 0;
      }
    }
    p += 2;
  }
  if (primefactors & 1) return -1;
  return 1;
}
