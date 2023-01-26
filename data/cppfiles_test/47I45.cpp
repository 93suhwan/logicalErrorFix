#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, k, a[N];
inline int sum(int i, int j) {
  int x, y;
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
  int _12 = sum(1, 2);
  int _13 = sum(1, 3);
  int _23 = sum(2, 3);
  int _123 = (_12 + _13 + _23) / 2;
  a[1] = _123 - _23;
  a[2] = _123 - _13;
  a[3] = _123 - _12;
  for (int i = 3; i < n; i++) a[i + 1] = sum(i, i + 1) - a[i];
  sort(a + 1, a + n + 1);
  cout << "finish " << a[k];
  return 0;
}
