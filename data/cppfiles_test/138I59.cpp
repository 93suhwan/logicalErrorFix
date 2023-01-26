#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define L(n) (n << 1)
#define R(n) (n << 1 | 1)
#define print_vector(n) for(auto a0 : n) cout << a0 << '\n'; cout << endl;
#define vector_sort(n) sort(n.begin(), n.end())
#define print_array(n, l, r) for(int a0 = l; a0 <= r; a0++) cout << n[a0] << '\n'; cout << '\n';
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define ABS(a) ((a) > 0 ? (a) : -(a))
// #define int long long
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, greater<int>, rb_tree_tag,tree_order_statistics_node_update>

template<class T>
istream & operator >> (istream &in, pair<T, T> &p) {
  in >> p.first >> p.second;
  return in;
}

template<class T>
ostream & operator <<(ostream &out, pair<T, T> &p) {
  out << p.first << ' ' << p.second;
  return out;
}

template<class Tuple, std::size_t N>
struct TuplePrinter {
  static void print(ostream &out, const Tuple& t) {
    TuplePrinter<Tuple, N-1>::print(out, t);
    out << ' ' << get<N-1>(t);
  }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(ostream &out, const Tuple& t) {
    out << get<0>(t);
  }
};

template<class... Args>
ostream & operator <<(ostream &out, const tuple<Args...> &p) {
  TuplePrinter<decltype(p), sizeof...(Args)>::print(out, p);
  return out;
}

int N, M, Q;
int A[200005];
int B[200005];
pii query[200005];
tuple<int, int, int> edges[400005];

int par[400005];
int used[400005];
long long sum[400005];
ordered_set seto[400005];

long long ans_now = 0;
long long ans[400005];

void input() {
  cin >> N >> M >> Q;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= M; i++) cin >> B[i];
  for (int i = 1; i <= Q; i++) cin >> query[i].first, query[i].second = i;
  A[N+1] = 2e9;
  B[M+1] = 2e9;
  sort(A + 1, A + N + 1);
  sort(B + 1, B + M + 1);
  sort(query + 1, query + Q + 1);
}

void get_edges() {
  int p_ed = 1;
  int p_A = 1, p_B = 1;
  while (p_ed < N + M) {
    if (A[p_A] < B[p_B]) {
      if (B[p_B] <= A[p_A+1]) {
        edges[p_ed] = {B[p_B] - A[p_A], p_A, p_B+N};
      } else {
        edges[p_ed] = {A[p_A+1] - A[p_A], p_A, p_A+1};
      }
      p_A++;
    }else {
      if (A[p_A] <= B[p_B+1]) {
        edges[p_ed] = {A[p_A] - B[p_B], p_B+N, p_A};
      } else {
        edges[p_ed] = {B[p_B+1] - B[p_B], p_B+N, p_B+N+1};
      }
      p_B++;
    }
    ++p_ed;
  }
  sort(edges + 1, edges + N + M);

  for (int i = 1; i <= N; i++) {
    seto[i].insert(A[i]);
    sum[i] = A[i];
    ans_now += A[i];
    used[i] = 1;
    par[i] = i;
  }

  for (int i = 1; i <= M; i++) {
    par[i+N] = i+N;
    seto[i+N].insert(B[i]);
  }
}

int find_par(int u) {
  return par[u] == u ? u : par[u] = find_par(par[u]);
}

void merge(int u, int v) {
  // cout << "init used: " << used[u] << " " << used[v] << "\n";
  // cout << "init sum: " << sum[u] << " " << sum[v] << "\n";
  u = find_par(u), v = find_par(v);
  if (seto[u].size() < seto[v].size()) swap(u, v);

  ans_now -= sum[v];
  ans_now -= sum[u];

  while (!seto[v].empty()) {
    int cur = *(seto[v].begin());
    if (used[u] > 0) {
      int now_candi = *(seto[u].find_by_order(used[u]-1));
      if (cur > now_candi) {
        // cout << cur << " " << now_candi << "\n";
        sum[u] += cur - now_candi;
      }
    }
    seto[u].insert(cur);
    seto[v].erase(seto[v].begin());
  }

  while (used[v] > 0) {
    sum[u] += *(seto[u].find_by_order(used[u]));
    used[u]++;
    used[v]--;
  }
  ans_now += sum[u];
  par[v] = u;

  // print_vector(seto[u]);
  // cout << "Merge " << u << " - " << v << ": \n";
  // cout << sum[u] << " " << sum[v] << "\n";
  // cout << ans_now << "\n\n";
}

void solve() {
  int p_qry = 1;
  query[Q+1].first = 2e9;
  for (int i = 1; i < N + M; i++) {
    auto [w, u, v] = edges[i];
    while (w > query[p_qry].first) {
      ans[query[p_qry].second] = ans_now;
      p_qry++;
    }

    merge(u, v);
  }
  while (p_qry <= Q) 
    ans[query[p_qry++].second] = ans_now;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  input();
  get_edges();
  // print_array(edges, 1, N+M-1);
  solve();
  print_array(ans, 1, Q);
}