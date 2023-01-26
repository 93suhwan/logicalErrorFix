#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
const int MOD = 1e9 + 7;
const int MAX_N = 2e5 + 5;
void FASTIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n, k;
pair<pii, int> A[MAX_N];
int T[MAX_N];
vi Adj[MAX_N];
bool visited[MAX_N];
int dfs(int u) {
  visited[u] = true;
  int mn = T[u];
  for (int v : Adj[u]) {
    if (!visited[v]) {
      mn = min(mn, dfs(v));
    }
  }
  return mn;
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    Adj[i].clear();
  }
  memset(visited, 0, sizeof(visited[0]) * (n + 1));
  for (int i = 0; i < n; i++) {
    cin >> A[i].first.second >> A[i].first.first >> T[i];
    A[i].second = i;
  }
  sort(A, A + n);
  map<int, pair<pii, int>> M;
  for (int i = 0; i < n; i++) {
    if (M.find(A[i].first.second) != M.end()) {
      if (A[i].first.first - M[A[i].first.second].first.first <= k) {
        Adj[A[i].second].push_back(M[A[i].first.second].second);
        Adj[M[A[i].first.second].second].push_back(A[i].second);
      }
    }
    M[A[i].first.second] = A[i];
  }
  for (int i = 0; i < n; i++) swap(A[i].first.first, A[i].first.second);
  sort(A, A + n);
  M.clear();
  for (int i = 0; i < n; i++) {
    if (M.find(A[i].first.second) != M.end()) {
      if (A[i].first.first - M[A[i].first.second].first.first <= k) {
        Adj[A[i].second].push_back(M[A[i].first.second].second);
        Adj[M[A[i].first.second].second].push_back(A[i].second);
      }
    }
    M[A[i].first.second] = A[i];
  }
  vi MN;
  for (int i = 0; i < n; i++) {
    if (visited[A[i].second]) continue;
    MN.push_back(dfs(A[i].second));
  }
  sort((MN).begin(), (MN).end());
  int m = MN.size();
  int ans = m - 1;
  ans = min(ans, MN.back());
  for (int i = m - 1; i >= 1; i--) {
    ans = min(ans, max(m - 1 - i, MN[i - 1]));
  }
  cout << ans << "\n";
}
int main() {
  FASTIO();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
