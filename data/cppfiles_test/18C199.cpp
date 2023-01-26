#include <bits/stdc++.h>
using namespace std;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& second) { return '"' + second + '"'; }
string to_string(const char* second) { return to_string((string)second); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) {
  string second;
  second += c;
  return to_string(second);
}
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
const int N = 2e5 + 5;
void run_case() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> grp;
  vector<bool> used(n, false);
  for (int i = 0; i < n; i++) {
    int j = i;
    if (used[j]) continue;
    vector<int> x;
    while (!used[j]) {
      x.push_back(a[j]);
      used[j] = true;
      j = (j - d + n) % n;
    }
    grp.push_back(x);
  }
  int ans = -1;
  for (auto v : grp) {
    if (count(v.begin(), v.end(), 0) == 0) {
      ans = -1;
      break;
    }
    for (int i = 0, j = 0; i < v.size(); i++) {
      while (j < i || v[j % v.size()] != 0) {
        j++;
      }
      ans = max(ans, j - i);
    }
  }
  cout << ans << '\n';
}
auto clk = clock();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    run_case();
  }
  return 0;
}
