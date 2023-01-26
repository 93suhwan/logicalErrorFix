#include <bits/stdc++.h>
using namespace std;
bool equalTo(double a, double b) {
  if (fabs(a - b) <= 1e-9)
    return true;
  else
    return false;
}
bool notEqual(double a, double b) {
  if (fabs(a - b) > 1e-9)
    return true;
  else
    return false;
}
bool lessThan(double a, double b) {
  if (a + 1e-9 < b)
    return true;
  else
    return false;
}
bool lessThanEqual(double a, double b) {
  if (a < b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThan(double a, double b) {
  if (a > b + 1e-9)
    return true;
  else
    return false;
}
bool greaterThanEqual(double a, double b) {
  if (a + 1e-9 > b)
    return true;
  else
    return false;
}
bool check(int mask, int i) { return ((1 << i) & mask); }
int Set(int mask, int i) { return mask | (1 << i); }
long long add(long long a, long long b) {
  if (a + b < 1000000007) return a + b;
  return (a + b) % 1000000007;
}
long long mul(long long a, long long b) {
  if (a * b < 1000000007) return a * b;
  return (a * b) % 1000000007;
}
int dir8[2][8] = {{1, -1, 0, 0, 1, -1, 1, -1}, {0, 0, 1, -1, 1, -1, -1, 1}};
int dir4[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
const int mxn = 200005;
int m, n, row, col, k, first, second;
int verS[mxn], horS[mxn];
int verR[mxn], horR[mxn];
map<int, int> horM, verM;
vector<pair<int, int> > points;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void solve(int test) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%d", &verS[i]);
  for (int i = 0; i < m; i++) scanf("%d", &horS[i]);
  memset(verR, 0, sizeof verR);
  memset(horR, 0, sizeof horR);
  points.clear();
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &first, &second);
    points.push_back({first, second});
  }
  horM.clear();
  verM.clear();
  sort(points.begin(), points.end());
  int prev = 0;
  long long bruh = 0;
  for (auto [first, second] : points) {
    row = upper_bound(horS, horS + m, second) - horS;
    col = upper_bound(verS, verS + n, first) - verS;
    if (prev != col - 1) {
      horM.clear();
    }
    if (horS[row - 1] == second && verS[col - 1] == first) {
      prev = col - 1;
      continue;
    } else if (horS[row - 1] == second) {
      verR[col - 1]++;
      horM[second]++;
      bruh += (horM[second] - 1);
    }
    prev = col - 1;
  }
  sort(points.begin(), points.end(), cmp);
  prev = 0;
  for (auto [first, second] : points) {
    row = upper_bound(horS, horS + m, second) - horS;
    col = upper_bound(verS, verS + n, first) - verS;
    if (prev != row - 1) verM.clear();
    if (horS[row - 1] == second && verS[col - 1] == first) {
      prev = row - 1;
      continue;
    } else if (verS[col - 1] == first) {
      horR[row - 1]++;
      verM[first]++;
      bruh += (verM[first] - 1);
    }
    prev = row - 1;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans += ((long long)verR[i] * (long long)(verR[i] - 1)) / 2;
  for (int i = 0; i < m; i++)
    ans += ((long long)horR[i] * (long long)(horR[i] - 1)) / 2;
  printf("%I64d\n", ans - bruh);
}
void test() {
  int t;
  scanf("%d", &t);
  for (int test = 1; test <= t; test++) {
    solve(test);
  }
}
int main() {
  test();
  return 0;
}
