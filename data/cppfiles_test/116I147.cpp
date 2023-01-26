#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
const int MOD = 998244353;
const int MAXN = 3e5 + 100;
const int LOGN = 20;
void clear() {}
void precalc() {}
void gen_tests() {}
int sum(int a, int b) { return (a + b) % MOD; }
int mult(int a, int b) { return ((long long)a * b) % MOD; }
set<int> added_indexes[MAXN];
struct Number {
  map<int, int> numbers;
  map<int, int> back_numbers;
  int delta = 0;
  int index;
  int Get(int ind) { return numbers[ind - delta]; }
  void Set(int ind, int val) {
    numbers[ind - delta] = val;
    back_numbers[val] = ind - delta;
  }
  int Size() { return numbers.size(); }
  int GetIndex(int value) { return back_numbers[value] + delta; }
  bool TryMerge(Number &number) {
    if (back_numbers.count(number.Get(0))) {
      int s_index = GetIndex(number.Get(0));
      int common_elements = 0;
      for (int i = 0; i + s_index < Size() && i < number.Size(); i++) {
        if (Get(i + s_index) != number.Get(i)) return false;
        common_elements++;
      }
      for (int i = common_elements; i < number.Size(); i++) {
        int val = number.Get(i);
        added_indexes[val].insert(index);
        Set(s_index + i, val);
      }
      return numbers.size() == back_numbers.size();
    } else if (number.back_numbers.count(Get(0))) {
      int s_index = number.GetIndex(Get(0));
      for (int i = 0; i < Size() && i + s_index < number.Size(); i++) {
        if (Get(i) != number.Get(i + s_index)) return false;
      }
      delta += s_index;
      for (int i = 0; i < s_index; i++) {
        int val = number.Get(i);
        added_indexes[val].insert(index);
        Set(i, val);
      }
      return numbers.size() == back_numbers.size();
    }
    return false;
  }
};
Number numbers[MAXN];
bool is_free[MAXN];
bool added[MAXN];
void FullRemove(int index, bool add_more) {
  queue<int> q;
  q.push(index);
  added[index] = false;
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    for (auto u : numbers[top].back_numbers) {
      int val = u.first;
      added_indexes[val].erase(top);
      for (auto v : added_indexes[val]) {
        if (added[v] && add_more) {
          added[v] = false;
          q.push(v);
        }
      }
    }
  }
}
int results[MAXN];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    numbers[i].index = i;
    added[i] = 1;
    int c;
    cin >> c;
    bool must_remove = false;
    for (int j = 0; j < c; j++) {
      int val;
      cin >> val;
      numbers[i].Set(j, val);
      if (is_free[val] && added_indexes[val].size() == 0) must_remove = true;
      added_indexes[val].insert(i);
      is_free[val] = true;
    }
    if (must_remove) {
      FullRemove(i, true);
      continue;
    }
    int v = i;
    set<int> merge_queue;
    for (auto u : numbers[i].back_numbers) {
      for (auto m : added_indexes[u.first]) {
        if (m != i) merge_queue.insert(m);
      }
    }
    for (int to : merge_queue) {
      if (numbers[v].Size() < numbers[to].Size()) {
        swap(v, to);
      }
      must_remove = !numbers[v].TryMerge(numbers[to]);
      if (must_remove) break;
      FullRemove(to, false);
    }
    if (must_remove) FullRemove(v, true);
  }
  map<int, int> shifts;
  for (int i = 1; i <= k; i++) {
    if (!is_free[i]) shifts[1]++;
  }
  for (int i = 0; i < n; i++) {
    if (added[i]) {
      shifts[numbers[i].Size()]++;
    }
  }
  vector<pair<int, int> > moves;
  for (auto u : shifts) {
    moves.push_back({u.first, u.second});
  }
  results[0] = 1;
  for (int i = 0; i < m; i++) {
    for (auto u : moves) {
      if (i + u.first > m) break;
      results[i + u.first] =
          sum(results[i + u.first], mult(u.second, results[i]));
    }
  }
  cout << results[m];
}
void multisolve() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  precalc();
  solve();
  return 0;
}
