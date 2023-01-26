#include <bits/stdc++.h>
using namespace std;
const int N = 12;
const int K = 15;
int n, m, k;
bool c[N][N];
long long po[N];
vector<int> v;
vector<int> odd;
int counter = 0;
vector<pair<int, long long> > arr;
void rec(int i, long long cur) {
  if (i == n) {
    if (counter == 0) arr.push_back(make_pair((int)v.size(), cur));
    return;
  }
  v.push_back(i);
  odd.push_back(1);
  counter++;
  rec(i + 1, cur + po[i] * i);
  v.pop_back();
  odd.pop_back();
  counter--;
  for (int j = 0; j < (int)v.size(); j++) {
    odd[j] ^= 1;
    if (odd[j])
      counter++;
    else
      counter--;
    rec(i + 1, cur + po[i] * v[j]);
    odd[j] ^= 1;
    if (odd[j])
      counter++;
    else
      counter--;
  }
}
void NumToVec(long long num, vector<int> &v) {
  v.clear();
  v.resize(n);
  for (int i = 0; i < n; i++) {
    v[i] = num % N;
    num /= N;
  }
}
vector<pair<int, int> > parr;
bool dp[(1 << (N / 2))][N / 2];
bool check() {
  int sz = (int)parr.size();
  for (int i = 0; i < sz; i++) {
    dp[(1 << sz) - 1][i] = c[parr[i].first][parr[i].second];
  }
  for (int mask = (1 << sz) - 2; mask > 0; mask--) {
    for (int last = 0; last < sz; last++) {
      if (((mask >> last) & 1) == 0) continue;
      dp[mask][last] = false;
      for (int i = 0; i < sz; i++) {
        if (((mask >> i) & 1) == 1) continue;
        if (c[parr[i].first][parr[last].first] &&
            c[parr[i].second][parr[last].second] && dp[mask ^ (1 << i)][i])
          dp[mask][last] = true;
        if (c[parr[i].second][parr[last].first] &&
            c[parr[i].first][parr[last].second] && dp[mask ^ (1 << i)][i])
          dp[mask][last] = true;
      }
    }
  }
  for (int i = 0; i < sz; i++) {
    if (dp[(1 << i)][i]) return true;
  }
  return false;
}
map<long long, bool> good;
long long ans = 0;
int frq[N];
long long nck[K][K], fact[K];
int main() {
  po[0] = 1;
  for (int i = 1; i < N; i++) po[i] = N * po[i - 1];
  fact[0] = 1;
  for (int i = 1; i < K; i++) fact[i] = (long long)i * fact[i - 1];
  for (int i = 0; i < K; i++) {
    nck[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      nck[i][j] = nck[i - 1][j] + nck[i - 1][j - 1];
    }
  }
  scanf("%d%d%d", &n, &m, &k);
  for (int a, b, i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    a--, b--;
    c[a][b] = c[b][a] = true;
  }
  rec(0, 0);
  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());
  long long tmp = 0;
  for (int i = 0; i < (int)arr.size(); i++) {
    if (arr[i].first == n / 2) {
      parr.clear();
      NumToVec(arr[i].second, v);
      for (int j = 0; j < (int)v.size(); j++) {
        if (v[j] != j) parr.push_back(make_pair(j, v[j]));
      }
      good[arr[i].second] = check();
    }
    if (good[arr[i].second]) {
      ans += nck[k][arr[i].first] * fact[arr[i].first];
      if (arr[i].first != n / 2) NumToVec(arr[i].second, v);
      memset(frq, 0, sizeof(frq));
      for (int j = 0; j < (int)v.size(); j++) {
        frq[v[j]]++;
      }
      for (int l = 0; l < n; l++) {
        if (frq[l] == 0) continue;
        for (int j = l + 1; j < n; j++) {
          if (frq[j] == 0 || (frq[l] != 2 && frq[j] != 2)) continue;
          tmp = arr[i].second;
          for (int k = 0; k < (int)v.size(); k++) {
            if (v[k] == j) {
              tmp -= po[k] * j;
              tmp += po[k] * l;
            }
          }
          good[tmp] = true;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
