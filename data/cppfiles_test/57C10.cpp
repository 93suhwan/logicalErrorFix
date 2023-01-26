#include <bits/stdc++.h>
template <class C>
C& mini(C& a, C b) {
  if (b < a) a = b;
  return a;
}
template <class C>
C& maxi(C& a, C b) {
  if (a < b) a = b;
  return a;
}
template <typename T>
void read(std::vector<T>& A) {
  for (T& x : A) std::cin >> x;
}
template <typename T>
void readv(std::vector<T>& A) {
  int N;
  std::cin >> N;
  A.resize(N);
  read(A);
}
using namespace std;
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout.setf(ios::fixed);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (s == k) {
      cout << "YES\n";
      continue;
    }
    if (s >= 2 * n || k > s) {
      cout << "NO\n";
      continue;
    }
    long long m = n / k;
    long long need = 2 * k * m + n % k;
    if (need <= s)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
