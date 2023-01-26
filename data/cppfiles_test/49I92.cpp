#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <class T>
struct St {
  vector<T> node;
  St() {}
  void resize(int N) { node.assign(4 * N, 0); }
  T query_sum(int l, int r, int v = 1, int vl = 0, int vr = -1) {
    if (vr == -1) vr = node.size() / 4 - 1;
    if (l == vl && r == vr) return node[v];
    int vm = (vl + vr) / 2;
    T val = 0;
    if (l > r) return val;
    if (l <= vm) val += query_sum(l, min(r, vm), 2 * v, vl, vm);
    if (r >= vm + 1) val += query_sum(max(l, vm + 1), r, 2 * v + 1, vm + 1, vr);
    return val;
  }
  T query_pos(T val, int v = 1, int vl = 0, int vr = -1) {
    if (vr == -1) vr = node.size() / 4 - 1;
    if (vl == vr) return node[v] >= val ? vl : vl + 1;
    int vm = (vl + vr) / 2;
    if (node[2 * v] >= val) return query_pos(val, 2 * v, vl, vm);
    return query_pos(val - node[2 * v], 2 * v + 1, vm + 1, vr);
  }
  void add(int i, T val, int v = 1, int vl = 0, int vr = -1) {
    if (vr == -1) vr = node.size() / 4 - 1;
    if (vl == vr) {
      node[v] += val;
      return;
    }
    int vm = (vl + vr) / 2;
    if (i <= vm) {
      add(i, val, 2 * v, vl, vm);
    } else {
      add(i, val, 2 * v + 1, vm + 1, vr);
    }
    node[v] = node[2 * v] + node[2 * v + 1];
  }
};
int N, Q;
vector<int> P;
vector<vector<int>> G;
vector<int> label;
vector<int> ans;
vector<vector<pair<int, pair<int, int>>>> queries;
vector<int> num2freq;
vector<set<int>> freq2num;
St<int> distr;
void visit(int v) {
  if (N >= 1000) {
    assert(0 <= v && v < N);
    for (int c : G[v]) visit(c);
    return;
  }
  int num = label[v];
  int& freq = num2freq[num];
  if (freq != 0) distr.add(freq, -1);
  if (freq != 0) freq2num[freq].erase(num);
  freq += 1;
  distr.add(freq, 1);
  freq2num[freq].insert(num);
  for (auto& q : queries[v]) {
    int i = q.first, l = q.second.first, k = q.second.second;
    k += distr.query_sum(0, l - 1);
    int f = distr.query_pos(k);
    ans[i] = f == N + 1 ? -1 : *freq2num[f].begin() + 1;
  }
  for (int c : G[v]) visit(c);
  distr.add(freq, -1);
  freq2num[freq].erase(num);
  freq -= 1;
  if (freq != 0) distr.add(freq, 1);
  if (freq != 0) freq2num[freq].insert(num);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = (int)(0); t < (int)((T)); t++) {
    cin >> N >> Q;
    P.resize(N), G.assign(N, {}), label.resize(N), queries.assign(N, {}),
        ans.resize(Q), num2freq.assign(N, 0), freq2num.assign(N + 1, {}),
        distr.resize(N + 1);
    for (int v = (int)(0); v < (int)((N)); v++) cin >> label[v];
    for (int v = (int)(0); v < (int)((N)); v++)
      assert(1 <= label[v] && label[v] <= N);
    for (int v = (int)(0); v < (int)((N)); v++) label[v] -= 1;
    for (int v = (int)(1); v < (int)(N); v++) {
      cin >> P[v];
      P[v] -= 1;
    }
    for (int q = (int)(0); q < (int)((Q)); q++) {
      int v, l, k;
      cin >> v >> l >> k;
      queries[v - 1].push_back({q, {l, k}});
    }
    for (int v = (int)(1); v < (int)(N); v++) G[P[v]].push_back(v);
    for (int v = (int)(0); v < (int)((N)); v++)
      assert(0 <= label[v] && label[v] < N);
    visit(0);
    for (int q = (int)(0); q < (int)((Q)); q++)
      cout << ans[q] << " \n"[q == Q - 1];
  }
}
