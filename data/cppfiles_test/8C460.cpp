#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
template <typename T>
void print_vec(vector<T>& A) {
  for (T& a : A) {
    cout << a << " ";
  }
  cout << "\n";
}
void solve() {
  long long n;
  cin >> n;
  long long c1 = n / 3;
  if (n % 3 == 0) {
    cout << c1 << " " << c1 << "\n";
  } else if (n % 3 == 1) {
    cout << c1 + 1 << " " << c1 << "\n";
  } else {
    cout << c1 << " " << c1 + 1 << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
