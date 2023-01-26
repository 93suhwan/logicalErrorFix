#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int size;
  cin >> size;
  for (int i = 0; i < size; ++i) {
    int n, m, k;
    cin >> n >> m >> k;
    bool res = (n % 2 == 0 && k % 2 == 0) ||
               (n % 2 != 0 && k >= m / 2 && (k - m / 2) % 2 == 0);
    cout << (res ? "YES\n" : "NO\n");
  }
  return 0;
}
