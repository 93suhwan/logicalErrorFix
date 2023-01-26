#include <bits/stdc++.h>
using namespace std;
long long int inf = 1e18;
long long int mod = 1e9 + 7;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long int power(long long int x, long long int y, long long int p) {
  if (x == 0) return 0;
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int pwr(long long int x, long long int y) {
  if (x == 0) return 0;
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int ncr(long long int n, long long int r) {
  if (r > n) {
    return 0;
  }
  if (r > n - r) {
    r = n - r;
  }
  long long int ans = 1;
  for (long long int i = 1; i <= r; i++) {
    ans *= (n - i + 1);
    ans %= mod;
    ans *= modInverse(i, mod);
    ans %= mod;
  }
  return ans;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<vector<long long int>> tree(305, vector<long long int>(605, 0));
vector<vector<long long int>> arr(305, vector<long long int>(305, 0));
void bld(long long int n, long long int ctr) {
  for (long long int i = 0; i < n; i++) tree[ctr][n + i] = arr[ctr][i];
  for (long long int i = n - 1; i > 0; --i)
    tree[ctr][i] = tree[ctr][i << 1] + tree[ctr][i << 1 | 1];
}
void upd(long long int n, long long int p, long long int value,
         long long int ctr) {
  tree[ctr][p + n] = value;
  p = p + n;
  for (long long int i = p; i > 1; i >>= 1)
    tree[ctr][i >> 1] = tree[ctr][i] + tree[ctr][i ^ 1];
}
long long int qry(long long int n, long long int l, long long int r,
                  long long int ctr) {
  long long int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += tree[ctr][l++];
    if (r & 1) res += tree[ctr][--r];
  }
  return res;
}
bool cmp(const pair<long long int, long long int> &p1,
         const pair<long long int, long long int> &p2) {
  if (p1.first < p2.first)
    return true;
  else if (p1.first == p2.first) {
    return (p1.second > p2.second);
  } else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int TESTS, i, j, k, flag, t1, t2, t3, t4, t5, t6, t7, t8, t9;
  cin >> TESTS;
  long long int casee = 0;
  while (TESTS--) {
    casee++;
    long long int n, m;
    cin >> n >> m;
    long long int a[n * m];
    vector<pair<long long int, long long int>> vp1(n * m);
    for (i = 0; i < (n * m); i++) {
      cin >> a[i];
      vp1[i] = make_pair(a[i], i);
    }
    sort((vp1).begin(), (vp1).end());
    long long int first, last;
    for (i = 0; i < (n * m); i++) {
      first = i;
      last = i;
      t1 = vp1[i].first;
      i++;
      while (i <= ((n * m) - 1) && t1 == vp1[i].first) {
        last = i;
        i++;
      }
      long long int mid = ((first / m) + 1) * m - 1;
      if ((first / m) != (last / m)) {
        sort(vp1.begin() + first, vp1.begin() + mid + 1, cmp);
        first = mid;
        mid += m;
        while (mid < last) {
          sort(vp1.begin() + first + 1, vp1.begin() + mid + 1, cmp);
          first = mid;
          mid += m;
        }
        mid -= m;
        sort(vp1.begin() + mid + 1, vp1.begin() + last + 1, cmp);
      } else {
        sort(vp1.begin() + first, vp1.begin() + last + 1, cmp);
      }
      i--;
    }
    for (i = 0; i < n; i++) {
      bld(m, i);
    }
    long long int out = 0;
    vector<long long int> found(n * m);
    for (i = 0; i < (n * m); i++) {
      t1 = vp1[i].second;
      found[t1] = i;
    }
    for (i = 0; i < (n * m); i++) {
      long long int row = found[i] / m;
      long long int rem = found[i] - (m * row);
      t1 = qry(m, 0, rem, row);
      out += t1;
      upd(m, rem, 1, row);
    }
    cout << out << "\n";
  }
}
