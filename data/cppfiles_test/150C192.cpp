#include <bits/stdc++.h>
using namespace std;
void judge() {}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int p1 = 1e9 + 7;
long long int p2 = 998244353;
struct segtree {
  vector<int> v;
  int n, n2;
  void init(int x) {
    n = x;
    int a = 1;
    while (a <= x) a *= 2;
    a *= 2;
    n2 = a;
    v.assign(n2, 0);
  }
  int return_max(int curr, int r2, int l, int r) {
    if (l == r) {
      return v[curr];
    }
    int mid = (r + l) / 2;
    if (r2 <= mid) return return_max(2 * curr + 1, r2, l, mid);
    return max(v[2 * curr + 1], return_max(2 * curr + 2, r2, mid + 1, r));
  }
  int return_max(int r) {
    if (r < 0) return 0;
    return return_max(0, r, 0, n - 1);
  }
  void update(int curr, int pos, int val, int l, int r) {
    if (l == r) {
      v[curr] = max(v[curr], val);
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
      update(2 * curr + 1, pos, val, l, mid);
    else
      update(2 * curr + 2, pos, val, mid + 1, r);
    v[curr] = max(v[2 * curr + 1], v[2 * curr + 2]);
  }
  void update(int pos, int val) { update(0, pos, val, 0, n - 1); }
  int ans() {
    int a = 0;
    for (auto val : v) a = max(a, val);
    return a;
  }
};
bool compare(pair<long long int, long long int>& a,
             pair<long long int, long long int>& b) {
  if (a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}
int find_set(vector<int>& parent, int x) {
  if (parent[x] == x) return x;
  return parent[x] = find_set(parent, parent[x]);
}
void union_set(vector<int>& parent, int x, int y) {
  x = find_set(parent, x);
  y = find_set(parent, y);
  if (x != y) {
    parent[x] = y;
  }
}
vector<long long int> primes;
void pre() {
  vector<long long int> v(100000);
  for (long long int i = 2; i <= 100000; i++) {
    if (v[i] == 0) {
      primes.push_back(i);
      for (long long int j = i * i; j <= 10000; j += i) {
        v[j] = 1;
      }
    }
  }
}
long long int query(long long int a, long long int b, long long int c) {
  cout << "? " << a << " " << b << " " << c << "\n";
  cout.flush();
  long long int l;
  cin >> l;
  return l;
}
void solve2() {
  long long int n;
  cin >> n;
  vector<long long int> v;
  long long int a = 0;
  long long int b = 0;
  long long int c = 0;
  long long int d = 0;
  for (int i = 0; i < n; i++) {
    long long int l;
    cin >> l;
    v.push_back(l);
    a += ((l % 3) != 0);
    b += (l == 1);
    c += ((l % 3) == 2);
    d += ((l % 3) == 1);
  }
  sort(v.begin(), v.end());
  set<long long int> ss;
  for (int i = 0; i < n; i++) {
    if (v[i] >= ((v[n - 1] / 3) * 3) && v[i] != v[n - 1]) ss.insert(v[i]);
  }
  if (v[n - 1] % 3 == 0) {
    if (a != 0) {
      cout << (v[n - 1] / 3) + 1;
    } else
      cout << (v[n - 1] / 3);
    return;
  } else if (v[n - 1] % 3 == 1) {
    if (b != 0) {
      if (c != 0) {
        cout << (v[n - 1] / 3) + 2;
      } else
        cout << (v[n - 1] / 3) + 1;
    } else {
      auto it = ss.find(v[n - 1] - 1);
      long long int e = 0;
      if (it != ss.end()) {
        e = 1;
      }
      if (c != 0 && e == 1) {
        cout << (v[n - 1] / 3) + 2;
      } else
        cout << (v[n - 1] / 3) + 1;
    }
  } else {
    if (d != 0) {
      cout << (v[n - 1] / 3) + 2;
    } else
      cout << (v[n - 1] / 3) + 1;
  }
}
int main() {
  judge();
  fastio();
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve2();
    cout << " \n";
  }
  cerr << "Time : " << ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
  return 0;
}
