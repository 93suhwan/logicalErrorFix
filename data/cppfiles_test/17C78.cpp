#include <bits/stdc++.h>
using namespace std;
const int block = 400, N = 2e5;
const long long base = 31, base2 = 37;
const long long mod = 1e9 + 7, mod2 = 1e9 + 9;
int n, m, a[200011];
long long fen[200011];
vector<int> ord;
string s;
void update(int pos, long long val) {
  for (int i = pos; i <= N; i += i & -i) fen[i] += val;
}
long long get_sum(int pos) {
  long long sum = 0;
  for (int i = pos; i >= 1; i -= i & -i) sum += fen[i];
  return sum;
}
map<int, int> mp;
void compress() {
  vector<int> tmp;
  for (auto p : ord) tmp.push_back(p);
  sort(tmp.begin(), tmp.end());
  tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
  for (int i = 0; i < (int)ord.size(); i++) {
    int rem = ord[i];
    ord[i] = lower_bound(tmp.begin(), tmp.end(), ord[i]) - tmp.begin() + 1;
    mp[ord[i]] = rem;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    ord.clear();
    mp.clear();
    for (int i = 0; i <= N + 5; i++) fen[i] = 0;
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
      int u;
      cin >> u;
      ord.push_back(u);
    }
    compress();
    long long ans = 0;
    for (int i = 0; i < (int)ord.size(); i++) {
      int u = ord[i];
      long long L = get_sum(u - 1), R = get_sum(N) - get_sum(u);
      if (L <= R) {
        ans += L;
        dq.push_front(mp[u]);
      } else {
        ans += R;
        dq.push_back(mp[u]);
      }
      update(u, 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
