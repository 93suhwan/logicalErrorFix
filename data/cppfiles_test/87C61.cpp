#include <bits/stdc++.h>
using namespace std;
void test() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((i + 1 + cnt) < a[i]) {
      cnt = a[i] - (i + 1);
    }
  }
  cout << cnt << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) test();
}
