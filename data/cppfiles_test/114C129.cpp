#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, mod = 1e9 + 7, inf = 0x3f3f3f3f;
int a[N];
void Test() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= 2 + n / 2 - 1; i++) {
    cout << a[i] << " " << a[1] << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) Test();
}
