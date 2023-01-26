#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
vector<int> f1, f2;
int find(vector<int>& f, int u) { return u == f[u] ? u : f[u] = find(f, f[u]); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  f1.resize(n + 1);
  f2.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    f1[i] = f2[i] = i;
  }
  int u, v;
  for (int i = 1; i <= m1; i++) {
    cin >> u >> v;
    int fu = find(f1, u);
    int fv = find(f1, v);
    f1[fu] = fv;
  }
  for (int i = 1; i <= m2; i++) {
    cin >> u >> v;
    int fu = find(f2, u);
    int fv = find(f2, v);
    f2[fu] = fv;
  }
  int res = 0;
  vector<pair<int, int> > ans;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int fu1 = find(f1, i);
      int fv1 = find(f1, j);
      if (fu1 == fv1) continue;
      int fu2 = find(f2, i);
      int fv2 = find(f2, j);
      if (fu2 == fv2) continue;
      res++;
      f1[fu1] = fv1;
      f2[fu2] = fv2;
      ans.push_back({i, j});
    }
  }
  cout << res << endl;
  for (auto it : ans) {
    cout << it.first << ' ' << it.second << endl;
  }
  return 0;
}
