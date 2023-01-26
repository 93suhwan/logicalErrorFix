#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  string sep;
  for (const T &x : v) os << sep << x, sep = " ";
  return os;
}
const int mxN = 1e5 + 1, oo = 1e9;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template <class I>
I rnd(I l, I r) {
  return std::uniform_int_distribution<I>(l, r)(rng);
}
int n, k;
vector<int> sor[10];
bool test(bitset<40> s) {
  for (int i = 0; i < k; ++i) {
    int cnt = 0;
    for (auto j : sor[i]) {
      cnt += !s[j];
    }
    for (auto j : sor[i]) {
      if (cnt) {
        s[j] = false;
        cnt--;
      } else
        s[j] = true;
    }
  }
  bool one = false;
  for (int i = 0; i < n; ++i) {
    one |= s[i];
    if (one and !s[i]) return false;
  }
  return true;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int q;
    cin >> q;
    sor[i].resize(q);
    for (auto &j : sor[i]) {
      cin >> j, --j;
    }
  }
  for (int i = 0; i < 1e7 / n; ++i) {
    long long s = rnd(1LL, (1LL << n) - 1);
    if (!test(s)) {
      cout << "REJECTED\n";
      exit(0);
    }
  }
  cout << "ACCEPTED\n";
}
