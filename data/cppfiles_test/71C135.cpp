#include <bits/stdc++.h>
using namespace std;
long long a, b;
set<long long> s, y;
void func(int l, long long num) {
  if (l <= 0) {
    s.insert(num);
    return;
  }
  func(l - 1, num * 10 + a);
  func(l - 1, num * 10 + b);
}
void fuck(int l, long long num) {
  if (l <= 0) {
    y.insert(num);
    return;
  }
  fuck(l - 1, num * 10 + a);
}
int main() {
  for (int i = 1; i <= 9; i++) s.insert(i);
  for (int i = 2; i <= 11; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        a = j, b = k;
        func(i, 0);
      }
    }
  }
  for (int i = 1; i <= 11; i++)
    for (int j = 0; j <= 9; j++) {
      a = j;
      fuck(i, 0);
    }
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (k == 2)
      cout << *(s.lower_bound(n)) << endl;
    else
      cout << *(y.lower_bound(n)) << endl;
  }
  return 0;
}
