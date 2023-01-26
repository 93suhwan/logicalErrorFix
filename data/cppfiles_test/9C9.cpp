#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int n) { return rng() % (n + 1); }
using ll = long long;
ll inf_ll = 9e18;
int inf_int = 2e9;
int grid[1000005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i * m + j];
    }
  }
  int c[k];
  for (int i = 0; i < k; i++) {
    int temp;
    cin >> temp;
    c[i] = temp - 1;
  }
  for (auto j : c) {
    int i = 0;
    while (i < n) {
      if (grid[i * m + j] == 1) {
        grid[i * m + j] = 2;
        j++;
      } else if (grid[i * m + j] == 3) {
        grid[i * m + j] = 2;
        j--;
      } else {
        i++;
      }
    }
    cout << j + 1 << " ";
  }
  return 0;
}
