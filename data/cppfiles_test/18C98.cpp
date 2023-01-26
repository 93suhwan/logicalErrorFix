#include <bits/stdc++.h>
using namespace std;
long long int sqrt(long long int p) {
  long long int low = 1, high = p, mid;
  while (low < high) {
    mid = (low + high + 1) / 2;
    if (mid * mid > p) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  return low;
}
long long int power(long long int a, long long int p,
                    long long int m = 1000000007) {
  a %= m;
  long long int val = 1;
  while (p > 0) {
    if (p & 1) {
      val = (val * a) % m;
    }
    a = (a * a) % m;
    p >>= 1;
  }
  return (val);
}
int query(unordered_map<long long int, int> &bit, long long int in) {
  int ans = 0;
  in++;
  while (in > 0) {
    ans += bit[in];
    in -= in & (-in);
  }
  return ans;
}
void add(unordered_map<long long int, int> &bit, long long int in) {
  in++;
  while (in < 3 * 1e9) {
    bit[in] += 1;
    in += in & (-in);
  }
}
int dfs(const vector<int> &v, vector<bool> &vis, vector<int> &ans, int i,
        int d) {
  if (vis[i]) {
    return ans[i];
  }
  if (v[i] == 0) {
    return ans[i];
  }
  vis[i] = 1;
  if (dfs(v, vis, ans, (i + d) % v.size(), d) == -1) return -1;
  ans[i] = ans[(i + d) % v.size()] + 1;
  return ans[i];
}
int main() {
  long long int i, j;
  int T = 1;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (i = 0; i < n; ++i) {
      cin >> v[i];
    }
    if (d == n) {
      for (i = 0; i < n; ++i) {
        if (v[i]) break;
      }
      if (i < n) {
        cout << -1 << "\n";
      } else {
        cout << 0 << "\n";
      }
      continue;
    }
    vector<bool> vis(n);
    vector<int> ans(n, -1);
    for (i = 0; i < n; ++i) {
      if (!v[i]) ans[i] = 0;
    }
    for (i = 0; i < n; ++i) {
      if (v[i] && vis[i] == 0) {
        if (dfs(v, vis, ans, i, d) == -1) break;
      }
    }
    if (i < n) {
      cout << -1 << "\n";
    } else {
      cout << *max_element(ans.begin(), ans.end()) << "\n";
    }
  }
}
