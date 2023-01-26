#include <bits/stdc++.h>
using namespace std;
template <typename C>
auto test(C* x) -> decltype(cerr << *x, 0LL);
template <typename C>
char test(...);
template <typename C>
struct itr {
  C begin, end;
};
template <typename C>
itr<C> get_range(C b, C e) {
  return itr<C>{b, e};
}
struct debug {
  template <typename T>
  debug& operator<<(const T&) {
    return *this;
  }
};
template <typename T>
string _ARR_(T* arr, int sz) {
  string ret = "{ " + to_string(arr[0]);
  for (int i = 1; i < sz; i++) ret += " , " + to_string(arr[i]);
  ret += " }";
  return ret;
}
const int INF = 1e9 + 7, N = 2e5;
int n, a[N], lp = 1, ls = 1;
void anwser(bool b) {
  cout << (b ? "Alice\n" : "Bob\n");
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i)
    if (a[i] > a[i - 1]) ++lp;
  for (int i = n - 2; i >= 0; --i)
    if (a[i] > a[i + 1]) ++ls;
  int state = 1;
  int p1 = 0, p2 = n - 1;
  while (1) {
    if (a[p1] > a[p2]) {
      if (lp % 2) {
        anwser(state);
        return 0;
      } else {
        if (ls == 1) {
          anwser(!state);
          return 0;
        }
        --p2;
        --ls;
      }
    } else {
      if (ls % 2) {
        anwser(state);
        return 0;
      } else {
        if (lp == 1) {
          anwser(!state);
          return 0;
        }
        ++p1;
        --lp;
      }
    }
    state = !state;
  }
  return 0;
}
