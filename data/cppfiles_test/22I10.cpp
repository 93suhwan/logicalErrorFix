#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
vector<int> ss[10];
int order[40];
clock_t init;
unordered_set<string> seen[11];
int k;
int cc = 0;
int check(int c, string& s) {
  cc++;
  if (((cc & 1023) == 0) &&
      ((double)(clock() - init) / CLOCKS_PER_SEC > 0.95)) {
    cout << "ACCEPTED" << endl;
    exit(0);
  }
  if (c == k) {
    int i;
    for (i = 1; i < s.size(); i++) {
      if (s[i - 1] > s[i]) return 0;
    }
    return 1;
  }
  int i, j;
  int q = 0, z = 0;
  string t = s;
  for (i = 0; i < ss[c].size(); i++)
    q += s[ss[c][i]] == '?', z += s[ss[c][i]] == '0';
  if (c & 1) {
    for (j = 0; j < ss[c].size(); j++) t[ss[c][j]] = (j < z) ? '0' : '1';
    for (i = 0; i <= q; i++) {
      if (!check(c + 1, t)) return 0;
      if (i < q) t[ss[c][z + i]] = '0';
    }
  } else {
    for (j = 0; j < ss[c].size(); j++) t[ss[c][j]] = (j < z + q) ? '0' : '1';
    for (i = q; i >= 0; i--) {
      if (!check(c + 1, t)) return 0;
      if (i > 0) t[ss[c][z + i - 1]] = '1';
    }
  }
  return 1;
}
int tt[40];
int main() {
  int i, j;
  int n, q;
  cin >> n >> k;
  for (i = 0; i < k; i++) {
    cin >> q;
    ss[i].resize(q);
    for (j = 0; j < q; j++) cin >> ss[i][j], ss[i][j]--, tt[ss[i][j]]++;
  }
  if (n == 1) {
    cout << "ACCEPTED" << endl;
    return 0;
  }
  for (i = 0; i < n; i++) {
    if (tt[i] == 0) {
      cout << "REJECTED" << endl;
      return 0;
    }
  }
  mt19937 gen(1234);
  for (i = 0; i < n; i++) order[i] = i;
  init = clock();
  while ((double)(clock() - init) / CLOCKS_PER_SEC < 0.03) {
    shuffle(order, order + n, gen);
    for (i = 0; i < k; i++) {
      vector<int> v;
      for (j = 0; j < ss[i].size(); j++) v.push_back(order[ss[i][j]]);
      sort(v.begin(), v.end());
      for (j = 0; j < ss[i].size(); j++) order[ss[i][j]] = v[j];
    }
    for (i = 0; i < n; i++) {
      if (order[i] != i) {
        cout << "REJECTED" << endl;
        return 0;
      }
    }
  }
  string s;
  for (i = 0; i < n; i++) s += '?';
  if (check(0, s)) {
    cout << "ACCEPTED" << endl;
    return 0;
  } else {
    cout << "REJECTED" << endl;
    return 0;
  }
  return 0;
}
