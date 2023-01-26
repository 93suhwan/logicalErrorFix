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
        auto largest = *max_element(v.begin(), v.end());
        long long int count = 0;
        long long int element = v[n - 1];
        while (true) {
          long long int last_element = LLONG_MIN;
          for (long long int i = 0; i < v.size(); i++) {
            if (v[i] > element) {
              last_element = max(last_element, i);
            }
          }
          if (v[last_element] == largest or last_element == LLONG_MIN) {
            count++;
            break;
          } else {
            count++;
            element = v[last_element];
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
