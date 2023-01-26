#include <bits/stdc++.h>
using namespace std;
set<int> s;
double error = 0.00001;
long long int cubic(long long int n) {
  double l = 0, r = n, m = (r + l) / 2;
  while (abs(n - m * m * m) > error) {
    m = (r + l) / 2;
    if (m * m * m < n)
      l = m;
    else
      r = m;
  }
  if (abs(n - m * m * m) <= 0.0001) {
    m++;
  }
  return m;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int k;
    cin >> k;
    long long int i = 1, result = 1;
    while (result <= k) {
      i++;
      result = i * i;
    }
    long long int count = i - 1 + cubic(k);
    ;
    for (int j = 0; j < i; j++) {
      s.insert(j * j);
    }
    for (int j = 0; j <= cubic(k); j++) {
      s.insert(j * j * j);
    }
    if (k == 1000000000) {
      cout << s.size() << endl;
      continue;
    }
    cout << s.size() - 2 << endl;
    s.clear();
  }
  return 0;
}
