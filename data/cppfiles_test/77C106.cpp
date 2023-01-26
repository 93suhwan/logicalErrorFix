#include <bits/stdc++.h>
using namespace std;
void iofun() {}
long long Pow(long long c, long long d) {
  return d == 0 ? 1 : c * pow(c, d - 1);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
map<int, string> mp = {{0, "0000"},  {1, "0001"},  {2, "0010"},  {3, "0011"},
                       {4, "0100"},  {5, "0101"},  {6, "0110"},  {7, "0111"},
                       {8, "1000"},  {9, "1001"},  {10, "1010"}, {11, "1011"},
                       {12, "1100"}, {13, "1101"}, {14, "1110"}, {15, "1111"}};
int a[1005][1005], cnt, n, m;
bool visited[1005][1005];
int posi(int k) {
  if (k == 0) return -1;
  if (k == 1) return 0;
  if (k == 2) return +1;
  return 0;
}
int posj(int k) {
  if (k == 0) return 0;
  if (k == 1) return +1;
  if (k == 2) return 0;
  return -1;
}
int calculate(int i, int j) {
  if (i >= n || j >= m || visited[i][j] || i < 0 || j < 0) return 0;
  cnt++;
  visited[i][j] = true;
  string roomstring = mp[a[i][j]];
  for (int k = 0; k < 4; ++k) {
    if (roomstring[k] == '0') {
      int nri = i + posi(k);
      int nrj = j + posj(k);
      calculate(nri, nrj);
    }
  }
  return cnt;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  vector<int> room;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; j++) {
      cnt = 0;
      if (!visited[i][j]) {
        room.push_back(calculate(i, j));
      }
    }
  }
  sort(room.rbegin(), room.rend());
  for (auto it : room) cout << it << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  iofun();
  solve();
  return 0;
}
