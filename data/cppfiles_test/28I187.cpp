#include <bits/stdc++.h>
using namespace std;
const long long int MOD = (long long int)1e9 + 7;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b = b >> 1;
  }
  return res % MOD;
}
long long int num_swaps(vector<long long int> &arr, long long int k) {
  long long int n = arr.size();
  for (long long int i = 0; i < n; i++) {
    arr[i] = (n + arr[i] + k) % n;
  }
  vector<long long int> vis(n, 0);
  long long int cnt_cycles = 0;
  for (long long int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      cnt_cycles++;
      long long int cur_node = i;
      while (1) {
        cur_node = arr[cur_node];
        if (vis[cur_node] == 1) {
          break;
        }
        vis[cur_node] = 1;
      }
    }
  }
  return (n - cnt_cycles);
}
void solve(long long int testnum) {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> a(n), b(n, 0), ans;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (long long int i = 0; i < n; i++) {
    long long int tmp = (n + i - a[i]) % n;
    b[tmp]++;
  }
  long long int cnt = 0;
  for (long long int i = 0; i < n; i++) {
    if (b[i] >= n - 2 * m && num_swaps(a, i) <= m) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << " ";
  for (long long int val : ans) {
    cout << val << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve(i);
  }
}
