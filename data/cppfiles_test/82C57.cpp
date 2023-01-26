#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 300000;
const int Q_MAX = 300000;
const int BITS = 19;
int n, q, k;
int a[N_MAX + 2];
int lg2[N_MAX + 2];
int rm[N_MAX + 2][BITS];
int rmq(int l, int r) {
  if (l > r) return 0;
  int bit = lg2[r - l + 1];
  return min(rm[l][bit], rm[r - (1 << bit) + 1][bit]);
}
struct SGTNode {
  long long sum;
  int lazy;
};
SGTNode operator+(const SGTNode &u, const SGTNode &v) {
  return SGTNode{u.sum + v.sum, 0};
}
SGTNode SGT[N_MAX * 4 + 2];
void build(int node, int l, int r) {
  if (l == r) {
    SGT[node].sum = 0;
    SGT[node].lazy = 0;
    return;
  }
  int mid = (l + r) / 2;
  int lSon = node * 2, rSon = node * 2 + 1;
  build(lSon, l, mid);
  build(rSon, mid + 1, r);
  SGT[node] = SGT[lSon] + SGT[rSon];
}
void split(int node, int l, int r) {
  if (SGT[node].lazy == 0) return;
  int mid = (l + r) / 2;
  int lSon = node * 2, rSon = node * 2 + 1;
  SGT[lSon].sum = (long long)(mid - l + 1) * SGT[node].lazy;
  SGT[lSon].lazy = SGT[node].lazy;
  SGT[rSon].sum = (long long)(r - mid) * SGT[node].lazy;
  SGT[rSon].lazy = SGT[node].lazy;
  SGT[node].lazy = 0;
}
void update(int node, int l, int r, int ul, int ur, int uval) {
  if (ul <= l && r <= ur) {
    SGT[node].sum = (long long)(r - l + 1) * uval;
    SGT[node].lazy = uval;
    return;
  }
  split(node, l, r);
  int mid = (l + r) / 2;
  int lSon = node * 2, rSon = node * 2 + 1;
  if (ul <= mid) update(lSon, l, mid, ul, ur, uval);
  if (mid + 1 <= ur) update(rSon, mid + 1, r, ul, ur, uval);
  SGT[node] = SGT[lSon] + SGT[rSon];
}
long long query(int node, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return SGT[node].sum;
  split(node, l, r);
  int mid = (l + r) / 2;
  int lSon = node * 2, rSon = node * 2 + 1;
  long long sum = 0;
  if (ql <= mid) sum += query(lSon, l, mid, ql, qr);
  if (mid + 1 <= qr) sum += query(rSon, mid + 1, r, ql, qr);
  return sum;
}
int qr[N_MAX + 2];
vector<int> queries[N_MAX + 2];
long long answer[N_MAX + 2];
int cost[N_MAX + 2];
int encode(int x, int pos) { return (pos - x) / k + (x != 0); }
int decode(int x, int i) { return (i - (x != 0)) * k + x; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) rm[i][0] = a[i];
  for (int bit = 1; bit < BITS; bit++)
    for (int i = 1; i + (1 << bit) - 1 <= n; i++)
      rm[i][bit] = min(rm[i][bit - 1], rm[i + (1 << (bit - 1))][bit - 1]);
  for (int i = 1; i <= n; i++) {
    lg2[i] = lg2[i - 1];
    if ((1 << (lg2[i] + 1)) <= i) lg2[i]++;
  }
  for (int i = 1; i <= q; i++) {
    int l;
    cin >> l >> qr[i];
    queries[l].push_back(i);
  }
  for (int x = 0; x < k; x++) {
    int m = encode(x, n);
    build(1, 1, m);
    vector<int> st;
    for (int i = m; i >= 1; i--) {
      int pos = decode(x, i);
      while (st.empty() == false && a[pos] <= cost[st.back()]) st.pop_back();
      update(1, 1, m, i, (st.empty() == true ? m : st.back() - 1), a[pos]);
      for (int id : queries[pos]) {
        answer[id] += a[pos];
        int j = encode(x, qr[id]);
        answer[id] += query(1, 1, m, i + 1, j);
      }
      cost[i] = rmq(max(1, pos - k + 1), pos);
      while (st.empty() == false && cost[i] <= cost[st.back()]) st.pop_back();
      update(1, 1, m, i, (st.empty() == true ? m : st.back() - 1), cost[i]);
      st.push_back(i);
    }
  }
  for (int i = 1; i <= q; i++) cout << answer[i] << "\n";
  return 0;
}
