#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q, m;
  char c;
  vector<long long> prefix_sum = {0};
  cin >> n >> m;
  vector<vector<bool> > grid(n, vector<bool>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      grid[i][j] = (c == 'X');
    }
  }
  for (int j = 1; j < m; j++) {
    long long sum = 0;
    for (int i = 1; i < n; i++) {
      if (grid[i - 1][j] and grid[i][j - 1]) sum++;
    }
    prefix_sum.push_back(prefix_sum[j - 1] + sum);
  }
  cout << endl;
  cin >> q;
  long long a, b;
  while (q--) {
    cin >> a >> b;
    if (prefix_sum[b - 1] - prefix_sum[a - 1] > 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
