#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T, class U>
bool chmax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  } else {
    return false;
  }
}
template <class T, class U>
bool chmin(T& a, U b) {
  if (b < a) {
    a = b;
    return true;
  } else {
    return false;
  }
}
template <typename T>
std::istream& operator>>(std::istream& is, vector<T>& A) {
  for (int i = 0; i < (int)A.size(); ++i) {
    is >> A[i];
  }
  return is;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& A) {
  for (int i = 0; i < (int)A.size(); ++i) {
    os << A[i] << ' ';
  }
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<vector<T>>& matrix) {
  for (int i = 0; i < (int)matrix.size(); ++i) {
    if (i != 0) {
      os << '\n';
    }
    for (int j = 0; j < (int)matrix[i].size(); ++j) {
      os << matrix[i][j] << ' ';
    }
  }
  return os;
}
template <typename T>
std::istream& operator>>(std::istream& is, vector<vector<T>>& matrix) {
  for (int i = 0; i < (int)matrix.size(); ++i) {
    for (int j = 0; j < (int)matrix[i].size(); ++j) {
      is >> matrix[i][j];
    }
  }
  return is;
}
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(const char& c) { return (string) "" + c; }
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
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ld> a(n);
    cin >> a;
    ld mean = 0.0;
    for (int i = 0; i < n; ++i) {
      mean += a[i];
    }
    mean /= n;
    map<ld, int> m1, m2;
    int cnt{};
    for (int i = 0; i < n; ++i) {
      if (a[i] == mean) {
        cnt++;
        continue;
      }
      m1[a[i] - mean]++;
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] == mean) {
        continue;
      }
      m2[mean - a[i]]++;
    }
    ll ans{};
    for (auto& x : m1) {
      if (m2.find(x.first) != m2.end()) {
        ans += x.second * 1LL * m2[x.first];
      }
    }
    ans /= 2;
    ans += (cnt * 1LL * (cnt - 1)) / 2;
    cout << ans << '\n';
  }
  return 0;
}
