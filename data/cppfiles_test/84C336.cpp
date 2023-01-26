#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, mod = 1e9 + 7;
int a[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    int l = n / 2 + 1, st = n / 2;
    cout << ((s - st + l - 1) / l) << endl;
  }
  return 0;
}
