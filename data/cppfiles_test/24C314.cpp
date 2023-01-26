#include <bits/stdc++.h>
using namespace std;
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2;
  }
};
using vote = pair<long long int, long long int>;
using Unordered_map = unordered_map<vote, long long int, pair_hash>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int c = n / 10;
    if ((n % 10) == 9) c++;
    cout << c << endl;
  }
}
