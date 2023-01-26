#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const long long int MAX = 1e9 + 7;
void array_show(int* array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%d%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(long long int* array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%lld%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(vector<int>& vec_s, int vec_n = -1, char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%d%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
void array_show(vector<long long int>& vec_s, int vec_n = -1,
                char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%lld%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v1) {
  int n = v1.size();
  for (int i = 0; i < n; i++) {
    if (i) os << " ";
    os << v1[i];
  }
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v1) {
  int n = v1.size();
  for (int i = 0; i < n; i++) is >> v1[i];
  return is;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
namespace sol {
int ques(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int s;
  cin >> s;
  return s;
}
void solve() {
  const int N = 1e9;
  int n, m;
  int i, j, k;
  int a, b, c;
  int z[3] = {1, N};
  int q[3] = {ques(1, 1), ques(1, N), ques(N, 1)};
  int y[2] = {q[0], q[1]};
  vector<int> v1 = {q[0], q[1]};
  while (z[1] - z[0] > 1) {
    z[2] = (z[0] + z[1]) / 2;
    a = ques(1, z[2]);
    v1.push_back(a);
    if (a - y[0] == z[2] - z[0]) {
      z[0] = z[2], y[0] = a;
      continue;
    }
    if (a - y[1] == z[2] - z[1]) {
      z[1] = z[2], y[1] = a;
      continue;
    }
    break;
  }
  sort(v1.begin(), v1.end());
  a = v1[0];
  b = q[0] - a;
  cout << "! " << a + 1 << " " << b + 1 << " " << N - (q[2] - b) << " "
       << N - (q[1] - a) << endl;
}
}  // namespace sol
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  sol::solve();
}
