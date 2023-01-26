#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
struct Node {
  long long tot;
  long long pref, suff;
  Node() { tot = pref = suff = 0; }
} st[800100];
int arr[200100];
void U(int node, int l, int r, int ind, int val) {
  if (l > ind || r < ind) return;
  if (l == r) {
    st[node].tot = 1;
    st[node].pref = 1;
    st[node].suff = 1;
    return;
  }
  int mid = (l + r) / 2;
  U(node * 2, l, mid, ind, val);
  U(node * 2 + 1, mid + 1, r, ind, val);
  st[node].tot = st[node * 2].tot + st[node * 2 + 1].tot;
  if (arr[mid + 1] >= arr[mid]) {
    st[node].tot += st[node * 2].suff * st[node * 2 + 1].pref;
    if (st[node * 2 + 1].pref == (r - mid))
      st[node].suff = st[node * 2 + 1].pref + st[node * 2].suff;
    if (st[node * 2].suff == (mid - l + 1)) {
      st[node].pref = st[node * 2].suff + st[node * 2 + 1].pref;
    }
  } else {
    st[node].pref = st[node * 2].pref;
    st[node].suff = st[node * 2 + 1].suff;
  }
}
Node S(int node, int l, int r, int tl, int tr) {
  if (l > tr || r < tl) return Node();
  if (l >= tl && r <= tr) {
    return st[node];
  }
  int mid = (l + r) / 2;
  Node lson = S(node * 2, l, mid, tl, tr);
  Node rson = S(node * 2 + 1, mid + 1, r, tl, tr);
  Node ret;
  ret.tot = lson.tot + rson.tot;
  if (arr[mid + 1] >= arr[mid]) {
    ret.tot += lson.suff * rson.pref;
    if (st[node * 2 + 1].pref == (r - mid)) ret.suff = rson.pref + lson.suff;
    if (lson.suff == (mid - l + 1)) {
      ret.pref = lson.suff + rson.pref;
    }
  } else {
    ret.pref = lson.pref;
    ret.suff = rson.suff;
  }
  return ret;
}
int main() {
  fastIO();
  int N, Q;
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    U(1, 1, N, i, arr[i]);
  }
  for (int i = 1; i <= Q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      arr[b] = c;
      U(1, 1, N, b, c);
    } else {
      cout << S(1, 1, N, b, c).tot << "\n";
    }
  }
}
