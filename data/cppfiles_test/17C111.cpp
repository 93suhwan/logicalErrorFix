#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll mod = 998244353;
template <typename T>
class bst {
 private:
  bst *l, *r, *p;
  bool is_root;
  int8_t _depth;
  int _size, freq;
  T data;
  int get_depth(bst* node) { return (node ? node->_depth : -1); }
  void set_aux() {
    _size = (r ? r->size() : 0) + (l ? l->size() : 0) + freq;
    _depth = (!is_root) + max(get_depth(l), get_depth(r));
  }
  void join(bst* anc, bst* des, bool dir = false) {
    if (anc) {
      if (des == NULL) {
        (dir ? anc->r : anc->l) = des;
        return;
      }
      if (des->data > anc->data)
        anc->r = des;
      else
        anc->l = des;
    }
    if (des) des->p = anc;
  }
  void rotate(bst* anc, bst* des) {
    join(anc->p, des);
    bst* tmp = (anc->data > des->data ? des->r : des->l);
    join(des, anc);
    join(anc, tmp, (anc->data < des->data));
    anc->set_aux();
    des->set_aux();
  }
  bst* rebuildSubtree() {
    if (get_depth(r) - get_depth(l) == 2) {
      if (get_depth(r->r) - get_depth(r->l) == -1) rotate(r, r->l);
      rotate(this, r);
      return p;
    } else if (get_depth(r) - get_depth(l) == -2) {
      if (get_depth(l->r) - get_depth(l->l) == 1) rotate(l, l->r);
      rotate(this, l);
      return p;
    }
    return this;
  }
  bst* insert_elem(T d) {
    if (d < data)
      l = (l ? l->insert_elem(d) : new bst(d, this));
    else if (d > data)
      r = (r ? r->insert_elem(d) : new bst(d, this));
    else
      freq++;
    set_aux();
    return rebuildSubtree();
  }
  bst(T d, bst* par) {
    data = d;
    l = r = NULL;
    p = par;
    is_root = _depth = 0;
    _size = freq = 1;
  }
  bst* erase_elem(T d, bst* node) {
    if (d != data and (r || l)) {
      if (d > data and r)
        r = r->erase_elem(d, node);
      else if (d < data and l)
        l = l->erase_elem(d, node);
      set_aux();
      return rebuildSubtree();
    }
    if (d == data) {
      freq--;
      if (freq > 0) return this;
      if (r) {
        r = r->erase_elem(d, this);
        set_aux();
        return rebuildSubtree();
      }
      if (l) {
        data = l->data;
        freq = l->freq;
        delete l;
        return this;
      }
      delete this;
      return NULL;
    }
    node->data = data;
    node->freq = freq;
    bst* ret = r;
    l = r = p = NULL;
    delete this;
    return ret;
  }

 public:
  bst() {
    l = r = p = NULL;
    is_root = 1;
    _size = _depth = freq = 0;
  }
  int size() { return _size; }
  int depth() { return _depth; }
  void insert(T d) {
    if (l == NULL)
      l = new bst(d, NULL);
    else
      l = l->insert_elem(d);
    set_aux();
  }
  void erase(T d) {
    l = l->erase_elem(d, NULL);
    set_aux();
  }
  int lower_bound(T e) {
    if (is_root and l) return l->lower_bound(e);
    int result = size();
    if (data >= e) result = min(result, (l ? l->size() : 0));
    if (e > data and r)
      result = min((l ? l->size() : 0) + freq + r->lower_bound(e), result);
    if (e < data and l) result = min(result, l->lower_bound(e));
    return result;
  }
};
void solver() {
  int n;
  cin >> n;
  vl dp(n, 0);
  bst<int> s;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    int idx = s.lower_bound(a + 1);
    dp[i] = s.size() - idx;
    idx = s.lower_bound(a);
    dp[i] = min(dp[i], (ll)idx);
    dp[i] += (i ? dp[i - 1] : 0);
    s.insert(a);
  }
  cout << dp[n - 1] << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool mt = 1;
  int tests = 1;
  if (mt) cin >> tests;
  for (int tt = 1; tt <= tests; ++tt) {
    solver();
  }
  return 0;
}
