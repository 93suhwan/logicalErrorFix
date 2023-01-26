#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
long long int ar[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    for (int i = 2; i <= n + 1; i++) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
