#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
using namespace std;
template <typename val1>
void __f(const char* name, val1&& value) {
  cout << name << " = " << value << endl;
}
template <typename val1, typename... values>
void __f(const char* names, val1&& value, values&&... multiplevalue) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " = " << value << " ";
  __f(comma + 1, multiplevalue...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> trees(2 * n, 0);
  int arr[n + 1];
  function<int(int)> query = [&](int a) {
    int ans = 0;
    while (a) {
      ans = max(trees[a], ans);
      a = a - (a & (-a));
    }
    return ans;
  };
  function<void(int, int)> update = [&](int a, int v) {
    while (a < 2 * n) {
      trees[a] = max(trees[a], v);
      a = a + (a & (-a));
    }
  };
  int ans = 0;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = n; i >= 1; i--) {
    if (i < arr[i]) continue;
    int off = i - arr[i] + 1;
    int fc = query(off);
    ans = max(ans, fc + 1);
    update(off, fc + 1);
  }
  cout << ans << endl;
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
