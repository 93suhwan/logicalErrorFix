#include <bits/stdc++.h>
using namespace std;
const long long MOD[4] = {1000000007, 1000000009, 998244353, 1145141919};
string s, t, ss;
int z[700010];
pair<pair<long long, long long>, pair<long long, long long> > h[500010],
    H = {{10, 10}, {10, 10}}, pwH[500010], res;
vector<int> len;
pair<pair<long long, long long>, pair<long long, long long> > operator*(
    pair<pair<long long, long long>, pair<long long, long long> > a,
    pair<pair<long long, long long>, pair<long long, long long> > b) {
  return make_pair(make_pair(a.first.first * b.first.first % MOD[0],
                             a.first.second * b.first.second % MOD[1]),
                   make_pair(a.second.first * b.second.first % MOD[2],
                             a.second.second * b.second.second % MOD[3]));
}
pair<pair<long long, long long>, pair<long long, long long> > operator+(
    pair<pair<long long, long long>, pair<long long, long long> > a,
    long long b) {
  return make_pair(
      make_pair((a.first.first + b) % MOD[0], (a.first.second + b) % MOD[1]),
      make_pair((a.second.first + b) % MOD[2], (a.second.second + b) % MOD[3]));
}
pair<pair<long long, long long>, pair<long long, long long> > operator+(
    pair<pair<long long, long long>, pair<long long, long long> > a,
    pair<pair<long long, long long>, pair<long long, long long> > b) {
  return make_pair(make_pair((a.first.first + b.first.first) % MOD[0],
                             (a.first.second + b.first.second) % MOD[1]),
                   make_pair((a.second.first + b.second.first) % MOD[2],
                             (a.second.second + b.second.second) % MOD[3]));
}
pair<pair<long long, long long>, pair<long long, long long> > operator-(
    pair<pair<long long, long long>, pair<long long, long long> > a,
    pair<pair<long long, long long>, pair<long long, long long> > b) {
  return make_pair(
      make_pair((a.first.first - b.first.first + MOD[0]) % MOD[0],
                (a.first.second - b.first.second + MOD[1]) % MOD[1]),
      make_pair((a.second.first - b.second.first + MOD[2]) % MOD[2],
                (a.second.second - b.second.second + MOD[3]) % MOD[3]));
}
void calcZ() {
  int lb = 0, ub = 0;
  for (int i = 1; i <= ss.size() - 1; ++i) {
    if (ss[i] != ss[0]) continue;
    if (i > ub) {
      int p = i;
      while (p < s.size() && ss[p] == ss[p - i]) p++;
      lb = i;
      ub = p - 1;
      z[i] = p - i;
    } else {
      int j = i - lb;
      if (j + z[j] - 1 < ub - lb)
        z[i] = z[j];
      else {
        int p = ub + 1;
        while (p < ss.size() && ss[p] == ss[p - i]) p++;
        z[i] = p - i;
        lb = i;
        ub = p - 1;
      }
    }
  }
}
void calcLen(int lb, int ub) {
  if (ub - lb + 1 == t.size() - 1) {
    len.push_back(ub - lb + 1);
    return;
  }
  int lcp = z[lb + t.size()];
  if (lcp >= ub - lb + 1) return;
  lb += lcp;
  int tst = lcp;
  if (t[tst] < s[lb]) return;
  len.push_back(ub - lb + 1);
  len.push_back(ub - lb);
}
pair<pair<long long, long long>, pair<long long, long long> > getHash(int lb,
                                                                      int ub) {
  return h[ub + 1] - (h[lb] * pwH[ub - lb + 1]);
}
void Try(int lb1, int ub1, int lb2, int ub2) {
  if (!(lb1 >= 0 && ub1 < s.size() && lb2 >= 0 && ub2 < s.size())) return;
  if (getHash(lb1, ub1) + getHash(lb2, ub2) != res) return;
  int car = 0, cur1 = ub1, cur2 = ub2;
  for (int i = 0; i < t.size(); ++i) {
    if (cur1 >= lb1) car += (s[cur1--] - '0');
    if (cur2 >= lb2) car += (s[cur2--] - '0');
    if (car % 10 != t[t.size() - i - 1] - '0') return;
    car /= 10;
  }
  if (car > 0) return;
  cout << lb1 + 1 << ' ' << ub1 + 1 << endl
       << lb2 + 1 << ' ' << ub2 + 1 << endl;
  exit(0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  ss = t + s;
  calcZ();
  for (int i = 0; i < s.size(); ++i) h[i + 1] = h[i] * H + (s[i] - '0');
  pwH[0] = make_pair(make_pair(1, 1), make_pair(1, 1));
  for (int i = 1; i <= 500005; ++i) pwH[i] = pwH[i - 1] * H;
  for (int i = 0; i < t.size(); ++i) res = res * H + (t[i] - '0');
  for (int i = t.size() - 1; i <= t.size(); ++i) {
    for (int st = 0; st < s.size() - i + 1; ++st) {
      len.clear();
      calcLen(st, st + i - 1);
      for (int j = 0; j < len.size(); ++j) {
        if (s[0] == '6' && s[1] == '2' && s[2] == '3' && s[3] == '4' &&
            st == 390 && st + i - 1 == 944) {
          cout << len[j] << ' ';
        }
        if (len[j] > 0)
          Try(st, st + i - 1, st + i, st + i + len[j] - 1),
              Try(st - 1 - len[j] + 1, st - 1, st, st + i - 1);
      }
    }
  }
  return 0;
}
