#include <bits/stdc++.h>
using namespace std;
void solve();
unordered_set<int> primes;
void sieve();
int main() {
  sieve();
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; ++test) {
    solve();
    cout << "\n";
  }
}
void solve() {
  using state = pair<int, int>;
  int n;
  cin >> n;
  vector<int> a(n);
  copy_n(istream_iterator<int>(cin), n, a.begin());
  unordered_map<int, state> sum_n;
  sum_n[0] = {-1, 0};
  for (int i = 0; i < n; ++i) {
    vector<pair<int, state>> to_add;
    for (auto [sum, j] : sum_n) {
      to_add.push_back({sum + a[i], {i, j.second + 1}});
    }
    for (auto [sum, j] : to_add) {
      auto it = sum_n.find(sum);
      if (it == sum_n.end()) {
        sum_n.insert({sum, j});
        continue;
      }
      if (it->second.second < j.second) {
        it->second = j;
      }
    }
  }
  int best = 0;
  int best_sum = 0;
  for (auto [sum, j] : sum_n) {
    if (primes.count(sum)) {
      continue;
    }
    if (best < j.second) {
      best = j.second;
      best_sum = sum;
    }
  }
  cout << best << "\n";
  while (best_sum != 0) {
    auto x = sum_n[best_sum];
    cout << (1 + x.first) << " ";
    best_sum -= a[x.first];
  }
}
void sieve() {
  constexpr int n = 20001;
  vector<bool> p(n, true);
  for (int i = 2; i != n; ++i) {
    if (!p[i]) {
      continue;
    }
    primes.insert(i);
    for (int j = i * i; j < n; j += i) {
      p[j] = false;
    }
  }
}
