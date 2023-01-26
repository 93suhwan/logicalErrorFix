#include <bits/stdc++.h>
using namespace std;
inline long Length(long left, long right) { return right - left + 1; }
template <class T, class V>
bool Contains(const T& uoset, const V& value) {
  return uoset.find(value) != uoset.end();
}
using TPair = pair<long, long>;
inline bool BySecond(const TPair& left, const TPair& right) {
  return left.second < right.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long T;
  cin >> T;
  if (T > 0)
    for (long i = 0; i <= T - 1; ++i) {
      long n;
      cin >> n;
      unordered_set<long> nums;
      long sq = 1;
      while (sq * sq <= n) {
        nums.insert(sq * sq);
        sq += 1;
      }
      long cu = 1;
      while (cu * cu * cu <= n) {
        nums.insert(cu * cu * cu);
        cu += 1;
      }
      cout << nums.size() << endl;
    }
  return 0;
}
