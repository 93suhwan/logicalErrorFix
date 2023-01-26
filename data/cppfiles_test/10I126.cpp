#include <bits/stdc++.h>
#pragma comment(linker, "/stack:16777216")
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MOD = 1e9 + 7;
const long long LOG = 19;
const long long INF = 1e18;
const double PI = acos(-1);
const double EPS = 1e-9;
const long long N = 3e5 + 5;
long long n, k;
vector<long long> a;
map<long long, vector<long long> > q;
bool comp(pair<long long, vector<long long> > a,
          pair<long long, vector<long long> > b) {
  return a.second.size() > b.second.size();
}
bool check(long long x, vector<pair<long long, vector<long long> > > q) {
  vector<pair<long long, vector<long long> > > cnt = q;
  for (long long i = 0; i < k; i++) {
    set<long long> st;
    for (long long j = 0; j < cnt.size(); j++) {
      if (st.size() == x) break;
      if (!st.count(cnt[j].first) && cnt[j].second.size()) {
        st.insert(cnt[j].first);
        cnt[j].second.pop_back();
      }
    }
    if (st.size() != x) return false;
  }
  return true;
}
void solve() {
  cin >> n >> k;
  a.resize(n);
  q.clear();
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (q[a[i]].size() < k) q[a[i]].push_back(i);
  }
  vector<long long> res(n, 0);
  vector<pair<long long, vector<long long> > > cnt;
  for (auto x : q) {
    cnt.push_back(x);
  }
  sort(cnt.begin(), cnt.end(), comp);
  long long l = 1, r = n / k + 1;
  for (long long j = 0; j < 30; j++) {
    long long mid = (l + r) / 2;
    if (check(mid, cnt)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (check(r, cnt)) {
    for (long long i = 1; i <= k; i++) {
      set<long long> st;
      for (long long j = 0; j < cnt.size(); j++) {
        if (st.size() == r) break;
        if (!st.count(cnt[j].first) && cnt[j].second.size()) {
          st.insert(cnt[j].first);
          res[cnt[j].second.back()] = i;
          cnt[j].second.pop_back();
        }
      }
    }
    for (long long i : res) cout << i << ' ';
  } else {
    for (long long i = 1; i <= k; i++) {
      set<long long> st;
      for (long long j = 0; j < cnt.size(); j++) {
        if (st.size() == l) break;
        if (!st.count(cnt[j].first) && cnt[j].second.size()) {
          st.insert(cnt[j].first);
          res[cnt[j].second.back()] = i;
          cnt[j].second.pop_back();
        }
      }
    }
    for (long long i : res) cout << i << ' ';
  }
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
