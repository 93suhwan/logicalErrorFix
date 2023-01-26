#include <bits/stdc++.h>
using namespace std;
string int_to_string(long long n) {
  string s = "";
  while (n) {
    long long now = n % 10;
    s += now + '0';
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long string_to_int(string s) {
  long long n = 0;
  for (int i = 0; i < (int)(s.size()); i++) {
    n *= 10;
    n += s[i] - '0';
  }
  return n;
}
void chmin(int &a, int b) {
  if (b < a) {
    a = b;
  }
}
void chmax(int &a, int b) {
  if (b > a) {
    a = b;
  }
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int month[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
const int MAXN = 1e6 + 10;
int a[MAXN];
int dist[MAXN];
int n, d;
int nxt(int now) { return (now - d + n) % n; }
void dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  for (int i = 0; i < (int)(n); i++) {
    if (a[i] == 0) {
      dist[i] = 0;
      pq.push(pair<int, int>(0, i));
    }
  }
  while (!pq.empty()) {
    int now = pq.top().second;
    pq.pop();
    if (dist[nxt(now)] > dist[now] + 1) {
      dist[nxt(now)] = dist[now] + 1;
      pq.push(pair<int, int>(dist[nxt(now)], nxt(now)));
    }
  }
}
void solve() {
  cin >> n >> d;
  for (int i = 0; i < (int)(n); i++) {
    cin >> a[i];
    dist[i] = 1e9;
  }
  dijkstra();
  int ans = 0;
  for (int i = 0; i < (int)(n); i++) {
    chmax(ans, dist[i]);
  }
  if (ans == 1e9) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
