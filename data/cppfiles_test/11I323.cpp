#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const double eps = 1e-12;
const double PI = acos(-1.0);
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const long long nax = 5e5 + 5;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isPowerOfTwo(long long int x) { return x && (!(x & (x - 1))); }
void solve() {
  long long int i, n, ans, k, m, j;
  cin >> n;
  vector<pair<long long, long long> > A;
  vector<pair<long long, long long> > B;
  vector<pair<long long, long long> > C;
  vector<pair<long long, long long> > D;
  vector<pair<long long, long long> > E;
  long long total = 0;
  for (i = 0; i < n; i++) {
    string s;
    cin >> s;
    long long cnt = 0;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == 'a') cnt++;
    }
    A.push_back({cnt, s.size()});
    cnt = 0;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == 'b') cnt++;
    }
    B.push_back({cnt, s.size()});
    cnt = 0;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == 'c') cnt++;
    }
    C.push_back({cnt, s.size()});
    cnt = 0;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == 'd') cnt++;
    }
    D.push_back({cnt, s.size()});
    cnt = 0;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == 'e') cnt++;
    }
    E.push_back({cnt, s.size()});
  }
  sort(A.begin(), A.end(),
       [](const pair<long long, long long> &p1,
          const pair<long long, long long> &p2) {
         if (p1.first < p2.first) return true;
         if (p1.first == p2.first) return p1.second > p2.second;
         return false;
       });
  sort(B.begin(), B.end(),
       [](const pair<long long, long long> &p1,
          const pair<long long, long long> &p2) {
         if (p1.first < p2.first) return true;
         if (p1.first == p2.first) return p1.second > p2.second;
         return false;
       });
  sort(C.begin(), C.end(),
       [](const pair<long long, long long> &p1,
          const pair<long long, long long> &p2) {
         if (p1.first < p2.first) return true;
         if (p1.first == p2.first) return p1.second > p2.second;
         return false;
       });
  sort(D.begin(), D.end(),
       [](const pair<long long, long long> &p1,
          const pair<long long, long long> &p2) {
         if (p1.first < p2.first) return true;
         if (p1.first == p2.first) return p1.second > p2.second;
         return false;
       });
  sort(E.begin(), E.end(),
       [](const pair<long long, long long> &p1,
          const pair<long long, long long> &p2) {
         if (p1.first < p2.first) return true;
         if (p1.first == p2.first) return p1.second > p2.second;
         return false;
       });
  reverse((A).begin(), (A).end());
  reverse((B).begin(), (B).end());
  reverse((C).begin(), (C).end());
  reverse((D).begin(), (D).end());
  reverse((E).begin(), (E).end());
  ans = 0;
  long long tmp = 0;
  long long cnt = 0;
  total = 0;
  for (auto x : A) {
    cnt += x.first;
    total += x.second;
    if (cnt > total - cnt) {
      tmp += 1;
      ans = max(ans, tmp);
    } else {
      cnt -= x.first;
      total -= x.second;
    }
  }
  tmp = 0;
  cnt = 0;
  total = 0;
  for (auto x : B) {
    cnt += x.first;
    total += x.second;
    if (cnt > total - cnt) {
      tmp += 1;
      ans = max(ans, tmp);
    } else {
      cnt -= x.first;
      total -= x.second;
    }
  }
  tmp = 0;
  cnt = 0;
  total = 0;
  for (auto x : C) {
    cnt += x.first;
    total += x.second;
    if (cnt > total - cnt) {
      tmp += 1;
      ans = max(ans, tmp);
    } else {
      cnt -= x.first;
      total -= x.second;
    }
  }
  tmp = 0;
  cnt = 0;
  total = 0;
  for (auto x : D) {
    cnt += x.first;
    total += x.second;
    if (cnt > total - cnt) {
      tmp += 1;
      ans = max(ans, tmp);
    } else {
      cnt -= x.first;
      total -= x.second;
    }
  }
  tmp = 0;
  cnt = 0;
  total = 0;
  for (auto x : E) {
    cnt += x.first;
    total += x.second;
    if (cnt > total - cnt) {
      tmp += 1;
      ans = max(ans, tmp);
    } else {
      cnt -= x.first;
      total -= x.second;
    }
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t = 1, i;
  cin >> t;
  while (t--) solve();
  return 0;
}
