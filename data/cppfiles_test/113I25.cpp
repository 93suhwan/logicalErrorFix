#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
void maverick() {
  long long x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  int ans1 = 0, ans2 = 0, multiply = 0, multiply1 = 0;
  if (p1 > 0) {
    for (int i = 0; i < p1; i++) {
      multiply *= 10;
    }
    ans1 = multiply * x1;
  } else {
    ans1 = x1;
  }
  if (p2 > 0) {
    for (int i = 0; i < p2; i++) {
      multiply1 *= 10;
    }
    ans2 = multiply1 * x2;
  } else {
    ans2 = x2;
  }
  if (ans1 > ans2) {
    cout << "<"
         << "\n";
  } else if (ans2 > ans1) {
    cout << ">"
         << "\n";
  } else {
    cout << "="
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test_cases;
  cin >> test_cases;
  while (test_cases--) {
    maverick();
  }
  return 0;
}
