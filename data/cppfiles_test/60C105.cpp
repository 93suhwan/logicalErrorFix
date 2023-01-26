#include <bits/stdc++.h>
using namespace std;
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
const long long N = 1e6 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int test, cs = 1;
  cin >> test;
  while (test--) {
    int n, i, j;
    cin >> n;
    cin >> j;
    for (i = 1; i < n; i++) {
      int a;
      cin >> a;
      j &= a;
    }
    cout << j << endl;
  }
}
