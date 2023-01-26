#include <bits/stdc++.h>
using namespace std;
template <typename T_vector>
void output_vector(std::vector<T_vector>& v) {
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << (i == v.size() - 1 ? '\n' : ' ');
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<int> P(N);
  for (auto& p : P) {
    cin >> p;
    p--;
  }
  vector<int> rev_P(N);
  for (int i = 0; i < N; i++) {
    rev_P[P[i]] = i;
  }
  int S = int(sqrt(N)) + 1;
  vector<int> s_jump(N);
  auto compute_s_jump = [&](int index) -> int {
    int x = index;
    for (int i = 0; i < S; i++) x = P[x];
    return s_jump[index] = x;
  };
  for (int i = 0; i < N; i++) compute_s_jump(i);
  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      swap(rev_P[P[x]], rev_P[P[y]]);
      swap(P[x], P[y]);
      int sx = compute_s_jump(x);
      int sy = compute_s_jump(y);
      for (int it = 0; it <= S; it++) {
        s_jump[x] = sx;
        s_jump[y] = sy;
        x = rev_P[x];
        y = rev_P[y];
        sx = rev_P[sx];
        sy = rev_P[sy];
      }
    } else {
      int x, k;
      cin >> x >> k;
      x--;
      while (k >= S) {
        x = s_jump[x];
        k -= S;
      }
      while (k >= 1) {
        x = P[x];
        k--;
      }
      cout << x + 1 << '\n';
    }
  }
}
