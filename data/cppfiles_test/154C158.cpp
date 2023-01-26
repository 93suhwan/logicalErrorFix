#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
}
template <typename T>
int SIZE(T(&t)) {
  return t.size();
}
template <typename T, size_t N>
int SIZE(T (&t)[N]) {
  return N;
}
string to_string(char t) { return "'" + string({t}) + "'"; }
string to_string(bool t) { return t ? "true" : "false"; }
string to_string(const string& t, int x1 = 0, int x2 = 1e9) {
  string ret = "";
  for (int i = min(x1, SIZE(t)), _i = min(x2, SIZE(t) - 1); i <= _i; ++i) {
    ret += t[i];
  }
  return '"' + ret + '"';
}
string to_string(const char* t) {
  string ret(t);
  return to_string(ret);
}
template <size_t N>
string to_string(const bitset<N>& t, int x1 = 0, int x2 = 1e9) {
  string ret = "";
  for (int i = min(x1, SIZE(t)); i <= min(x2, SIZE(t) - 1); ++i) {
    ret += t[i] + '0';
  }
  return to_string(ret);
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1 = 0, int x2 = 1e9, Coords... C);
template <typename T, typename S>
string to_string(const pair<T, S>& t) {
  return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1, int x2, Coords... C) {
  string ret = "[";
  x1 = min(x1, SIZE(t));
  auto e = begin(t);
  advance(e, x1);
  for (int i = x1, _i = min(x2, SIZE(t) - 1); i <= _i; ++i) {
    ret += to_string(*e, C...) + (i != _i ? ", " : "");
    e = next(e);
  }
  return ret + "]";
}
template <int Index, typename... Ts>
struct print_tuple {
  string operator()(const tuple<Ts...>& t) {
    string ret = print_tuple<Index - 1, Ts...>{}(t);
    ret += (Index ? ", " : "");
    return ret + to_string(get<Index>(t));
  }
};
template <typename... Ts>
struct print_tuple<0, Ts...> {
  string operator()(const tuple<Ts...>& t) { return to_string(get<0>(t)); }
};
template <typename... Ts>
string to_string(const tuple<Ts...>& t) {
  const auto Size = tuple_size<tuple<Ts...>>::value;
  return print_tuple<Size - 1, Ts...>{}(t);
}
void dbgr() { ; }
template <typename Heads, typename... Tails>
void dbgr(Heads H, Tails... T) {
  cout << to_string(H) << " | ";
  dbgr(T...);
}
int main() {
  fastio();
  int tt;
  cin >> tt;
  while (tt--) {
    int arr[3];
    for (int i = 0; i < 3; i++) cin >> arr[i];
    sort(arr, arr + 3);
    if (arr[2] - arr[0] == arr[1])
      cout << "YES"
           << "\n";
    else if ((arr[0] == arr[1] && arr[2] % 2 == 0) ||
             (arr[0] == arr[2] && arr[1] % 2 == 0) ||
             (arr[1] == arr[2] && arr[0] % 2 == 0))
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
