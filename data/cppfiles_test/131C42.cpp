#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T maxe(vector<T> &vec) {
  return *max_element(begin(vec), end(vec));
}
template <typename T>
inline T mine(vector<T> &vec) {
  return *min_element(begin(vec), end(vec));
}
template <typename T>
inline void printV(vector<T> &vec) {
  cerr << "########\n";
  for (int i = 0; i < vec.size(); ++i) {
    cerr << vec[i] << ' ';
  }
  cerr << '\n';
  cerr << "########\n";
}
template <typename T>
inline void printVV(vector<vector<T>> &vec) {
  cerr << "########\n";
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = 0; j < vec[i].size(); ++j) {
      cerr << vec[i][j] << ' ';
    }
    cerr << '\n';
  }
  cerr << "########\n";
}
template <typename T>
inline void print(T obj) {
  cout << obj << '\n';
}
template <typename T, typename... Args>
inline void print(T t, Args... args) {
  cout << t << " ";
  print(args...);
}
template <typename T>
inline void dbg(T obj) {
  cerr << obj << '\n';
}
template <typename T, typename... Args>
inline void dbg(T t, Args... args) {
  cerr << t << " ";
  dbg(args...);
}
unordered_map<int, unordered_set<int>> adj;
unordered_map<int, int> parent;
tuple<int, int, int, int, int> dfs(int i) {
  if (!adj.count(i)) {
    return {1, 1, i, i, i};
  }
  int bestDiam = 1;
  int bestR1 = i;
  int bestR2 = i;
  vector<pair<int, int>> nums;
  for (int j : adj[i]) {
    tuple<int, int, int, int, int> soln = dfs(j);
    if (get<1>(soln) > bestDiam) {
      bestDiam = get<1>(soln);
      bestR1 = get<3>(soln);
      bestR2 = get<4>(soln);
    }
    if (get<0>(soln) + 1 > bestDiam) {
      bestDiam = get<0>(soln) + 1;
      bestR1 = get<2>(soln);
      bestR2 = i;
    }
    nums.push_back({get<0>(soln), get<2>(soln)});
  }
  sort(begin(nums), end(nums));
  if (nums.size() >= 2) {
    int newDiam = nums[nums.size() - 1].first + nums[nums.size() - 2].first + 1;
    if (newDiam > bestDiam) {
      bestDiam = newDiam;
      bestR1 = nums[nums.size() - 1].second;
      bestR2 = nums[nums.size() - 2].second;
    }
  }
  return {1 + nums[nums.size() - 1].first, bestDiam,
          nums[nums.size() - 1].second, bestR1, bestR2};
}
void run() {
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  };
  unordered_map<int, int> toI;
  for (int i = 0; i < n; ++i) toI[v[i]] = i + 1;
  stack<int> st;
  for (int i = 0; i < n; ++i) st.push(v[i]);
  parent[0] = -1;
  while (!st.empty()) {
    int t = st.top();
    st.pop();
    if (parent.count(t)) continue;
    int xp2 = 1;
    while (xp2 < t) xp2 <<= 1;
    int par = xp2 - t;
    parent[t] = par;
    adj[par].insert(t);
    if (!parent.count(par)) st.push(par);
  }
  int start = 0;
  while (adj[start].size() == 1 && !toI.count(start)) {
    start = *adj[start].begin();
  }
  tuple<int, int, int, int, int> soln = dfs(start);
  print(toI[get<3>(soln)], toI[get<4>(soln)], get<1>(soln) - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.exceptions(cin.failbit);
  long long t = 1;
  for (int tests = 0; tests < t; ++tests) run();
}
