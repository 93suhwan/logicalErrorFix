#include <bits/stdc++.h>
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using MaxHeap = std::priority_queue<T>;
using ll = long long;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;
using Pdd = std::pair<double, double>;
template <class T>
bool chmin(T &a, const T b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}
template <class T>
bool chmax(T &a, const T b) {
  if (a < b) {
    a = b;
    return true;
  } else {
    return false;
  }
}
template <class T>
void vdeb(const std::vector<T> &da) {
  auto n = da.size();
  for (size_t i = 0; i < n; i++) {
    if (i == n - 1)
      std::cout << da[i];
    else
      std::cout << da[i] << " ";
  }
  std::cout << std::endl;
}
template <class T>
void vdeb(const std::vector<std::vector<T>> &da) {
  auto n = da.size();
  for (size_t i = 0; i < n; i++) {
    std::cout << i << " : ";
    vdeb(da[i]);
  }
}
template <>
void vdeb(const std::vector<std::string> &da) {
  auto n = da.size();
  for (size_t i = 0; i < n; i++) {
    std::cout << da[i] << std::endl;
  }
}
using namespace std;
const int INF = 1 << 20;
int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<int> da(m + 1, 0);
  for (int i = (1); i < int(m); i++) {
    for (int j = (0); j < int(i); j++) {
      if (t[i] == t[j]) continue;
      bool flg = true;
      for (int k = (0); k < int(j); k++) {
        if (t[i - k - 1] != t[j - k - 1]) {
          flg = false;
          break;
        }
      }
      if (flg) chmax(da[i], j + 1);
    }
  }
  for (int i = (0); i < int(m - 1); i++) {
    bool flg = true;
    for (int j = (0); j < int(i + 1); j++) {
      if (t[m - j - 1] != t[i - j]) {
        flg = false;
        break;
      }
    }
    if (flg) chmax(da[m], i + 1);
  }
  vector<vector<int>> dp0(n + 1, vector<int>(m, INF));
  vector<vector<int>> dp1(n + 1, vector<int>(m, INF));
  dp0[0][0] = 0;
  for (int i = (0); i < int(n); i++) {
    for (int j = (0); j < int(m); j++) {
      if (s[i] == t[j]) {
        if (j == m - 1) {
          for (int k = (0); k < int(n); k++) {
            chmin(dp1[k + 1][da[j + 1]], dp0[k][j]);
            chmin(dp1[k][da[j]], dp0[k][j] + 1);
          }
        } else {
          for (int k = (0); k < int(n + 1); k++) {
            chmin(dp1[k][j + 1], dp0[k][j]);
            chmin(dp1[k][da[j]], dp0[k][j] + 1);
          }
        }
      } else {
        if (j == m - 1) {
          for (int k = (0); k < int(n); k++) {
            chmin(dp1[k + 1][da[j + 1]], dp0[k][j] + 1);
            chmin(dp1[k][da[j]], dp0[k][j]);
          }
        } else {
          for (int k = (0); k < int(n + 1); k++) {
            chmin(dp1[k][j + 1], dp0[k][j] + 1);
            chmin(dp1[k][da[j]], dp0[k][j]);
          }
        }
      }
      for (int k = (0); k < int(n + 1); k++) dp0[k][j] = INF;
    }
    swap(dp0, dp1);
  }
  vector<int> ans(n - m + 2, INF);
  for (int i = (0); i < int(n - m + 2); i++) {
    for (int j = (0); j < int(m); j++) chmin(ans[i], dp0[i][j]);
  }
  for (auto &i : ans)
    if (i == INF) i = -1;
  vdeb(ans);
}
