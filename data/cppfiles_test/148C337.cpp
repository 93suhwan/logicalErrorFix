#include <bits/stdc++.h>
using namespace std;
const long long int M = 1000000007;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
struct Node {
  long long int val;
  long long int ind;
  long long int lasind;
};
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
  return;
}
bool cmp(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b) {
  if (a.first == b.first) {
    return a.second.first < b.second.first;
  }
  return a.first > b.first;
}
bool cmpp(pair<string, int> a, pair<string, int> b) {
  return a.second < b.second;
}
bool prime(long long int p) {
  for (int i = 2; i <= sqrt(p); i++) {
    if (p % i == 0) return false;
  }
  return true;
}
void swap(long long int &a, long long int &b) {
  int temp = a;
  a = b;
  b = temp;
  return;
}
int computeXOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
long long int factorial(long long int N) {
  long long int fact = 1;
  for (int i = 2; i <= N; i++) fact = (fact * i) % M;
  return (fact % M);
}
void solve() {
  long long int m, n, x, y, z, a, b, c, k;
  string s;
  long long int w, h;
  int h1, h2, v1, v2;
  cin >> w >> h;
  cin >> h1;
  long long int hh1[h1];
  for (long long int i = 0; i < h1; i++) cin >> hh1[i];
  cin >> h2;
  long long int hh2[h2];
  for (long long int i = 0; i < h2; i++) cin >> hh2[i];
  cin >> v1;
  long long int vv1[v1];
  for (long long int i = 0; i < v1; i++) cin >> vv1[i];
  cin >> v2;
  long long int vv2[v2];
  for (long long int i = 0; i < v2; i++) cin >> vv2[i];
  int longesth1 = hh1[h1 - 1] - hh1[0];
  int longesth2 = hh2[h2 - 1] - hh2[0];
  int longestv1 = vv1[v1 - 1] - vv1[0];
  int longestv2 = vv2[v2 - 1] - vv2[0];
  long long int area[4];
  area[0] = longesth1 * h;
  area[1] = longesth2 * h;
  area[2] = longestv1 * w;
  area[3] = longestv2 * w;
  long long int ans = INT_MIN;
  for (int i = 0; i < 4; i++) {
    ans = max(ans, area[i]);
  }
  cout << ans << endl;
}
int main() {
  init_code();
  long long int t = 1;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
  return 0;
}
