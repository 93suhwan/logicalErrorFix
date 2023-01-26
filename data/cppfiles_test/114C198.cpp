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
    int ar[n];
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
    }
    sort(ar, ar + n);
    for (int i = 0; i < n / 2; i++) {
      cout << ar[i + 1] << " " << ar[0] << "\n";
    }
  }
}
