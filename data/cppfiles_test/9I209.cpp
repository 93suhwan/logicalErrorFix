#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_vector(vector<T> x) {
  for (int i = 0; i < x.size(); ++i) {
    cout << x[i] << " ";
  }
  cout << endl;
}
template <typename T>
void print_array(T array[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << array[i] << " ";
  }
  cout << endl;
}
template <typename T, typename S>
void print_map(map<T, S> x) {
  for (typename map<T, S>::iterator it = x.begin(); it != x.end(); it++) {
    cout << it->first << " -> " << it->second << endl;
  }
}
void solve() {
  string s;
  cin >> s;
  map<char, int> m;
  for (int i = 0; i < s.size(); i++) m[s[i]]++;
  if (m.size() < floor((double)s.size() / 2))
    cout << m.size() << endl;
  else
    cout << floor((double)s.size() / 2) << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
