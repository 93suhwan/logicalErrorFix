#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], p;
void init() {
  for (int i = 1; p <= 1000; i++) {
    if (i % 3 == 0 || i % 10 == 3)
      continue;
    else
      a[++p] = i;
  }
}
int main() {
  init();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << a[n] << endl;
  }
  return 0;
}
