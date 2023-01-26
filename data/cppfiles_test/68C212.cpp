#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> seq;
void fill() {
  for (long long int i = 1; 1 + i * (i + 1) <= 1000000000000; i++) {
    seq[1 + i * (i + 1)] = i;
  }
}
int main() {
  fill();
  long long int t, inp1, a, b, val;
  cin >> t;
  vector<long long int> cases;
  for (int i = 0; i < t; i++) {
    cin >> inp1;
    cases.push_back(inp1);
  }
  for (int i = 0; i < t; i++) {
    auto it = seq.lower_bound(cases[i]);
    if (cases[i] == 1) {
      cout << 1 << " " << 1 << "\n";
    } else if (cases[i] == 2) {
      cout << 1 << " " << 2 << "\n";
    } else if (cases[i] == 3) {
      cout << 2 << " " << 2 << "\n";
    } else if (it == seq.begin()) {
      val = (*it).first;
    } else if (it == seq.end()) {
      val = (*(--it)).first;
    } else {
      if (cases[i] - (*(--it)).first < (*(++it)).first - cases[i]) {
        val = (*(--it)).first;
        cout << (*it).second + 1 << " "
             << (*it).second - (cases[i] - (*it).first) + 1 << "\n";
      } else {
        val = (*it).first;
        cout << (*it).second - ((*it).first - cases[i]) + 1 << " "
             << (*it).second + 1 << "\n";
      }
    }
  }
  return 0;
}
