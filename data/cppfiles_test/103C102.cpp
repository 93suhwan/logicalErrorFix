#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  } else {
    return -1;
  }
}
ll power(ll x, ll y) {
  ll res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int N = 2001;
string arr[N];
pair<int, int> g[N][N];
bool visited[N][N];
int dp[N][N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = (0); i < (n); i++) {
    cin >> arr[i];
    for (int j = (0); j < (m); j++) {
      if (arr[i][j] == 'L')
        g[i + 1][j + 1] = {i + 1, j};
      else if (arr[i][j] == 'R')
        g[i + 1][j + 1] = {i + 1, j + 2};
      else if (arr[i][j] == 'D')
        g[i + 1][j + 1] = {i + 2, j + 1};
      else
        g[i + 1][j + 1] = {i, j + 1};
    }
  }
  int i = 1;
  int best = 0;
  pair<int, int> ans;
  while (i <= n) {
    int j = 1;
    while (j <= m) {
      int start_x = i, start_y = j;
      int x, y;
      set<pair<int, int>> s;
      s.insert({i, j});
      int d = 0;
      pair<int, int> p = {0, 0};
      while (!visited[i][j] && i > 0 && i <= n && j > 0 && j <= m) {
        visited[i][j] = true;
        d++;
        x = g[i][j].first;
        y = g[i][j].second;
        i = x;
        j = y;
        if (!s.count({i, j}))
          s.insert({i, j});
        else {
          p.first = i;
          p.second = j;
          break;
        }
      }
      if (p.first == 0) {
        if (i == 0 || i > n || j == 0 || j > m) {
          i = start_x;
          j = start_y;
          while (i > 0 && i <= n && j > 0 && j <= m) {
            dp[i][j] = d;
            d--;
            x = g[i][j].first;
            y = g[i][j].second;
            i = x;
            j = y;
          }
        } else {
          int end_x = i, end_y = j;
          i = start_x;
          j = start_y;
          while (i != end_x || j != end_y) {
            dp[i][j] = d + dp[end_x][end_y];
            d--;
            x = g[i][j].first;
            y = g[i][j].second;
            i = x;
            j = y;
          }
        }
      } else {
        int end_x = p.first, end_y = p.second;
        i = start_x;
        j = start_y;
        while (i != end_x || j != end_y) {
          dp[i][j] = d;
          d--;
          x = g[i][j].first;
          y = g[i][j].second;
          i = x;
          j = y;
        }
        dp[i][j] = d;
        x = g[i][j].first;
        y = g[i][j].second;
        i = x;
        j = y;
        while (i != end_x || j != end_y) {
          dp[i][j] = dp[end_x][end_y];
          x = g[i][j].first;
          y = g[i][j].second;
          i = x;
          j = y;
        }
      }
      i = start_x;
      j = start_y;
      j++;
    }
    i++;
  }
  for (int i = (1); i < (n + 1); i++) {
    for (int j = (1); j < (m + 1); j++) {
      if (best < dp[i][j]) {
        best = dp[i][j];
        ans.first = i;
        ans.second = j;
      }
    }
  }
  cout << ans.first << " " << ans.second << " " << best << '\n';
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    memset(visited, false, sizeof(visited));
    solve();
  }
  return 0;
}
