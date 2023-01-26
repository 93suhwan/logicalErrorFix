#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const long long MOD = 998244353;
const int INF = 1e7;
const double pi = 2 * asin(1);
const double eps = 1e-10;
int per[500000], r2i[500000], res[500000];
char lk[500000];
int main() {
  ios::sync_with_stdio(false);
  mt19937_64 rnd(time(0));
  srand(time(0));
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &per[i]);
    scanf("%s", lk + 1);
    vector<pair<int, int> > tv;
    for (int i = 1; i <= n; i++)
      if (lk[i] == '0') tv.push_back(make_pair(per[i], i));
    sort(tv.begin(), tv.end());
    for (int i = 0; i < tv.size(); i++) res[tv[i].second] = i + 1;
    int cnt = tv.size();
    tv.clear();
    for (int i = 1; i <= n; i++)
      if (lk[i] == '1') tv.push_back(make_pair(per[i], i));
    sort(tv.begin(), tv.end());
    for (int i = 0; i < tv.size(); i++) res[tv[i].second] = i + 1 + cnt;
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    cout << '\n';
  }
}
