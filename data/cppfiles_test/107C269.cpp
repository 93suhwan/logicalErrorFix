#include <bits/stdc++.h>
#pragma optimize("SEX_ON_THE_BEACH")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unroll-all-loops")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("no-stack-protector")
using ll = long long int;
using ull = unsigned long long int;
using dd = double;
using ldd = long double;
namespace someUsefull {
template <typename T1, typename T2>
inline void checkMin(T1& a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void checkMax(T1& a, T2 b) {
  if (a < b) a = b;
}
const int _bitfunctions_size_ = 16;
const int _bitfunctions_mask_ = (1 << _bitfunctions_size_) - 1;
char* _bits_count_;
inline void _build_bits_count_() {
  _bits_count_ = new char[1 << _bitfunctions_size_];
  for (int i = 1; i < (1 << _bitfunctions_size_); ++i) {
    _bits_count_[i] = _bits_count_[i >> 1];
    if (i & 1) ++_bits_count_[i];
  }
}
template <typename T1 = char, typename T2 = int>
inline T1 popcnt(T2 x) {
  T1 ans = 0;
  while (x) {
    ans += _bits_count_[x & _bitfunctions_mask_];
    x >>= _bitfunctions_size_;
  }
  return ans;
}
}  // namespace someUsefull
namespace operators {
template <typename T1, typename T2>
std::istream& operator>>(std::istream& in, std::pair<T1, T2>& x) {
  in >> x.first >> x.second;
  return in;
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, std::pair<T1, T2> x) {
  out << x.first << " " << x.second;
  return out;
}
template <typename T1>
std::istream& operator>>(std::istream& in, std::vector<T1>& x) {
  for (auto& i : x) in >> i;
  return in;
}
template <typename T1>
std::ostream& operator<<(std::ostream& out, std::vector<T1>& x) {
  for (auto& i : x) out << i << " ";
  return out;
}
}  // namespace operators
using namespace std;
using namespace operators;
using namespace someUsefull;
void solve(int test = 0) {
  int n, a, b;
  cin >> n >> a >> b;
  bool sw = 0;
  if (a < b) {
    swap(a, b);
    sw = 1;
  }
  if (abs(a - b) > 1) {
    cout << -1 << '\n';
    return;
  }
  if (a > (n - 1) / 2) {
    cout << -1 << '\n';
    return;
  }
  if (b > (n - 2) / 2) {
    cout << -1 << '\n';
    return;
  }
  vector<int> arr(n);
  arr[0] = 1;
  set<int> have;
  for (int i = 1; i < n; ++i) {
    have.insert(i + 1);
  }
  if (a == 0) {
    for (int i = 0; i < n; ++i) {
      cout << i + 1 << " ";
    }
    cout << '\n';
    return;
  }
  for (int i = 1; i < n; ++i) {
    if (i % 2) {
      arr[i] = *have.rbegin();
      have.erase(arr[i]);
      a--;
    } else {
      arr[i] = *have.begin();
      have.erase(arr[i]);
      b--;
    }
    if (a == 0 && b == 0) {
      bool fl = i % 2;
      i++;
      for (; i < n; ++i) {
        if (fl)
          arr[i] = *have.rbegin();
        else
          arr[i] = *have.begin();
        have.erase(arr[i]);
      }
    }
  }
  if (sw) {
    for (int i = 0; i < n; ++i) arr[i] = n + 1 - arr[i];
  }
  cout << arr << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  _build_bits_count_();
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve(i + 1);
  }
  return 0;
}
