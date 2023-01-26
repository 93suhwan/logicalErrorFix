#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 1e5 + 10;
const int maxS = 1e6 + 10;
const long long mod = 1e9 + 7;
int n, k, num = 0;
long long f[61];
struct Node {
  int nxt[2], color;
  long long dp[6];
  Node() : nxt(), color(0), dp() {}
} trie[maxS];
vector<pair<long long, int>> vec;
void addNode(long long x, int color) {
  vector<int> a;
  while (x) {
    a.push_back(x & 1);
    x /= 2;
  }
  a.pop_back();
  reverse((a).begin(), (a).end());
  int cur = 0;
  for (auto &b : a) {
    if (!trie[cur].nxt[b]) {
      trie[cur].nxt[b] = ++num;
    }
    cur = trie[cur].nxt[b];
  }
  trie[cur].color = color;
}
void dfs(int cur, int depth) {
  if (trie[cur].nxt[0]) {
    dfs(trie[cur].nxt[0], depth - 1);
  }
  if (trie[cur].nxt[1]) {
    dfs(trie[cur].nxt[1], depth - 1);
  }
  if (depth == 1) {
    if (trie[cur].color) {
      trie[cur].dp[trie[cur].color - 1] = 1;
    } else {
      for (int i = 0; i < (int)(6); ++i) {
        trie[cur].dp[i] = 1;
      }
    }
    return;
  }
  for (int i = 0; i < (int)(6); ++i) {
    for (int j = 0; j < (int)(6); ++j) {
      for (int k = 0; k < (int)(6); ++k) {
        if (j != i && j != (i ^ 1) && k != i && k != (i ^ 1)) {
          long long L, R;
          if (!trie[cur].nxt[0]) {
            L = f[depth - 1];
          } else {
            L = trie[trie[cur].nxt[0]].dp[j];
          }
          if (!trie[cur].nxt[1]) {
            R = f[depth - 1];
          } else {
            R = trie[trie[cur].nxt[1]].dp[k];
          }
          if (!trie[cur].color || i + 1 == trie[cur].color) {
            trie[cur].dp[i] = (trie[cur].dp[i] + L * R) % mod;
          }
        }
      }
    }
  }
}
void solve() {
  cin >> k >> n;
  f[1] = 1;
  for (int i = (int)(2); i <= (int)(60); ++i) {
    f[i] = f[i - 1] * f[i - 1] % mod * 16 % mod;
  }
  for (int i = 1; i <= (int)(n); ++i) {
    long long x;
    string s;
    cin >> x >> s;
    if (s == "white") {
      addNode(x, 1);
    } else if (s == "yellow") {
      addNode(x, 2);
    } else if (s == "green") {
      addNode(x, 3);
    } else if (s == "blue") {
      addNode(x, 4);
    } else if (s == "red") {
      addNode(x, 5);
    } else if (s == "orange") {
      addNode(x, 6);
    }
  }
  dfs(0, k);
  long long ans = 0;
  for (int i = 0; i < (int)(6); ++i) {
    ans = (ans + trie[0].dp[i]) % mod;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
