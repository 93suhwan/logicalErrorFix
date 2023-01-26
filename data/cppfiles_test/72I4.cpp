#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e9;
long long x1, x2, y11, y2;
long long query(long long a, long long b) {
  long long x;
  cout << "? " << a << " " << b << endl;
  cin >> x;
  return x;
}
int main() {
  long long x, y;
  x = query(1, 1);
  y = query(MAX, 1);
  long long i = (MAX + 1 + x - y) / 2;
  long long j = x + 2 - i;
  if (j < 1) j = 1;
  int a = query(i, j);
  if (a == -1) assert(0);
  long long c1 = j + a;
  long long l1 = x + 2 - c1;
  long long l2 = c1 + (MAX - y - 1);
  long long c2 = MAX - query(i, MAX);
  cout << "! " << l1 << " " << c1 << " " << l2 << " " << c2 << endl;
  return 0;
}
