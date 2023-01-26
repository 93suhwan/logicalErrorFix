#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
const long long N = 1e6 + 2;
long long mod(long long x, long long y = MOD) { return ((x % y) + y) % y; }
long long addm(long long x) { return x; }
template <typename... Ts>
long long addm(long long x, Ts... ys) {
  return mod(x + addm(ys...));
}
long long mulm(long long x) { return x; }
template <typename... Ts>
long long mulm(long long x, Ts... ys) {
  return mod(x * mulm(ys...));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    pair<long long, long long> arr[n];
    vector<long long> loop;
    int visited[n];
    memset(visited, 0, sizeof visited);
    ;
    for (long long i = (0); i < (n); i++) {
      int a;
      cin >> a;
      arr[i] = pair<long long, long long>(a, i);
    }
    sort(arr, arr + n);
    bool flag = false;
    for (long long i = (1); i < (n - 1); i++) {
      if (arr[i].first == arr[i - 1].first) flag = true;
    }
    if (flag) {
      cout << "YES\n";
      continue;
    }
    int count = 0;
    int oddcount = 0;
    for (long long i = (0); i < (n); i++) {
      if (visited[i]) continue;
      int u = i;
      int cnt = 0;
      while (!visited[u]) {
        cnt++;
        visited[u] = 1;
        u = arr[u].second;
      }
      if (cnt % 2 == 0)
        count++;
      else
        oddcount++;
    }
    if (count % 2 == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
