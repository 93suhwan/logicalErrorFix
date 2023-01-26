#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> adj[200005], adj_rev[200005];
int xMove[] = {0, 1, 0, -1, 1, 1, -1, -1, 2, 2, -2, -2, 1, 1, -1, -1};
int yMove[] = {1, 0, -1, 0, 1, -1, 1, -1, 1, -1, 1, -1, 2, -2, 2, -2};
int main() {
  cin.tie(0), cout.tie(0);
  ios_base::sync_with_stdio(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  int TC = 1;
  int n, k, m, q;
  cin >> TC;
  int x[300005];
  x[0] = 0;
  for (int i = 1; i <= 300000; i++) x[i] = (i ^ x[i - 1]);
  for (int t1 = 1; t1 <= TC; t1++) {
    int a, b;
    cin >> a >> b;
    int cur_xor = x[a - 1];
    int needed = cur_xor ^ b;
    if (cur_xor == b)
      cout << a << "\n";
    else if (needed != a)
      cout << a + 1 << "\n";
    else {
      cout << a + 2 << "\n";
    }
  }
  return 0;
}
