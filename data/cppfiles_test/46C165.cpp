#include <bits/stdc++.h>
using namespace std;
const string ed = "\n";
class BArrayEversion {
 public:
  void solve(std::istream& in, std::ostream& out) {
    ios_base::sync_with_stdio(false);
    in.tie(NULL);
    out.tie(NULL);
    long long int t;
    in >> t;
    while (t--) {
      long long int n;
      in >> n;
      vector<long long int> v(n);
      set<long long int> s;
      for (long long int i = 0; i < n; i++) {
        in >> v[i];
        s.insert(v[i]);
      }
      if (s.size() == 1) {
        out << 0 << ed;
      } else {
        long long int element = v[n - 1];
        long long int count = 0;
        for (long long int i = n - 1; i >= 0; i--) {
          if (v[i] > element) {
            element = v[i];
            count++;
          }
        }
        out << count << ed;
      }
    }
  }
};
int main() {
  BArrayEversion solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
