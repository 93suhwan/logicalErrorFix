#include <bits/stdc++.h>
using namespace std;
template <class T>
void smin(T& a, T b) {
  a = min(a, b);
}
template <class T>
void smax(T& a, T b) {
  a = max(a, b);
}
void yes() { cout << "ACCEPTED" << endl; }
void no() { cout << "REJECTED" << endl; }
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
const int M = 40;
int n, k;
long long powers[M];
bool ok(bitset<M> f, bitset<M> diffs[], bitset<M> unions[], int idx) {
  int ones_cnt = diffs[idx].count();
  int total_cnt = ones_cnt + unions[idx].count();
  if (idx == k) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (f.test(i))
        flag = true;
      else if (flag)
        return false;
    }
    return true;
  }
  bitset<M> fullone = ~bitset<M>{0};
  bitset<M> f_mask = f & unions[idx];
  int mask_cnt = f_mask.count();
  for (int i = 0; i <= ones_cnt; i++) {
    int ones_total_cnt = i + mask_cnt;
    int zeros_total_cnt = total_cnt - ones_total_cnt;
    bitset<M> next_f = diffs[idx] | unions[idx];
    bitset<M> without_next_f = fullone & ~next_f;
    f = f & without_next_f;
    int j = 0, cnt = 0;
    while (j < M && cnt < zeros_total_cnt) {
      if (next_f.test(j)) {
        next_f.set(j, false);
        cnt++;
      }
      j++;
    }
    bool res = ok(f | next_f, diffs, unions, idx + 1);
    if (!res) return false;
  }
  return true;
}
void solve() {
  cin >> n >> k;
  powers[0] = 1;
  for (int i = 1; i < M; i++) powers[i] = powers[i - 1] << 1;
  if (n > 1 && k == 0) return no();
  bitset<M> diffs[k];
  bitset<M> unions[k];
  bitset<M> onion{0};
  for (int i = 0; i < k; i++) {
    bitset<M> bs{0};
    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++) {
      int xi;
      cin >> xi;
      xi--;
      bs.set(xi, true);
    }
    diffs[i] = bs & ~onion;
    unions[i] = bs & onion;
    onion = onion | bs;
  }
  if (n == 1) return yes();
  bitset<M> f{0};
  if (ok(f, diffs, unions, 0)) return yes();
  return no();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
