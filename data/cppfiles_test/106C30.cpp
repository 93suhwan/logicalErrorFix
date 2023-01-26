#include <bits/stdc++.h>
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;
template <typename T>
T abs(T x) {
  return (x < 0) ? (-x) : x;
}
cat gcd(cat a, cat b) {
  if (a > b) swap(a, b);
  while (a) {
    cat c = b % a;
    b = a;
    a = c;
  }
  return b;
}
cat pw(cat a, cat e, cat mod) {
  if (e <= 0) return 1;
  cat x = pw(a, e / 2, mod);
  x = x * x % mod;
  return (e & 1) ? x * a % mod : x;
}
template <typename T>
class fin {
  vector<T> node_val;
  int lastone(int x) { return x & (x ^ (x - 1)); }

 public:
  fin(int N, T init_val) { node_val.resize(N + 10, init_val); }
  void put(int pos, T val) {
    for (int i = pos + 1; i < (int)node_val.size(); i += lastone(i))
      node_val[i] += val;
  }
  T get(int pos) {
    T ret = 0;
    for (int i = pos + 1; i > 0; i -= lastone(i)) ret += node_val[i];
    return ret;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  int N, K, MX = 1000000;
  cin >> N >> K;
  vector<int> A(1 << N);
  for (int i = 0; i < (1 << N); i++) cin >> A[i];
  vector<char> use_b(1 << N, 0);
  vector<int> id(1 << N, -1), V;
  int ans = 0;
  vector<pair<int, pair<int, int> > > E;
  E.reserve((1 << (N - 1)) * N);
  for (int i = 0; i < (1 << N); i++)
    for (int j = 0; j < N; j++)
      if ((i >> j) & 1)
        E.push_back({A[i] + A[i ^ (1 << j)], {i, i ^ (1 << j)}});
  vector<int> n_val(2 * MX + 1, 0);
  for (int i = 0; i < (int)E.size(); i++) n_val[E[i].first]++;
  vector<int> cur_pos(2 * MX + 1, 0);
  for (int i = 1; i <= 2 * MX; i++) cur_pos[i] = cur_pos[i - 1] + n_val[i - 1];
  vector<pair<int, pair<int, int> > > Es((1 << (N - 1)) * N);
  for (int i = 0; i < (1 << (N - 1)) * N; i++) Es[cur_pos[E[i].first]++] = E[i];
  E = Es;
  for (int k = 0; k < K; k++) {
    vector<pair<int, int> > max_add(2 * k, {-MX, -1});
    vector<int> prev(2 * k);
    for (int i = 0; i < 2 * k; i++) {
      int v = V[i], u = V[i] ^ (1 << (use_b[V[i]] - 1));
      for (int j = 0; j < N; j++)
        if (!use_b[v ^ (1 << j)]) {
          max_add[id[u]] = max(max_add[id[u]], {A[v ^ (1 << j)], v ^ (1 << j)});
          if (max_add[id[u]].second == (v ^ (1 << j)))
            prev[id[u]] = v ^ (1 << j);
        }
    }
    for (int l = 0; l < k + 2; l++)
      for (int i = 0; i < 2 * k; i++) {
        int v = V[i];
        for (int j = 0; j < N; j++)
          if (use_b[v ^ (1 << j)]) {
            int u = v ^ (1 << j) ^ (1 << (use_b[v ^ (1 << j)] - 1));
            if (max_add[id[u]] < max_add[id[v]]) prev[id[u]] = v;
            max_add[id[u]] = max(max_add[id[u]], max_add[id[v]]);
          }
      }
    int max_add_tot = 0, path_st, path_end, path_prev;
    for (int i = 0; i < 2 * k; i++) {
      int v = V[i];
      for (int j = 0; j < N; j++)
        if (!use_b[v ^ (1 << j)] &&
            max_add_tot < max_add[id[v]].first + A[v ^ (1 << j)]) {
          max_add_tot = max_add[id[v]].first + A[v ^ (1 << j)];
          path_st = max_add[id[v]].second;
          path_prev = v;
          path_end = v ^ (1 << j);
        }
    }
    while (!E.empty() &&
           (use_b[E.back().second.first] || use_b[E.back().second.second]))
      E.pop_back();
    if (!E.empty() && max_add_tot < E.back().first) {
      max_add_tot = E.back().first;
      path_st = path_prev = E.back().second.first;
      path_end = E.back().second.second;
    }
    if (max_add_tot == 0) break;
    ans += A[path_st] + A[path_end];
    id[path_st] = V.size();
    V.push_back(path_st);
    id[path_end] = V.size();
    V.push_back(path_end);
    while (use_b[path_prev]) {
      int u = path_prev ^ (1 << (use_b[path_prev] - 1));
      use_b[path_end] = use_b[path_prev] =
          1 + __builtin_ctz(path_prev ^ path_end);
      path_end = u;
      path_prev = prev[id[path_prev]];
    }
    use_b[path_end] = use_b[path_prev] =
        1 + __builtin_ctz(path_prev ^ path_end);
  }
  cout << ans << "\n";
}
