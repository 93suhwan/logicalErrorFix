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
template <class L, class R>
std::ostream& operator<<(std::ostream& os, const std::pair<L, R>& P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  os << "]";
  return os;
}
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout.setf(ios::fixed);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    set<std::pair<int, int> > have;
    for (int i = 0; i < N; i++) {
      int v;
      cin >> v;
      if (v) have.insert({v, i});
    }
    vector<std::pair<int, int> > ret;
    while (have.size() > 1) {
      auto f = have.begin();
      auto vf = *f;
      have.erase(f);
      auto l = prev(have.end());
      auto vl = *l;
      have.erase(l);
      vf.first--;
      vl.first--;
      ret.push_back({vf.second, vl.second});
      if (vf.first) have.insert(vf);
      if (vl.first) have.insert(vl);
    }
    cout << ret.size() << '\n';
    for (auto [x, y] : ret) cout << x + 1 << ' ' << y + 1 << '\n';
  }
  return 0;
}
