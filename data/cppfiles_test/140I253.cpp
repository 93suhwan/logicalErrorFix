//
//  atcoder.cpp
//
//
///
#include <bits/stdc++.h>

#define REPI(i, S, N) for(int i=int(S); i<int(N); i++)
#define REP(i, N) REPI(i, 0, N)

namespace kyopro {
  using namespace std;
  using ll = int64_t;
  template<typename T> class in {
      T value;
  public:
      in() { cin >> value; }
      operator const T&() const { return value; }
      operator T&() { return value; }
      in& operator=(T source) { value = source; return *this; }
  };
  template<> class in<string> : public string {
  public:
      in() { cin >> *this; }
  };
  template<class T> class inseq : public T {
  public:
      template<typename... Arg> inseq(Arg... arg) : T(forward<Arg>(arg)...) { for (auto&& i : *this) cin >> i; }
  };
  template<class T> using invec = inseq<vector<T>>;
  constexpr array<int, 1000> NotAho() {
      array<int, 1000> r = {0};
      int now = 0, i = 0;
      while(i < 1000) {
          auto divn = now;

          if (now % 3 != 0 && divn % 10 != 3) {
              r[i++] = now;
          }
          now++;
      }
      
      return r;
  } 
  class AtcoderSolver {
  private:
    in<ll> t;
    
  public:
    auto solve() {
        
        REP(i,t) {
            in<ll> n;
            cout << (ll)sqrt((ll)n) + (ll)pow((ll)n, 1.0 / 3.0) - (ll)pow((ll)n, 1.0 / (2.0 * 3.0)) << endl;
        }
    }
  };

  auto solve() {
    AtcoderSolver atcoder;
    return atcoder.solve();
  }

  template<typename T> void plot(const T& func) { cout << setprecision(9) << func() << endl; }
  template<> void plot<void()>(void(&func)()) { func(); }
}

int main() {
  kyopro::plot(kyopro::solve);

  return 0;
}