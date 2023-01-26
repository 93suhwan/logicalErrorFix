#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 40;
const int K = 10;
long long atStep[K], newAtStep[K], knownAtStep[K];
int newAtStepCnt[K];
long long stepMask[K][N + 1];
bool backtrack(int step, long long maskOnes) {
  if (step == k) {
    int ones = __builtin_popcountll(maskOnes);
    return maskOnes == ((1LL << ones) - 1);
  }
  int onesCurr = __builtin_popcountll(maskOnes & atStep[step]);
  for (int onesHere = 0; onesHere <= newAtStepCnt[step]; onesHere++) {
    int onesTotal = onesCurr + onesHere;
    long long maskOnesNew = maskOnes | stepMask[step][onesTotal];
    if (!backtrack(step + 1, maskOnesNew)) {
      return false;
    }
  }
  return true;
}
bool solve(vector<vector<int>> &seqs) {
  if (n == 1) {
    return true;
  }
  long long known = 0;
  for (int i = 0; i < k; i++) {
    for (int idx = 0; idx < (int)seqs[i].size(); idx++) {
      int j = seqs[i][idx];
      long long m = 1LL << j;
      atStep[i] |= m;
      stepMask[i][idx + 1] = atStep[i];
      if (!(known & m)) {
        newAtStep[i] |= m;
        known |= m;
      }
    }
    newAtStepCnt[i] = __builtin_popcountll(newAtStep[i]);
    knownAtStep[i] = known;
  }
  if (knownAtStep[k - 1] != ((1LL << n) - 1)) {
    return false;
  }
  return backtrack(0, 0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  vector<vector<int>> seqs(k);
  for (int i = 0; i < k; i++) {
    int len;
    cin >> len;
    while (len--) {
      int j;
      cin >> j;
      j--;
      seqs[i].push_back(j);
    }
  }
  cout << (solve(seqs) ? "ACCEPTED" : "REJECTED");
  return 0;
}
