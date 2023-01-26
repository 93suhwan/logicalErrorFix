#include <bits/stdc++.h>
using namespace std;
class Graph {
 public:
  vector<vector<int> > adj_list;
  Graph(int n) : adj_list(vector<vector<int> >(n)) {}
  void add_edge(int u, int v, bool bidirectional = true) {
    adj_list[u].push_back(v);
    if (bidirectional) {
      adj_list[v].push_back(u);
    }
  }
};
void print_err() { cerr << "\n"; }
template <class T, class... Arg>
void print_err(T x, Arg &&...args) {
  cerr << x << " ";
  print_err(args...);
}
template <class T>
void print_container(T &cont) {
  for (auto iter : cont) {
    cerr << iter << " ";
  }
  cerr << "\n";
}
void in() {}
template <class T, class... Arg>
void in(T &x, Arg &&...args) {
  cin >> x;
  in(args...);
}
template <class T>
void in_c(T &container, int start, int end) {
  for (int i = start; i < end; ++i) {
    cin >> container[i];
  }
}
inline void kick_temp(int test) { cout << "Case #" << test << ": "; }
vector<int> d4x{0, 0, 1, -1};
vector<int> d4y{-1, 1, 0, 0};
vector<int> d8x{0, 0, 1, -1, 1, 1, -1, -1};
vector<int> d8y{1, -1, 0, 0, -1, 1, 1, -1};
int get_swaps(vector<int> P, int k) {
  ;
  ;
  int count = 0;
  int i, j;
  int n = P.size();
  int index[n];
  for (i = 0; i < n; ++i) {
    index[P[i]] = i;
  }
  for (i = 0; i < n; ++i) {
    if (P[i] != (i - k + n) % n) {
      int temp = index[(i - k + n) % n];
      P[temp] = P[i];
      index[P[i]] = temp;
      ++count;
    }
  }
  return count;
}
void solve(int test) {
  ;
  int i, j, n, m;
  in(n, m);
  vector<int> A(n, 0);
  vector<int> P;
  for (i = 0; i < n; ++i) {
    cin >> j;
    j--;
    P.push_back(j);
    A[(i - j + n) % n]++;
  }
  int thres = n - 2 * m;
  vector<int> ans;
  ;
  for (i = 0; i < n; ++i) {
    if (A[i] >= thres) {
      if (get_swaps(P, i) <= m) {
        ans.push_back(i);
      }
    }
  }
  cout << ans.size();
  cout << " ";
  for (i = 0; i < ans.size(); ++i) {
    cout << ans[i];
    cout << " ";
  }
  cout << "\n";
}
int main() {
  int i = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_cases;
  cin >> test_cases;
  for (i = 1; i <= test_cases; ++i) solve(i);
  return 0;
}
