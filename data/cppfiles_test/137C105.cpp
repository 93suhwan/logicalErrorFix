#include <bits/stdc++.h>
using namespace std;
const long long inf = 1ll << 18;
long long a, b, top, now;
queue<long long> q;
map<long long, int> mp;
long long rev(long long x) {
  long long y = 0;
  while (x != 0) {
    y = (y << 1) | (x & 1);
    x >>= 1;
  }
  return y;
}
void push(long long &x) {
  if (x > b && rev(x) > b) return;
  if (mp.find(x) == mp.end()) {
    q.push(x);
    mp[x] = 1;
  }
}
string solve() {
  if (a == b) return "YES";
  q.push(a);
  mp[a] = 1;
  while (!q.empty()) {
    top = q.front();
    q.pop();
    now = rev(top << 1);
    if (now == b) return "YES";
    push(now);
    now = rev((top << 1) | 1);
    if (now == b) return "YES";
    push(now);
  }
  return "NO";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b;
  cout << solve() << endl;
  return 0;
}
