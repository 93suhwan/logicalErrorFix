#include <bits/stdc++.h>
using namespace std;
namespace my {
template <typename T>
class vector : public std::vector<T> {
 public:
  vector() {}
  vector(int n) { this->reserve(n); }
  vector(std::initializer_list<T> ls) {
    for (auto i : ls) this->push_back(i);
  }
  void push_input(size_t n) {
    for (size_t i{0ULL}; i != n; ++i) {
      T store;
      cin >> store;
      this->push_back(store);
    }
  }
};
}  // namespace my
int recur_depth = 0;
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream&>::type operator<<(
    Ostream& os, const Cont& v) {
  os << "[";
  for (auto& x : v) {
    os << x << ", ";
  }
  return os << "]";
}
template <typename T1, typename T2>
std::istream& operator>>(std::istream& in, pair<T1, T2>& P) {
  in >> P.first >> P.second;
  return in;
}
template <typename Ostream, typename... Ts>
Ostream& operator<<(Ostream& os, const pair<Ts...>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename T>
inline bool compare_float(T a, T b) {
  return (abs(a - b) < 1e-9) ? true : false;
}
template <typename T>
istream& operator>>(istream& os, vector<T>& v) {
  T store;
  os >> store;
  v.push_back(store);
  return os;
}
template <typename T>
void print(T container, string sep = " ", string end = "\n") {
  for (const auto& i : container) std::cout << i << sep;
  cout << end;
}
const std::string sp{" "};
const std::string nl{"\n"};
class solution {
  int T = 1;
  int N;
  int M;
  int k;

 public:
  solution() {}
  void solve() {
    cin >> N >> M >> k;
    bool yes{true};
    if (not(M & 1) and not(N & 1)) {
      if (k & 1) {
        k = k * 2;
        int row{k / M};
        int left{(k % M) / 2};
        if (row & 1) {
          left += (M / 2);
          if (left & 1) {
            yes = false;
          }
        } else {
          if (left & 1) {
            yes = false;
          }
        }
      }
    } else if (N & 1) {
      k *= 2;
      int row{k / M};
      int left{(k % M) / 2};
      if (row & 1) {
        if (left & 1) {
          yes = false;
        }
      } else {
        left += (M / 2);
        if (left & 1 or N == 1) {
          yes = false;
        }
      }
    } else {
      if (M != 1) {
        M = M - 1;
        int max_dominos{(M * N) / 2};
        k = k * 2;
        int row{k / M};
        int left{(k % M) / 2};
        if (row & 1) {
          left += (M / 2);
          if (left & 1) {
            yes = false;
          }
        } else {
          if (left & 1) {
            yes = false;
          }
        }
      } else {
        yes = not(k != 0);
      }
    }
    if (yes) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
  }
  void operator()() {
    std::cin >> T;
    while (T--) {
      solve();
    }
  }
};
int main() {
  ios::sync_with_stdio(0);
  solution()();
  return 0;
}
