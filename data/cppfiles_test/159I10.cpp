#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 50;
mt19937 rng(2333);
int n;
unsigned long long h[N], v[N];
int bad[N];
int p[N];
void output(vector<int> res) {
  for (int x : res) bad[x] = 1;
  cout << n - (int)(res).size() << '\n';
  for (int i = 1; i < (n + 1); ++i) {
    if (!bad[i]) cout << i << " ";
  }
  exit(0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  h[0] = 1;
  unsigned long long fp = 0;
  iota(p, p + n + 1, 0);
  for (int i = 2; i < (n + 1); ++i) {
    if (p[i] == i) {
      for (int j = i * 2; j <= n; j += i) p[j] = i;
    }
  }
  cout << endl;
  h[0] = 1;
  for (int i = 1; i < (n + 1); ++i) {
    if (i == 1)
      v[i] = 1;
    else if (p[i] == i)
      v[i] = rng();
    else
      v[i] = v[i / p[i]] ^ v[p[i]];
    h[i] = h[i - 1] ^ v[i];
    fp ^= h[i];
  }
  if (fp == 0) output({});
  map<unsigned long long, int> mp;
  for (int i = 1; i < (n + 1); ++i) mp[h[i] ^ fp] = i;
  if (mp.count(0)) {
    output({mp[0]});
  }
  for (int i = 1; i < (n + 1); ++i) {
    if (mp.count(h[i])) {
      output({i, mp[h[i]]});
    }
  }
  output({2, (n - 1) / 2, n});
}
