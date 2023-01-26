#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a[1000];
  a[0] = 1;
  int cur = 1;
  for (int i = 1; i < 1000; i++) {
    cur++;
    while (cur % 3 == 0 or cur % 10 == 3) cur++;
    a[i] = cur;
  }
  int t;
  cin >> t;
  while (t--) {
    int temp;
    cin >> temp;
    cout << a[temp - 1] << endl;
  }
  return 0;
}
