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
string get_s(long long val) {
  string s = "";
  while (val) {
    int tmp = val % 2;
    if (tmp) {
      s += "1";
    } else {
      s += "0";
    }
    val /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x, y;
  cin >> x >> y;
  string s1 = get_s(x);
  string s2 = get_s(y);
  queue<string> Q;
  unordered_set<string> S;
  Q.push(s1);
  S.insert(s1);
  while (!Q.empty()) {
    string s = Q.front();
    Q.pop();
    if (s.size() > s2.size()) continue;
    if (s.size() == s2.size()) {
      if (s == s2) {
        cout << "YES" << endl;
        return 0;
      }
    }
    string tmp = s + "0";
    reverse(tmp.begin(), tmp.end());
    int beg = 0;
    while (beg < tmp.size() && tmp[beg] == '0') beg++;
    tmp = tmp.substr(beg);
    if (!S.count(tmp)) {
      Q.push(tmp);
      S.insert(tmp);
    }
    tmp = s + "1";
    reverse(tmp.begin(), tmp.end());
    if (!S.count(tmp)) {
      Q.push(tmp);
      S.insert(tmp);
    }
  }
  cout << "NO" << endl;
  return 0;
}
