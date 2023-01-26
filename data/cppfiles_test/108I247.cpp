#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
long long int M = 1e9 + 7;
long long int mod(long long int m, long long int mod = M) {
  m %= mod;
  return (m + mod) % mod;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
bool is_prime(long long int x) {
  if (x == 1) return false;
  if (x == 2 || x == 3) return true;
  for (long long int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
long long int power(long long int a, long long int b) {
  long long int res = 1ll;
  while (b > 0) {
    if (b % 2ll) res = (res * a);
    a = (a * a);
    b /= 2ll;
  }
  return res;
}
vector<long long int> primes;
void getPrimes() {
  vector<bool> p(1001, true);
  for (long long int i = 2; i * i <= 1000; i++) {
    if (p[i]) {
      for (long long int j = i * i; j <= 1000; j += i) {
        p[j] = false;
      }
    }
  }
  for (long long int i = 2; i <= 1000; i++) {
    if (p[i]) {
      primes.push_back(i);
    }
  }
}
void build(vector<long long int> &a, vector<long long int> &seg,
           long long int s, long long int e, long long int indx) {
  if (s == e) {
    seg[indx] = a[s];
    return;
  }
  long long int mid = (s + e) / 2;
  build(a, seg, s, mid, 2 * indx);
  build(a, seg, mid + 1, e, 2 * indx + 1);
  seg[indx] = gcd(seg[2 * indx], seg[2 * indx + 1]);
}
void update(vector<long long int> &a, vector<long long int> &seg,
            long long int s, long long int e, long long int indx,
            long long int updindx, long long int val) {
  if (s == e) {
    seg[indx] = val;
    a[updindx] = val;
    return;
  }
  long long int mid = (s + e) / 2;
  if (updindx <= mid)
    update(a, seg, s, mid, 2 * indx, updindx, val);
  else
    update(a, seg, mid + 1, e, 2 * indx + 1, updindx, val);
  seg[indx] = min(seg[2 * indx], seg[2 * indx + 1]);
}
long long int query(vector<long long int> &a, vector<long long int> &seg,
                    long long int s, long long int e, long long int indx,
                    long long int qs, long long int qe) {
  if (s >= qs && e <= qe) {
    return seg[indx];
  } else if (qs > e || qe < s)
    return 0;
  long long int mid = (s + e) / 2;
  return gcd(query(a, seg, s, mid, 2 * indx, qs, qe),
             query(a, seg, mid + 1, e, 2 * indx + 1, qs, qe));
}
bool chk(vector<long long int> &a, vector<long long int> &seg, long long int &n,
         long long int mid, long long int overallgcd) {
  for (long long int i = 0; i < n - mid; i++) {
    long long int x = query(a, seg, 0, n - 1, 1, i, i + mid);
    if (x != overallgcd) return false;
  }
  for (long long int i = n - mid - 1; i < n; i += 1) {
    long long int x = gcd(query(a, seg, 0, n - 1, 1, i, n),
                          query(a, seg, 0, n - 1, 1, 0, (i + mid) % n));
    if (x != overallgcd) return false;
  }
  return true;
}
int main() {
  fastio();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<pair<long long int, long long int>> pa(n), pb(n);
    set<pair<long long int, long long int>> sa, sb;
    for (long long int i = 0; i < n; i++) {
      cin >> pa[i].first;
      pa[i].second = i;
      pa[i].first *= (-1);
      sa.insert(pa[i]);
    }
    for (long long int i = 0; i < n; i++) {
      cin >> pb[i].first;
      pb[i].second = i;
      pb[i].first *= (-1);
      sb.insert(pb[i]);
    }
    vector<long long int> ans(n, 0);
    while (!sa.empty() && !sb.empty()) {
      pair<long long int, long long int> dum1, dum2;
      dum1 = *sa.begin();
      dum2 = *sb.begin();
      ans[dum1.second] = 1;
      ans[dum2.second] = 1;
      if (dum1.second != dum2.second) {
        if (dum1.first < dum2.first) {
          sa.erase(pa[dum2.second]);
          sb.erase(pb[dum2.second]);
        } else {
          sb.erase(pb[dum1.second]);
          sa.erase(pa[dum1.second]);
        }
      } else
        break;
    }
    for (long long int i = 0; i < n; i++) cout << ans[i];
    cout << "\n";
    ;
  }
  return 0;
}
