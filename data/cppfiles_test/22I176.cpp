#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:2108864220")
using namespace std;
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
long long nextLong(long long l, long long r) {
  uniform_int_distribution<long long> foo(l, r);
  return foo(rnd);
}
double nextDouble(double l, double r) {
  uniform_real_distribution<double> foo(l, r);
  return foo(rnd);
}
double workTime() { return double(clock()) / CLOCKS_PER_SEC; }
void myReturn(int code = 0) { exit(code); }
const int MOD = 1000000007;
const int maxN = 40;
const int maxK = 10;
int n, k;
long long mskSuff[maxN + 1];
long long mskChanged[maxK + 1], mskCovered[maxK + 1];
const int partSize = 20;
const long long mskPart = (1ll << partSize) - 1;
int cntBits[1 << partSize];
void initBitCounter() {
  for (int i = 1; i < (1 << mskPart); ++i) {
    for (int j = 0; j < mskPart; ++j) {
      if (i & (1 << j)) {
        cntBits[i] = cntBits[i ^ (1 << j)] + 1;
        break;
      }
    }
  }
}
int countBits(const long long& msk) {
  return cntBits[msk & mskPart] + cntBits[msk >> partSize];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  initBitCounter();
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= k; ++i) {
    int sz;
    scanf("%d", &sz);
    while (sz-- > 0) {
      int j;
      scanf("%d", &j);
      mskChanged[i] |= (1ll << (j - 1));
    }
  }
  if (n == 1) {
    printf("ACCEPTED\n");
    myReturn();
  }
  for (int i = 1; i <= k; ++i) {
    mskCovered[i] = mskCovered[i - 1] | mskChanged[i];
  }
  if (mskCovered[k] != (1ll << n) - 1) {
    printf("REJECTED\n");
    myReturn();
  }
  for (int i = 1; i <= n; ++i) {
    mskSuff[i] = mskSuff[i - 1] | (1ll << (n - i));
  }
  unordered_set<long long> setAchieve;
  for (int i = 0; i <= n; ++i) {
    setAchieve.insert(mskSuff[i] & mskChanged[1]);
  }
  for (int i = 2; i <= k; ++i) {
    long long mskUnchanged = mskSuff[n] ^ mskChanged[i];
    long long mskAppend = mskCovered[i] ^ mskCovered[i - 1];
    int cntAppend = countBits(mskAppend);
    long long mskTakenFromPrev = mskCovered[i - 1] & mskChanged[i];
    vector<long long> vecSortedSuff;
    vecSortedSuff.push_back(0);
    for (int j = 1; j <= n; ++j) {
      if (vecSortedSuff.back() != (mskChanged[i] & mskSuff[j])) {
        vecSortedSuff.push_back(mskChanged[i] & mskSuff[j]);
      }
    }
    unordered_set<long long> setNextStep;
    for (const long long& msk : setAchieve) {
      long long mskStay = msk & mskTakenFromPrev;
      int cntStay = countBits(mskStay);
      for (int j = 0; j <= cntAppend; ++j) {
        long long nextMsk = (msk & mskUnchanged) | vecSortedSuff[cntStay + j];
        setNextStep.insert(nextMsk);
      }
    }
    setAchieve = setNextStep;
    cerr << i << endl;
  }
  for (int i = 0; i <= n; ++i) {
    if (setAchieve.find(mskSuff[i]) == setAchieve.end()) {
      printf("REJECTED\n");
      myReturn();
    }
    setAchieve.erase(mskSuff[i]);
  }
  if (setAchieve.empty()) {
    printf("ACCEPTED\n");
  } else {
    printf("REJECTED\n");
  }
  myReturn();
}
