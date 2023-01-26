#include <bits/stdc++.h>
using namespace std;
vector<long long> swaps;
long long lenArray, nbSwaps;
void test(long long curSwap, long long maskSeen, long long maskVal) {
  if (curSwap == nbSwaps) {
    for (long long i = 0; i < lenArray; ++i)
      if (!((1LL << i) & maskSeen)) {
        cout << "REJECTED";
        cout << endl;
        exit(0);
      }
    bool seen1 = false;
    for (long long i = 0; i < lenArray; ++i) {
      if ((1LL << i) & maskVal)
        seen1 = true;
      else if (seen1) {
        cout << "REJECTED";
        cout << endl;
        exit(0);
      }
    }
    return;
  }
  long long cntUnset = __builtin_popcountll(~maskSeen & swaps[curSwap]);
  long long cnt1 = __builtin_popcountll(maskVal & swaps[curSwap]);
  long long cnt0 = __builtin_popcountll(swaps[curSwap]) - cnt1 - cntUnset;
  vector<long long> bits;
  for (long long i = 0; i < lenArray; ++i)
    if ((1LL << i) & swaps[curSwap]) bits.push_back(i);
  assert(bits.size() == cntUnset + cnt0 + cnt1);
  long long nxtSeen = maskSeen | swaps[curSwap];
  for (long long add0 = 0; add0 <= cntUnset; ++add0) {
    long long nxtVal = maskVal | swaps[curSwap];
    for (long long i = 0; i < add0 + cnt0; ++i) nxtVal -= 1LL << bits[i];
    test(curSwap + 1, nxtSeen, nxtVal);
  }
}
signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> lenArray >> nbSwaps;
  swaps.resize(nbSwaps);
  for (long long i = 0; i < nbSwaps; ++i) {
    long long l;
    cin >> l;
    for (long long j = 0; j < l; ++j) {
      long long x;
      cin >> x;
      swaps[i] |= 1LL << (x - 1);
    }
  }
  test(0, 0, 0);
  cout << "ACCEPTED\n";
}
