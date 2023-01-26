#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
class A {
  int x;

 public:
  A(int i) { x = i; }
  void print() { cout << x; }
};
class B : public A {
 public:
  B() : A(10) {}
};
class C : public A {
 public:
  C() : A(10) {}
};
class D : public B, public C {};
void solve() {
  long long int a = 1, b = 0, c = 0, t = 0, ans2 = 0, k = -1, ans = 0, c1 = 0,
                c2 = 0, c3 = 0, c4 = 0, n = 0, m = 0, x = 1e18;
  cin >> a;
  cout << (a == 9 ? 1 : a / 10) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t z = clock();
  long long int qc = 1, additionalv;
  cin >> qc;
  for (long long int i = 1; i <= qc; i++) {
    solve();
  }
  fprintf(stderr, "Real Time: % .4Lf\n",
          (long double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
}
