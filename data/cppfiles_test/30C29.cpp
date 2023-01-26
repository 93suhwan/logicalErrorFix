#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
int mult(int a, int b) { return a * (long long)b % mod; }
int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}
struct Vertex {
  int f;
  int r;
};
vector<Vertex> snm;
int get(int v) {
  if (snm[v].f != v) snm[v].f = get(snm[v].f);
  return snm[v].f;
}
void unite(int u, int v) {
  if (snm[u].r > snm[v].r) swap(u, v);
  snm[u].f = v;
  if (snm[u].r == snm[v].r) snm[v].r++;
}
const int N = 1000007;
int pos[N];
int cmp[N];
vector<int> divisors[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) snm.push_back({i, 1});
  for (int i = 0; i < N; ++i) {
    pos[i] = -1;
    cmp[i] = -1;
  }
  vector<int> v(n);
  for (auto& first : v) cin >> first;
  for (int i = 0; i < n; ++i) pos[v[i]] = i;
  for (int i = 2; i < N; ++i) {
    if (divisors[i].size() == 0) {
      for (int j = i; j < N; j += i) divisors[j].push_back(i);
    }
    int last = -1;
    for (int j = i; j < N; j += i) {
      if (pos[j] != -1 && last != -1) {
        int A = get(pos[j]), B = get(last);
        if (A != B) unite(A, B);
      }
      if (pos[j] != -1) {
        last = pos[j];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int G = get(i);
    for (auto first : divisors[v[i]]) {
      cmp[first] = G;
    }
  }
  set<pair<int, int> > united;
  vector<bool> used(n, false);
  for (int i = 0; i < n; ++i) {
    int A = v[i], B = v[i] + 1;
    vector<int> allc;
    allc.push_back(get(i));
    for (auto first : divisors[B]) {
      if (cmp[first] != -1) {
        allc.push_back(cmp[first]);
      }
    }
    vector<int> T;
    for (auto first : allc)
      if (!used[first]) {
        used[first] = true;
        T.push_back(first);
      }
    for (auto first : allc) used[first] = false;
    for (auto first : T)
      for (auto second : T)
        if (first < second) united.insert(make_pair(first, second));
  }
  for (int i = 0; i < q; ++i) {
    int first, second;
    cin >> first >> second;
    first--, second--;
    if (get(first) == get(second)) {
      cout << "0\n";
      continue;
    }
    int A = get(first), B = get(second);
    if (A > B) swap(A, B);
    if (united.count(make_pair(A, B)))
      cout << "1\n";
    else
      cout << "2\n";
  }
}
