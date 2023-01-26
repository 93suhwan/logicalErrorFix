#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long n, k, a[N];
inline long long sum(int i, int j) {
  long long x, y;
  cout << "and " << i << ' ' << j << endl;
  fflush(stdout);
  cin >> x;
  cout << "or " << i << ' ' << j << endl;
  fflush(stdout);
  cin >> y;
  return x + y;
}
int main() {
  cin >> n >> k;
  long long _12 = sum(1, 2);
  long long _13 = sum(1, 3);
  long long _23 = sum(2, 3);
  long long _123 = (_12 + _13 + _23) / 2;
  a[1] = _123 - _23;
  a[2] = _123 - _13;
  a[3] = _123 - _12;
  for (int i = 3; i < n; i++) a[i + 1] = sum(i, i + 1) - a[i];
  sort(a + 1, a + n + 1);
  cout << "finish " << a[k];
  return 0;
}
