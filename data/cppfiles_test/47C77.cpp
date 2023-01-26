#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1E9 + 7;
const long double PI = acosl(-1.0);
const int MIRO[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
long long ceil_div(long long index_one, long long index_two) {
  return (index_one + index_two - 1) / index_two;
}
long long bin_pow(long long base, long long power) {
  long long result = 1;
  while (power) {
    if (power & 1) result *= base;
    base *= base;
    power >>= 1;
  }
  return result;
}
long long div_pow(long long base, long long power, long long modulus) {
  base %= modulus;
  long long result = 1;
  while (power) {
    if (power & 1) result = result * base % modulus;
    base = base * base % modulus;
    power >>= 1;
  }
  return result;
}
long long gcd(long long index_one, long long index_two) {
  if (!index_one || !index_two) return index_one | index_two;
  unsigned index_shift = __builtin_ctz(index_one | index_two);
  index_one >>= __builtin_ctz(index_one);
  do {
    index_two >>= __builtin_ctz(index_two);
    if (index_one > index_two) swap(index_one, index_two);
    index_two -= index_one;
  } while (index_two);
  return index_one << index_shift;
}
long long lcm(long long index_one, long long index_two) {
  if (!index_two) return 0;
  return index_one / gcd(index_one, index_two) * index_two;
};
int sign[((int)1E7 >> 5) + 1];
vector<int> prod_raw(int limit) {
  int largest_index = (int)sqrt(limit);
  for (int sign_index = 4; sign_index <= limit; sign_index += 2)
    sign[sign_index >> 5] |= 1 << (sign_index & 31);
  for (int index = 3; index <= largest_index; index += 2) {
    if (!(sign[index >> 5] & 1 << (index & 31))) {
      for (int sign_index = index * index; sign_index <= limit;
           sign_index += index + index)
        sign[sign_index >> 5] |= 1 << (sign_index & 31);
    }
  }
  vector<int> raw;
  raw.push_back(2);
  for (int index = 3; index <= limit; index += 2) {
    if (!(sign[index >> 5] & 1 << (index & 31))) raw.push_back(index);
  }
  return raw;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a < 0)
        neg.push_back(-a);
      else if (a > 0)
        pos.push_back(a);
    }
    sort(pos.rbegin(), pos.rend()), sort(neg.rbegin(), neg.rend());
    long long dist = 0;
    for (int i = 0; i < (int)pos.size(); i += k) dist += 2 * pos[i];
    for (int i = 0; i < (int)neg.size(); i += k) dist += 2 * neg[i];
    dist -= max(!pos.empty() ? pos[0] : 0, !neg.empty() ? neg[0] : 0);
    cout << dist;
    cout << '\n';
  }
  return 0;
}
