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
  int minn = min(p1, p2);
  p1 -= minn;
  p2 -= minn;
  if (p1 >= 7) {
    cout << ">"
         << "\n";
  } else if (p2 >= 7) {
    cout << "<"
         << "\n";
  } else {
    for (int i = 0; i < p1; i++) {
      x1 *= 10;
    }
    for (int i = 0; i < p2; i++) {
      x2 *= 10;
    }
    if (x1 > x2) {
      cout << ">"
           << "\n";
    } else if (x1 < x2) {
      cout << "<"
           << "\n";
    } else {
      cout << "="
           << "\n";
    }
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
