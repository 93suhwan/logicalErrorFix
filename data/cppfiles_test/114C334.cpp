#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int MOD = 1e9 + 7;
int dd(int a, int b, int c, int d) { return abs(a - c) + abs(b - d); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n], mi = INT_MAX;
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
      mi = min(mi, ar[i]);
    }
    int x = n / 2;
    for (int i = 0; i < n; i++) {
      if (ar[i] == mi) {
        continue;
      }
      x--;
      cout << ar[i] << " " << mi << endl;
      if (x == 0) {
        break;
      }
    }
  }
}
