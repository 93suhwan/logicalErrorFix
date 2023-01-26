#include <bits/stdc++.h>
using namespace std;
vector<int> r(100005);
vector<int> p(100005);
int find_set(int x) {
  if (p[x] == x) return x;
  p[x] = find_set(p[x]);
  return p[x];
}
void make_pair1(int x, int y) {
  int p1 = find_set(x);
  int p2 = find_set(y);
  if (p1 == p2) return;
  if (r[p1] >= r[p2]) {
    r[p1] = r[p1] + r[p2];
    p[p2] = p1;
  } else {
    r[p2] = r[p2] + r[p1];
    p[p1] = p2;
  }
}
bool prime[100005];
void sieve() {
  vector<long long> ans;
  memset(prime, true, sizeof(prime));
  long long i;
  for (i = 2; i * i < 100005; i++) {
    if (prime[i] == true) {
      for (int j = i * i; j < 100005; j += i) {
        prime[j] = false;
      }
    }
  }
  for (i = 2; i < 100005; i++) {
    if (prime[i]) {
      ans.push_back(i);
    }
  }
}
void want() {
  long long n, m;
  cin >> n >> m;
  long long x, y;
  cin >> x >> y;
  long long z, w;
  cin >> z >> w;
  long long a, b, c, d;
  if (z >= x) {
    a = z - x;
  } else {
    a = INT_MAX;
    b = 2 * n - x - z;
  }
  if (w >= y) {
    c = w - y;
  } else {
    c = INT_MAX;
    d = 2 * m - w - y;
  }
  cout << min(min(a, b), min(c, d)) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    want();
  }
}
