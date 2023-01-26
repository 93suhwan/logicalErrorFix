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
template <typename IntType>
struct BinaryIndexedTreeAdd {
  int n;
  vector<IntType> elems;
  BinaryIndexedTreeAdd(int n_) {
    n = n_ + 2;
    elems.assign(n, 0);
  }
  void __add(int idx, IntType v) {
    idx++;
    while (idx < n) {
      elems[idx] += v;
      idx += (idx & (-idx));
    }
  }
  IntType __prefix(int idx) {
    IntType res = 0;
    while (idx > 0) {
      res += elems[idx];
      idx ^= (idx & (-idx));
    }
    return res;
  }
  void add(IntType v, int l, int r) {
    __add(l, v);
    __add(r, -v);
  }
  IntType get(int idx) { return __prefix(idx + 1); }
};
using BitAdd = BinaryIndexedTreeAdd<int>;
void dfs(vector<vector<int>>& V, vector<int>& A, int v,
         vector<vector<query>>& Q, vector<set<int>>& S, map<int, int>& cnt,
         BitAdd& ba) {
  cnt[A[v]]++;
  int newcnt = cnt[A[v]];
  if (newcnt > 1) {
    S[newcnt - 1].erase(A[v]);
    ba.add(-1, newcnt - 1, newcnt);
  } else {
    ba.add(1, 1, A.size() + 1);
  }
  S[newcnt].insert(A[v]);
  for (auto& q : Q[v]) {
    int b = 1, e = A.size() + 2;
    int targ = ba.get(q.l - 1) + q.k - 1;
    while (b < e) {
      int t = (b + e) / 2;
      if (ba.get(t) <= targ)
        b = t + 1;
      else
        e = t;
    }
    if (b < A.size() + 1 && ba.get(b) > targ) {
      assert(S[b].size() > 0);
      q.ans = *S[b].begin();
    }
  }
  for (int x : V[v]) {
    dfs(V, A, x, Q, S, cnt, ba);
  }
  cnt[A[v]]--;
  S[newcnt].erase(A[v]);
  newcnt--;
  if (newcnt > 0) {
    S[newcnt].insert(A[v]);
    ba.add(1, newcnt, newcnt + 1);
  } else
    ba.add(-1, 1, A.size() + 1);
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
  BitAdd ba(n + 1);
  dfs(V, A, 0, Q, S, cnt, ba);
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
