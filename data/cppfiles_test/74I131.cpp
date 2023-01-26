#include <bits/stdc++.h>
using namespace std;
template <typename num_t>
inline void add_mod(num_t& a, const long long& b, const int& m) {
  a = (a + b) % m;
  if (a < 0) a += m;
}
template <typename num_t>
inline bool update_max(num_t& a, const num_t& b) {
  return a < b ? a = b, true : false;
}
template <typename num_t>
inline bool update_min(num_t& a, const num_t& b) {
  return a > b ? a = b, true : false;
}
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) {
  return !lhs ? rhs : gcd(rhs % lhs, lhs);
}
template <typename num_t>
num_t pw(num_t n, num_t k, num_t mod) {
  num_t res = 1;
  for (; k > 0; k >>= 1) {
    if (k & 1) res = 1ll * res * n % mod;
    n = 1ll * n * n % mod;
  }
  return res;
}
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const long long ll_inf = 3ll * inf * inf;
const int max_n = 1e5 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  set<int> uniq_a(a.begin(), a.end());
  if ((int)(uniq_a).size() < n) {
    cout << "YES\n";
    for (int i = (0), _b = (n - (int)(uniq_a).size()); i < _b; ++i)
      cout << 0 << ' ';
    for (auto x : uniq_a) cout << x << ' ';
    return;
  }
  vector<int> even, odd;
  for (int x : a)
    if (x & 1)
      odd.push_back(x);
    else
      even.push_back(x);
  vector<int> ans;
  if (even.size() >= 3) {
    int sum = (even[0] + even[1] + even[2]) / 2;
    for (int j = (0), _b = ((int)(even).size()); j < _b; ++j)
      if (j < 3)
        ans.push_back(sum - even[j]);
      else
        ans.push_back(even[j] - ans[0]);
    for (int j = (0), _b = ((int)(odd).size()); j < _b; ++j)
      ans.push_back(odd[j] - ans[0]);
  } else if ((int)(even).size() >= 1 && odd.size() >= 2) {
    int sum = (even[0] + odd[0] + odd[1]) / 2;
    ans = {sum - even[0], sum - odd[0], sum - odd[1]};
    for (int j = (1), _b = ((int)(even).size()); j < _b; ++j)
      ans.push_back(even[j] - ans[0]);
    for (int j = (2), _b = ((int)(odd).size()); j < _b; ++j)
      ans.push_back(odd[j] - ans[0]);
  } else if (n <= 3) {
    cout << "NO";
    return;
  } else if (n <= 26) {
    map<pair<int, int>, vector<int>> mapping;
    for (int mask = (1), _b = (1 << n); mask < _b; ++mask) {
      int sum = 0;
      for (int j = (0), _b = (n); j < _b; ++j)
        if (mask & (1 << j)) sum += a[j];
      int cnt = __builtin_popcount(mask);
      auto it = mapping.find({cnt, sum});
      if (it == mapping.end()) {
        mapping[{cnt, sum}].push_back(mask);
        continue;
      }
      cerr << "cnt"
           << ": " << (cnt) << ", "
           << "sum"
           << ": " << (sum) << '\n';
      ;
      auto lhs = (it->second)[0], rhs = mask;
      vector<int> left_index, right_index;
      vector<bool> chosen(n, false);
      for (int j = (0), _b = (n); j < _b; ++j)
        if ((lhs & (1 << j)) ^ (rhs & (1 << j))) {
          if (lhs & (1 << j))
            left_index.push_back(j);
          else
            right_index.push_back(j);
          chosen[j] = true;
        }
      ans.push_back(0);
      for (int i = (0), _b = ((int)(left_index).size()); i < _b; ++i) {
        ans.push_back(a[left_index[i]] - ans.back());
        ans.push_back(a[right_index[i]] - ans.back());
      }
      ans.pop_back();
      for (int i = (0), _b = (n); i < _b; ++i)
        if (!chosen[i]) {
          ans.push_back(a[i]);
        }
      break;
    }
  } else {
    const int checking_size = 27;
    const int set_cnt = checking_size / 2;
    map<int, vector<int>> mapping;
    for (int mask = (0), _b = (1 << checking_size); mask < _b; ++mask)
      if (__builtin_popcount(mask) == set_cnt) {
        int sum = 0;
        for (int j = (0), _b = (checking_size); j < _b; ++j)
          if (mask & (1 << j)) sum += a[j];
        mapping[sum].push_back(mask);
        if ((int)(mapping[sum]).size() == 1) {
          continue;
        }
        auto lhs = mapping[sum][0], rhs = mapping[sum][1];
        vector<int> left_index, right_index;
        vector<bool> chosen(checking_size, false);
        for (int j = (0), _b = (checking_size); j < _b; ++j)
          if ((lhs & (1 << j)) ^ (rhs & (1 << j))) {
            if (lhs & (1 << j))
              left_index.push_back(j);
            else
              right_index.push_back(j);
            chosen[j] = true;
          }
        ans.push_back(0);
        for (int i = (0), _b = ((int)(left_index).size()); i < _b; ++i) {
          ans.push_back(a[left_index[i]] - ans.back());
          ans.push_back(a[right_index[i]] - ans.back());
        }
        ans.pop_back();
        for (int i = (0), _b = (n); i < _b; ++i)
          if (i >= checking_size || !chosen[i]) {
            ans.push_back(a[i]);
          }
        break;
      }
  }
  cout << "YES\n";
  for (auto x : ans) cout << x << ' ';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
