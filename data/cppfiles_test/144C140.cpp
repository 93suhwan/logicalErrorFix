#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n, m, k;
    cin >> n >> m >> k;
    ll big_tables_cnt = n % m;
    ll small_tables_cnt = m - big_tables_cnt;
    ll small_persons_num = small_tables_cnt * (n / m);
    ll first_small_person = 0;
    for (ll i = 0; i < k; ++i) {
      ll cur_small_table = 0;
      ll cur_person = first_small_person;
      for (ll table = 0; table < m; ++table) {
        if (cur_small_table < small_tables_cnt) {
          cout << n / m << ' ';
          for (ll c = 0; c < n / m; ++c) {
            cout << cur_person + 1 << ' ';
            cur_person = (cur_person + 1) % n;
          }
          ++cur_small_table;
        } else {
          cout << (n + m - 1) / m << ' ';
          for (ll c = 0; c < (n + m - 1) / m; ++c) {
            cout << cur_person + 1 << ' ';
            cur_person = (cur_person + 1) % n;
          }
        }
        cout << endl;
      }
      first_small_person = (first_small_person + small_persons_num) % n;
    }
    cout << endl;
  }
  return 0;
}
