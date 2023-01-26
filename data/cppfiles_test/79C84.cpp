#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int solve() {
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n + 1, 0);
  vector<ll> b(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
  }
  queue<pair<ll, ll>> q;
  set<ll> not_visited;
  vector<ll> last_jump(n + 1, -1);
  for (int i = 0; i < n; i++) {
    not_visited.insert(i);
  }
  q.push({-1, n});
  while (!q.empty()) {
    ll current = q.front().second;
    ll last = q.front().first;
    q.pop();
    last_jump[current] = last;
    ll slipped = min(n, current + b[current]);
    auto iter = not_visited.upper_bound(slipped);
    if (iter != not_visited.begin()) {
      vector<ll> used;
      while (iter != not_visited.begin()) {
        iter--;
        if (slipped - *iter <= a[slipped]) {
          used.push_back(*iter);
          q.push({current, *iter});
        } else {
          break;
        }
      }
      for (auto u : used) {
        not_visited.erase(u);
      }
    }
  }
  if (last_jump[0] == -1) {
    cout << -1 << "\n";
  } else {
    vector<ll> answers;
    ll current = 0;
    while (current != n) {
      answers.push_back(current);
      current = last_jump[current];
    }
    reverse(answers.begin(), answers.end());
    cout << answers.size() << "\n";
    for (auto a : answers) {
      cout << a << " ";
    }
    cout << "\n";
  }
  return 0;
}
int main() {
  solve();
  cout << flush;
  return 0;
}
