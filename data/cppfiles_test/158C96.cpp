#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1e17;
const long double pi = 3.1415926535897932;
const string endstr = "\n";
template <typename T>
T gcd(T a, T b) {
  return (a == 0) ? b : gcd(b % a, a);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
bool p_comp_fs(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.first < p2.first;
};
bool p_comp_fg(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.first > p2.first;
};
bool p_comp_ss(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.second < p2.second;
};
bool p_comp_sg(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.second > p2.second;
};
template <typename T>
vector<T> uniquen(vector<T> vec) {
  sort((vec).begin(), (vec).end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
inline long long popcnt(long long x) {
  return __builtin_popcountll((unsigned long long)x);
};
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
bool bit(long long st, long long b) { return ((st >> b) & 1) == 1; }
void solve() {
  long long N, M;
  cin >> N >> M;
  vector<long long> X(N);
  for (long long i = 0; i < N; i++) cin >> X[i];
  vector<vector<long long> > S(N, vector<long long>(M, 0));
  for (long long i = 0; i < N; i++)
    for (long long j = 0; j < M; j++) {
      char c;
      cin >> c;
      if (c == '1') S[i][j] = 1;
    }
  long long ans_v = -LINF;
  vector<long long> ans;
  for (long long st = 0; st < (1ll << N); st++) {
    vector<pair<long long, long long> > cnt;
    for (long long j = 0; j < M; j++) {
      long long c = 0;
      for (long long i = 0; i < N; i++) {
        if (bit(st, i))
          c -= S[i][j];
        else
          c += S[i][j];
      }
      cnt.push_back({c, j});
    }
    sort((cnt).begin(), (cnt).end());
    vector<long long> vals(M);
    for (long long j = 0; j < M; j++) {
      vals[cnt[j].second] = j + 1;
    }
    vector<long long> R(N);
    for (long long i = 0; i < N; i++) {
      for (long long j = 0; j < M; j++) {
        R[i] += S[i][j] * vals[j];
      }
    }
    bool ok = true;
    long long ans_c = 0;
    for (long long i = 0; i < N; i++) {
      if (bit(st, i)) {
        ok = ok & (X[i] >= R[i]);
      } else {
        ok = ok & (X[i] <= R[i]);
      }
      ans_c += abs(X[i] - R[i]);
    }
    if (!ok) continue;
    if (chmax(ans_v, ans_c)) {
      ans = vals;
    }
  }
  for (long long v : ans) cout << v << " ";
  cout << endstr;
}
int main(int argc, const char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T;
  cin >> T;
  for (long long _ = 0; _ < T; _++) {
    solve();
  }
  return 0;
}
