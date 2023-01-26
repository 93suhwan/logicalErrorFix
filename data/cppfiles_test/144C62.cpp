#include <bits/stdc++.h>
using namespace std;
const long long N = 100100;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long table_with_more = (n % m);
  long long table_capacity = ((n + m - 1) / m);
  long long total_person_cnt = table_with_more * table_capacity;
  long long mxB = 0;
  vector<long long> b(n, 0);
  for (long long game = 0; game < k; game++) {
    vector<long long> table[m], selected(n, 0);
    long long cur_person_cnt = 0, table_index = 0;
    for (long long i = 0; i < n && cur_person_cnt < total_person_cnt; i++) {
      if (b[i] < mxB) {
        b[i]++;
        selected[i] = 1;
        cur_person_cnt++;
        table[table_index].push_back(i);
        if (table[table_index].size() == table_capacity) {
          table_index++;
        }
      }
    }
    for (long long i = 0; i < n && cur_person_cnt < total_person_cnt; i++) {
      if (!selected[i]) {
        b[i]++;
        selected[i] = 1;
        cur_person_cnt++;
        table[table_index].push_back(i);
        if (table[table_index].size() == table_capacity) {
          table_index++;
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      if (!selected[i]) {
        selected[i] = 1;
        table[table_index].push_back(i);
        if (table[table_index].size() == (n / m)) {
          table_index++;
        }
      }
      mxB = max(mxB, b[i]);
    }
    for (long long i = 0; i < m; i++) {
      cout << (long long)table[i].size() << ' ';
      for (long long person_index : table[i]) {
        cout << person_index + 1 << ' ';
      }
      cout << '\n';
    }
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
