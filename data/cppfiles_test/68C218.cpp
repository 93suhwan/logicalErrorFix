#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int t;
int n;
int k;
int a1[N];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    int i, j, y, y1;
    i = sqrt(n);
    if (i * i < n) i = i + 1;
    y1 = i * i;
    j = (i - 1) * (i - 1);
    y = (y1 - j + 1) / 2 + j;
    if (n == y) cout << i << " " << i << endl;
    if (n > y) cout << i << " " << i - (n - y) << endl;
    if (n < y) cout << i - (y - n) << " " << i << endl;
  }
}
