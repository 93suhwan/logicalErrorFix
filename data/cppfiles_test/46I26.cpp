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
        vector<long long int> v2 = v;
        sort(v2.begin(), v2.end());
        if (is_sorted(v.begin(), v.end())) {
          out << 0 << ed;
        } else {
          long long int count = 0;
          for (long long int i = 1; i <= n - 2; i++) {
            if (v[i] < v[i - 1]) {
              count++;
            }
          }
          out << count << ed;
        }
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
