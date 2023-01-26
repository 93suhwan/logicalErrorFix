#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
using vi = vector<long long>;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long powmod(long long a, long long b, long long mod) {
  if (b == 0 || a == 1) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2 == 0) {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  }
}
long long prime(long long p) {
  if (p == 1) return 0;
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return i;
  }
  return 1;
}
long long inv(long long a, long long mod) { return powmod(a, mod - 2, mod); }
template <typename T1>
void ifmax(T1 &max, T1 kek) {
  if (kek > max) max = kek;
  return;
}
template <typename T1>
void ifmin(T1 &min, T1 kek) {
  if (kek < min) min = kek;
  return;
}
template <typename T1>
istream &operator>>(std::istream &in, vector<T1> &a) {
  for (long long i = 0; i < a.size(); i++) in >> a[i];
  return in;
}
template <typename T1>
ostream &operator<<(std::ostream &out, vector<T1> &b) {
  for (long long i = 0; i < b.size(); i++) out << b[i] << " ";
  out << "\n";
  return out;
}
template <typename T1>
void sort(vector<T1> &m) {
  sort(m.begin(), m.end());
}
template <typename T1>
void reverse(vector<T1> &m) {
  reverse(m.begin(), m.end());
}
void solve() {
  long long a;
  cin >> a;
  vector<vector<long long>> m(a, vector<long long>(3));
  vector<pair<long long, long long>> qq(a);
  for (long long i = 0; i < a; i++) {
    cin >> m[i];
    qq[i] = {m[i][0] + m[i][1] - m[i][2], i};
  }
  sort(qq);
  map<long long, vector<long long>> sorted;
  for (long long i = 0; i < a; i++) {
    sorted[qq[i].first].push_back(qq[i].second);
  }
  long long answer = 0;
  vector<long long> ans(a);
  vector<bool> used(a);
  for (auto q : sorted) {
    vector<long long> omegalul = q.second;
    vector<pair<long long, vector<long long>>> parse;
    for (long long i = 0; i < omegalul.size(); i++) {
      parse.push_back({omegalul[i], m[omegalul[i]]});
    }
    vector<pair<long long, pair<long long, long long>>> max_min;
    for (long long i = 0; i < parse.size(); i++) {
      vector<long long> cur = parse[i].second;
      long long a1 = cur[0];
      long long b1 = cur[1];
      long long m1 = cur[2];
      max_min.push_back(
          {parse[i].first, {a1 - max(0LL, m1 - b1), max(0LL, a1 - m1)}});
    }
    for (long long i = 0; i < max_min.size(); i++) {
      swap(max_min[i].first, max_min[i].second.first);
    }
    sort(max_min);
    for (long long i = 0; i < max_min.size(); i++) {
      swap(max_min[i].first, max_min[i].second.first);
    }
    priority_queue<pair<long long, long long>> q2;
    for (long long i = 0; i < max_min.size(); i++) {
      q2.push({-max_min[i].second.second, max_min[i].first});
    }
    for (long long i = 0; i < max_min.size(); i++) {
      if (!used[i]) {
        answer++;
        long long cur1 = max_min[i].second.first;
        while (!q2.empty()) {
          pair<long long, long long> pepega = q2.top();
          if (-pepega.first <= cur1) {
            ans[pepega.second] = m[pepega.second][0] - cur1;
            q2.pop();
            used[pepega.second] = true;
          } else
            break;
        }
      }
    }
  }
  cout << answer << "\n";
  for (long long i = 0; i < a; i++) {
    cout << ans[i] << " " << m[i][2] - ans[i] << "\n";
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  long long multitest = 1;
  long long tututu;
  tututu = 1;
  if (multitest) cin >> tututu;
  for (long long qwerty = 0; qwerty < tututu; qwerty++) solve();
  return 0;
}
