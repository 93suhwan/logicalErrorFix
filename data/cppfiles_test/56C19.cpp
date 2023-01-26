#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(NULL));
const long long mod = 1e9 + 7;
vector<vector<long long>> neightbours = {
    {0, 1, 2, 3}, {0, 4, 2, 5}, {1, 4, 3, 5}};
map<char, long long> indexes = {{'w', 0}, {'g', 1}, {'y', 2},
                                {'b', 3}, {'r', 4}, {'o', 5}};
bool isparent(long long a, long long b) {
  while (b > a) b >>= 1;
  return a == b;
}
map<long long, vector<long long>> remind;
vector<long long> solve_small(long long k) {
  if (remind.count(k)) return remind[k];
  if (k == 1) {
    vector<long long> res(6, 1);
    return res;
  } else {
    vector<long long> subres = solve_small(k - 1);
    vector<long long> res(6, 0);
    vector<vector<long long>> list(6);
    for (auto i : neightbours) {
      for (long long j = 0; j < 4; j++) {
        list[i[j]].push_back(i[(j + 1) % 4]);
        list[i[(j + 1) % 4]].push_back(i[j]);
      }
    }
    for (long long i = 0; i < 6; i++) {
      for (long long j = 0; j < list[i].size(); j++) {
        for (long long k = 0; k < list[i].size(); k++) {
          res[i] =
              (res[i] + (subres[list[i][j]] * subres[list[i][k]]) % mod) % mod;
        }
      }
    }
    remind[k] = res;
    return res;
  }
}
vector<long long> solve(long long k, vector<pair<long long, long long>> dots,
                        long long idx = 1) {
  if (!dots.size()) {
    if (!remind.count(k)) remind[k] = solve_small(k);
    return remind[k];
  }
  if (k == 1) {
    vector<long long> res(6, 0);
    res[dots[0].second] = 1;
    return res;
  }
  vector<pair<long long, long long>> ldots, rdots;
  pair<long long, long long> sqrt;
  bool istrue = false;
  for (auto i : dots) {
    if (isparent(2 * idx, i.first))
      ldots.push_back(i);
    else if (isparent(2 * idx + 1, i.first))
      rdots.push_back(i);
    else {
      istrue = true;
      sqrt = i;
    }
  }
  vector<long long> lpart = solve(k - 1, ldots, idx * 2),
                    rpart = solve(k - 1, rdots, idx * 2 + 1);
  vector<long long> res(6, 0);
  vector<vector<long long>> list(6);
  for (auto i : neightbours) {
    for (long long j = 0; j < 4; j++) {
      list[i[j]].push_back(i[(j + 1) % 4]);
      list[i[(j + 1) % 4]].push_back(i[j]);
    }
  }
  if (istrue) {
    long long i = sqrt.second;
    for (long long j = 0; j < list[i].size(); j++) {
      for (long long k = 0; k < list[i].size(); k++) {
        res[i] = (res[i] + (lpart[list[i][j]] * rpart[list[i][k]]) % mod) % mod;
      }
    }
    return res;
  } else {
    for (long long i = 0; i < 6; i++) {
      for (long long j = 0; j < list[i].size(); j++) {
        for (long long k = 0; k < list[i].size(); k++) {
          res[i] =
              (res[i] + (lpart[list[i][j]] * rpart[list[i][k]]) % mod) % mod;
        }
      }
    }
    return res;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long k;
  cin >> k;
  long long n;
  cin >> n;
  vector<pair<long long, long long>> vertices;
  for (long long i = 0; i < n; i++) {
    long long v;
    string s;
    cin >> v >> s;
    vertices.push_back({v, indexes[s[0]]});
  }
  vector<long long> res = solve(k, vertices);
  long long sum = 0;
  for (auto i : res) {
    sum = (sum + i) % mod;
  }
  cout << sum;
}
