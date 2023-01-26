#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i) is >> vec[i];
  return is;
}
template <class T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  for (auto& t : vec) os << t << " ";
  return os;
}
struct query {
  int l, k;
  int idx;
  int ans;
};
void dfs(vector<vector<int>>& V, vector<int>& A, int v,
         vector<vector<query>>& Q, vector<set<int>>& S, map<int, int>& cnt,
         int maxsz) {
  cnt[A[v]]++;
  int newcnt = cnt[A[v]];
  if (newcnt > 1) S[newcnt - 1].erase(A[v]);
  S[newcnt].insert(A[v]);
  maxsz = max(maxsz, newcnt + 1);
  for (auto& q : Q[v]) {
    int tot = 0;
    for (int i = q.l; i < maxsz; ++i) {
      tot += S[i].size();
      if (tot >= q.k) {
        q.ans = *S[i].begin();
        break;
      }
    }
  }
  for (int x : V[v]) {
    dfs(V, A, x, Q, S, cnt, maxsz);
  }
}
void st() {
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  cin >> A;
  vector<vector<int>> V(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    p--;
    V[p].push_back(i);
  }
  vector<vector<query>> Q(n);
  for (int i = 0; i < q; ++i) {
    int v, l, k;
    cin >> v >> l >> k;
    Q[v - 1].push_back({l, k, i, -1});
  }
  vector<set<int>> S(n + 1);
  map<int, int> cnt;
  dfs(V, A, 0, Q, S, cnt, 0);
  vector<int> ans(q);
  for (int i = 0; i < n; ++i) {
    for (auto& qq : Q[i]) {
      ans[qq.idx] = qq.ans;
    }
  }
  cout << ans << (char)10;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    if (t < 50) {
      cerr << "-------------------" << (char)10;
    }
    st();
  }
}
