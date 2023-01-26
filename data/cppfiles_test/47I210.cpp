#include <bits/stdc++.h>
using namespace std;
constexpr long long N = 10005;
constexpr long long D = 200;
constexpr long double EPS = 1e-7;
ofstream fout;
ifstream fin;
long long n, m, sz, k;
int fl;
long long gr(int a, int b) {
  cout << "or " << a + 1 << " " << b + 1 << "\n" << flush;
  long long c;
  cin >> c;
  return c;
}
long long ga(int a, int b) {
  cout << "and " << a + 1 << " " << b + 1 << "\n" << flush;
  long long c;
  cin >> c;
  return c;
}
void solve() {
  long long a, b, c;
  cin >> n >> k;
  vector<long long> v(n);
  {
    long long i1 = ga(0, 1);
    long long i2 = ga(2, 1);
    long long i3 = ga(0, 2);
    long long s1 = gr(0, 1);
    long long s2 = gr(2, 1);
    long long s3 = gr(0, 2);
    v[0] = (((s1 | s2) - i1 - i2 - i3 + (i1 & i3)) ^ (s2 - i2));
    v[1] = (s1 - v[0] + i1);
    v[2] = (s3 - v[0] + i3);
    for (int i = (3); i < (n); i++) {
      a = ga(0, i);
      b = gr(0, i);
      v[i] = (b - v[0] + a);
    }
    sort(v.begin(), v.end());
    cout << "finish " << v[k - 1] << "\n";
  }
}
signed main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(14);
  cout.fixed;
  int t = 1;
  srand(time(0));
  fin.open("input.txt");
  fout.open("output.txt");
  fout.precision(14);
  fout.fixed;
  int y = 0;
  while (t--) {
    solve();
  }
  fout.close();
  fin.close();
}
