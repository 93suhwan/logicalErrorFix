#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
const int M = 1000000007;
int n, m, k;
long long a[N + 1], b[N + 1], answer[N + 1], all[N + 1 << 1], pref[N + 1 << 1],
    monocrap_items[N + 1 << 1], current_result;
pair<int, int> q[N + 1];
vector<pair<int, int> > components;
vector<pair<int, pair<int, int> > > components_diffs;
map<int, int> idx;
void read() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  for (int i = 0; i < m; i++) scanf("%lld", b + i);
  for (int i = 0; i < k; i++) scanf("%d", &q[i].first), q[i].second = i;
}
void sort_arrays() {
  sort(a, a + n);
  sort(b, b + m);
  sort(q, q + k);
  a[n] = 1e9 + 10;
  b[m] = 1e9 + 10;
}
void build_all_array() {
  int idx = 0, jdx = 0;
  for (int i = 1; i <= n + m; i++) {
    if (a[idx] < b[jdx]) {
      all[i] = a[idx];
      idx++;
      monocrap_items[i] = 1;
    } else {
      all[i] = b[jdx];
      jdx++;
    }
    monocrap_items[i] += monocrap_items[i - 1];
    pref[i] = pref[i - 1] + all[i];
  }
}
int get_idx(int i) {
  if (idx[i] == i) return i;
  return idx[i] = get_idx(idx[i]);
}
long long get_result(pair<int, int> p) {
  int count = monocrap_items[p.second] - monocrap_items[p.first - 1];
  long long sum = pref[p.second] - pref[p.second - count];
  return sum;
}
long long merge_comps(int i, int j) {
  i = get_idx(i);
  j = get_idx(j);
  if (i == j) return 0;
  if (i > j) swap(i, j);
  long long r1 = get_result(components[i]);
  long long r2 = get_result(components[j]);
  components[i].second = components[j].second;
  components[j].first = components[i].first;
  idx[j] = i;
  long long r3 = get_result(components[i]);
  return r3 - r1 - r2;
}
void create_components() {
  for (int i = 1; i <= n + m; i++)
    components.push_back(make_pair(i, i)), idx[i] = i;
  for (int i = 1; i < n + m; i++)
    components_diffs.push_back(
        make_pair((all[components[i].first] - all[components[i - 1].first]),
                  make_pair(i, i - 1)));
  sort(components_diffs.begin(), components_diffs.end());
}
void calc_initial_result() {
  for (int i = 0; i < n; i++) current_result += a[i];
}
void calc_queries() {
  int idx = 0;
  for (int i = 0; i < k; i++) {
    while (idx < components_diffs.size() &&
           components_diffs[idx].first <= q[i].first) {
      current_result += merge_comps(components_diffs[idx].second.first,
                                    components_diffs[idx].second.second);
      idx++;
    }
    answer[q[i].second] = current_result;
  }
}
void print_answers() {
  for (int i = 0; i < k; i++) {
    printf("%lld\n", answer[i]);
  }
}
void solve() {
  sort_arrays();
  build_all_array();
  create_components();
  calc_initial_result();
  calc_queries();
  print_answers();
}
signed main() {
  int t = 1;
  while (t--) {
    read();
    solve();
  }
  return 0;
}
