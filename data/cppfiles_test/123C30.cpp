#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 100;
vector<long long> L[MAXN];
long long dp[MAXN];
long long H[MAXN];
long long P[MAXN];
void precal(long long nodo, long long padre) {
  P[nodo] = padre;
  dp[nodo] = 1;
  H[nodo] = -1;
  for (auto v : L[nodo]) {
    if (v != padre) {
      precal(v, nodo);
      if (dp[v] + 1 > dp[nodo]) {
        dp[nodo] = dp[v] + 1;
        H[nodo] = v;
      }
    }
  }
}
long long arr[MAXN];
set<pair<long long, long long>> st;
long long contg = 0;
void DFS(long long nodo, long long padre) {
  contg++;
  for (auto v : L[nodo]) {
    if (v != padre && v != H[nodo]) {
      st.insert({dp[v], v});
    }
  }
  if (H[nodo] != -1) {
    DFS(H[nodo], nodo);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long N, K;
  cin >> N >> K;
  for (long long i = 1; i <= N - 1; i++) {
    long long a, b;
    cin >> a >> b;
    L[a].push_back(b);
    L[b].push_back(a);
  }
  precal(1, -1);
  st.insert({dp[1], 1});
  arr[0] = 0;
  long long pos = 0;
  while (st.size()) {
    long long nodo = (*(--st.end())).second;
    st.erase(st.find({dp[nodo], nodo}));
    DFS(nodo, P[nodo]);
    arr[++pos] = contg;
  }
  false;
  for (long long i = pos + 1; i <= N; i++) {
    arr[i] = contg;
  }
  false;
  vector<long long> vvv;
  for (long long i = 0; i <= K; i++) {
    long long maxB = N - arr[i];
    long long minB = 0;
    long long t1 = min(maxB, max(minB, N / 2));
    long long t2 = min(maxB, max(minB, N / 2 - 1));
    long long t3 = min(maxB, max(minB, N / 2 + 1));
    false;
    false;
    false;
    false;
    false;
    false;
    false;
    vvv.push_back(min({(N - i - t1) * (i - t1), (N - i - t2) * (i - t2),
                       (N - i - t3) * (i - t3)}));
  }
  long long res = -1e18;
  for (auto x : vvv) {
    res = max(res, x);
  }
  cout << res << '\n';
  return 0;
}
