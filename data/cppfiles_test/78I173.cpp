#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
vector<string> tokenizer(string str, char ch) {
  std::istringstream var((str));
  vector<string> v;
  string t;
  while (getline((var), t, (ch))) {
    v.push_back(t);
  }
  return v;
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main(int argc, char const *argv[]) {
  file_i_o();
  long long int t;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    long long int b = max(l, (r + 1) / 2);
    long long int a = r;
    if (b != l) {
      cout << b - 1 << "\n";
    } else {
      cout << r % l << "\n";
    }
  }
  return 0;
}
