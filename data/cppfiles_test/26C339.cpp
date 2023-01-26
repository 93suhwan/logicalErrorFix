#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int md = 1e9 + 7;
int main() {
  int qt, n;
  cin >> qt;
  a[1] = 1;
  a[2] = 1;
  for (int i = 3; i < 200010; i++) a[i] = a[i - 1] * i % md;
  while (qt--) {
    cin >> n;
    cout << a[2 * n] << endl;
  }
  return 0;
}
