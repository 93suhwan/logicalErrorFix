#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const int M = 1e6 + 10;
long long MOD = 998244353;
const long long INF = 0x3f3f3f3f3f3f3f3f;
inline long long gcd(long long s, long long b) {
  return b == 0 ? s : gcd(b, s % b);
}
void read(long long& x) {
  long long f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  x *= f;
}
long long t, n, m;
struct node {
  long long val, pos;
  bool operator<(const node& x) const { return val < x.val; }
} e[N];
int main() {
  cin >> t;
  while (t--) {
    priority_queue<node> pq;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> e[i].val;
      e[i].pos = i;
      if (e[i].val) pq.push(e[i]);
    }
    vector<pair<long long, long long> > ans;
    while (pq.size() != 1 && !pq.empty()) {
      node cur = pq.top();
      pq.pop();
      node cur1 = pq.top();
      pq.pop();
      ans.push_back(make_pair(cur.pos, cur1.pos));
      if (cur.val - 1 > 0) pq.push(node{cur.val - 1, cur.pos});
      if (cur1.val - 1 > 0) pq.push(node{cur1.val - 1, cur1.pos});
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
