#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void input_output() {}
void print_time(high_resolution_clock::time_point start) {
  high_resolution_clock::time_point stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
}
bool helper(int n, int m, int k, vector<string> &ans) {
  int i, j;
  int nums = (n * m) / 2;
  if (k > n * (m / 2)) {
    return false;
  } else {
    int cols_rem = m - 2 * ((k / n) + (k % n != 0));
    int xtra = (n - k % n) % n;
    if (nums - k > (cols_rem * (n / 2) + (xtra / 2) * 2)) {
      return false;
    }
    for (i = 0; i < n; ++i) {
      ans.push_back("");
      for (j = 0; j < m; ++j) {
        ans[i].push_back('.');
      }
    }
    int temp = 0;
    bool flip = false;
    bool flip2 = false;
    for (j = 0; j < m; j += 2) {
      if (temp >= k) break;
      if (!flip2)
        flip = false;
      else
        flip = true;
      for (i = 0; i < n; ++i) {
        if (temp >= k) break;
        if (!flip) {
          ans[i][j] = 'a';
          ans[i][j + 1] = 'a';
          flip = true;
        } else {
          ans[i][j] = 'b';
          ans[i][j + 1] = 'b';
          flip = false;
        }
        temp++;
      }
      flip2 = !flip2;
    }
    flip = false;
    flip2 = false;
    for (i = 0; i < n; i += 2) {
      if (!flip2)
        flip = false;
      else
        flip = true;
      for (j = 0; j < m; ++j) {
        if (ans[i][j] != '.') continue;
        if (!flip) {
          ans[i][j] = 'x';
          ans[i + 1][j] = 'x';
          flip = true;
        } else {
          ans[i][j] = 'y';
          ans[i + 1][j] = 'y';
          flip = false;
        }
      }
      flip2 = !flip2;
    }
  }
  return true;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int i, j;
  int nums = (n * m) / 2;
  int xtra = 0;
  bool ans;
  vector<string> v;
  if (n % 2 == 0) {
    ans = helper(n, m, k, v);
    if (ans) {
      cout << "YES\n";
      for (i = 0; i < n; ++i) cout << v[i] << '\n';
    } else
      cout << "NO\n";
  } else {
    ans = helper(m, n, nums - k, v);
    if (ans) {
      cout << "YES\n";
      for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
          cout << v[j][i];
        }
        cout << '\n';
      }
    } else
      cout << "NO\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input_output();
  high_resolution_clock::time_point start = high_resolution_clock::now();
  int t;
  cin >> t;
  while (t--) solve();
  print_time(start);
  return 0;
}
