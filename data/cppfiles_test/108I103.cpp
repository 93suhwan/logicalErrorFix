#include <bits/stdc++.h>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
const int MAX = 100001;
const int TREE = 262144;
int n;
int a[MAX], b[MAX];
int maxA[MAX], maxB[MAX];
void compressValues(int arr[MAX]) {
  vector<int> vals;
  for (int i = 0; i < n; i++) vals.push_back(arr[i]);
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
  unordered_map<int, int> pos;
  for (int i = 0; i < (int)vals.size(); i++) pos[vals[i]] = i;
  for (int i = 0; i < n; i++) arr[i] = pos[arr[i]];
}
unordered_map<long long, int> dyn;
int recurse(int A, int B) {
  if (A == a[n - 1] || B == b[n - 1]) return 1;
  long long key = (long long)A * MAX + B;
  if (dyn.find(key) != dyn.end()) return dyn[key];
  int nA = max(A, maxA[B]);
  int nB = max(B, maxB[A]);
  if (A == nA && B == nB) return dyn[key] = 0;
  return dyn[key] = recurse(nA, nB);
}
void solve() {
  compressValues(a);
  compressValues(b);
  memset(maxA, 0, sizeof(maxA));
  memset(maxB, 0, sizeof(maxB));
  for (int i = 0; i < n; i++) {
    maxA[b[i]] = max(maxA[b[i]], a[i]);
    maxB[a[i]] = max(maxB[a[i]], b[i]);
  }
  for (int i = 1; i < MAX; i++) {
    maxA[i] = max(maxA[i], maxA[i - 1]);
    maxB[i] = max(maxB[i], maxB[i - 1]);
  }
  string ans;
  dyn.clear();
  for (int i = 0; i < n; i++) {
    ans += recurse(a[i], b[i]) ? "1" : "0";
  }
  fprintf(out, "%s\n", ans.c_str());
}
int main(void) {
  int numTests;
  fscanf(in, "%d", &numTests);
  for (int test = 0; test < numTests; test++) {
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++) fscanf(in, "%d", &a[i]);
    for (int i = 0; i < n; i++) fscanf(in, "%d", &b[i]);
    solve();
  }
  return 0;
}
