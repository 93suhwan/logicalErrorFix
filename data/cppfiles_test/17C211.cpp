#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int a[M];
int b[M];
int vis[M];
map<int, int> mp;
int tree[M];
int lowerbit(int x) { return x & (-x); }
void add(int x, int y) {
  for (int i = x; i < M; i += lowerbit(i)) {
    tree[i] += y;
  }
}
long long int query(int x) {
  long long int ans = 0;
  for (int i = x; i > 0; i -= lowerbit(i)) {
    ans = ans + (long long int)tree[i];
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i) {
      if (mp.count(b[i]) == 0) mp[b[i]] = i;
    }
    long long int ans = 0;
    add(mp[a[1]], 1);
    for (int i = 2; i <= n; ++i) {
      long long int z = query(mp[a[i]] - 1);
      long long int z1 = i - 1 - query(mp[a[i]]);
      ans = ans + min(z1, (long long int)z);
      add(mp[a[i]], 1);
    }
    for (int i = 1; i <= n; ++i) {
      add(mp[a[i]], -1);
    }
    cout << ans << endl;
  }
}
