#include <bits/stdc++.h>
using namespace std;
template <typename T>
T max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T max4(T a, T b, T c, T d) {
  return max(max(a, d), max(b, c));
}
template <typename T>
T min3(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T min4(T a, T b, T c, T d) {
  return min(min(a, d), min(b, c));
}
template <typename T>
T binex(T a, T b, T mod) {
  T ans = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, set<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, multiset<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T, class Q>
ostream& operator<<(ostream& os, pair<T, Q> a) {
  os << "| ";
  os << a.first << ", " << a.second << " ";
  return os << "|";
}
template <class P, class Q, class T>
ostream& operator<<(ostream& os, tuple<P, Q, T> a) {
  os << "| " << (get<0>(a)) << ", " << (get<1>(a)) << ", " << (get<2>(a))
     << "|";
  return os;
}
void precomp() {}
void solve() {
  int64_t n, k;
  cin >> n >> k;
  vector<vector<int64_t>> edges(n + 1);
  for (int64_t i = 0; i < n - 1; i++) {
    int64_t a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  if (k == 2) {
    cout << ((n * (n - 1)) / 2) % int64_t(1000000007) << "\n";
    return;
  }
  int64_t fans = 0;
  for (int64_t i = 1; i <= n; i++) {
    int64_t root = i;
    vector<bool> vis(n + 1, false);
    vis[root] = true;
    vector<vector<int64_t>> cnt;
    int64_t maxaa = 0;
    for (auto x : edges[root]) {
      queue<int64_t> sto;
      sto.push(x);
      vis[x] = true;
      vector<int64_t> depth(n + 1, -1);
      int64_t maxa = 0;
      depth[x] = 0;
      while (!sto.empty()) {
        int64_t te = sto.front();
        sto.pop();
        vis[te] = true;
        for (auto x : edges[te]) {
          if (vis[x]) {
            continue;
          }
          sto.push(x);
          depth[x] = depth[te] + 1;
          maxa = depth[x];
        }
      }
      maxaa = max(maxaa, maxa);
      vector<int64_t> temp(maxa + 1);
      for (int64_t i = 1; i <= n; i++) {
        if (depth[i] != -1) {
          temp[depth[i]]++;
        }
      }
      cnt.push_back(temp);
    }
    for (int64_t i = 0; i < cnt.size(); i++) {
      cnt[i].resize(maxaa + 1);
    }
    int64_t ans = 0;
    for (int64_t i = 0; i < maxaa + 1; i++) {
      vector<vector<int64_t>> dp(cnt.size(), vector<int64_t>(k + 1));
      dp[0][0] = 1;
      dp[0][1] = cnt[0][i];
      for (int64_t j = 0; j < cnt.size() - 1; j++) {
        for (int64_t l = 0; l <= k; l++) {
          dp[j + 1][l] += dp[j][l];
          dp[j + 1][l] %= int64_t(1000000007);
          if (l >= k) {
            continue;
          }
          dp[j + 1][l + 1] += (dp[j][l] * cnt[j + 1][i]) % int64_t(1000000007);
          dp[j + 1][l + 1] %= int64_t(1000000007);
        }
      }
      ans += dp[cnt.size() - 1][k];
      ans %= int64_t(1000000007);
    }
    fans += ans;
    fans %= int64_t(1000000007);
  }
  cout << fans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t T;
  cin >> T;
  precomp();
  for (int64_t I = 1; I <= T; I++) {
    solve();
  }
}
