#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> arr1;
    vector<long long> arr2;
    for (int i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      if (x < 0)
        arr2.push_back(abs(x));
      else
        arr1.push_back(x);
    }
    sort(arr1.begin(), arr1.end(), greater<int>());
    sort(arr2.begin(), arr2.end(), greater<int>());
    debug() << " ["
            << "arr1"
               ": "
            << (arr1)
            << "] "
               " ["
            << "arr2"
               ": "
            << (arr2) << "] ";
    vector<long long> ans;
    int i = 0;
    while (i < arr2.size()) {
      ans.push_back(arr2[i]);
      i += k;
    }
    i = 0;
    while (i < arr1.size()) {
      ans.push_back(arr1[i]);
      i += k;
    }
    cout << accumulate(ans.begin(), ans.end(), 0LL) * 2 -
                *max_element(ans.begin(), ans.end())
         << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
