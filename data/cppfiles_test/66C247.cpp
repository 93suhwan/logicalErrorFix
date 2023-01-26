#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N];
int n, i, cnt;
int main() {
  for (i = 1; i < N; i++) {
    if (i % 3 == 0 || (i % 10 == 3)) {
      continue;
    }
    a[++cnt] = i;
  }
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << a[n] << endl;
  }
}
