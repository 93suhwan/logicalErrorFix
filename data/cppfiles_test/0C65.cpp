#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 15;
const long long oo = ((long long)1e18) + 7;
int N, M, T, K, Q;
string A[MAXN];
int B[MAXN];
bool minimize(int &x, const int &y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
bool maximize(int &x, const int &y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
bool cmp(int x, int y) {
  for (int i = 1; i <= A[x].size(); i++)
    if (A[x][i - 1] != A[y][i - 1])
      return (i & 1) ? A[x][i - 1] < A[y][i - 1] : A[x][i - 1] > A[y][i - 1];
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("A"
            ".inp",
            "r")) {
    freopen(
        "A"
        ".inp",
        "r", stdin);
    freopen(
        "A"
        ".out",
        "w", stdout);
  }
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    B[i] = i;
  }
  sort(B + 1, B + N + 1, cmp);
  for (int i = 1; i <= N; i++) cout << B[i] << ' ';
}
