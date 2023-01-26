#include <bits/stdc++.h>
using namespace std;
long long PosMod(long long a) { return a >= 0 ? a : a + 998244353; }
long long AddMod(long long a, long long b) {
  return PosMod((a + b) % 998244353);
}
long long MultMod(long long a, long long b) {
  return PosMod((a * b) % 998244353);
}
long long powll(long long a, long long n) {
  long long r = 1;
  for (long long b = n; b > 0; b >>= 1, a = MultMod(a, a))
    if (b & 1) r = MultMod(r, a);
  return r;
}
long long InvMod(long long a) { return powll(a, 998244353 - 2); }
long long Frac(long long a, long long b) { return MultMod(a, InvMod(b)); }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int n, m, k;
int COL[2][2][1000100];
int ROW[2][2][1000100];
map<std::pair<int, int>, int> writtenValue;
long long col_posCnt[3];
long long row_posCnt[3];
long long valid1Cnt[2];
long long valid2Cnt[2];
int calcRPos(int i) {
  int pos = 0;
  pos += ROW[1][1][i] == 0 && ROW[0][0][i] == 0;
  pos += ROW[0][1][i] == 0 && ROW[1][0][i] == 0;
  return pos;
}
int calcCPos(int i) {
  int pos = 0;
  pos += COL[1][1][i] == 0 && COL[0][0][i] == 0;
  pos += COL[0][1][i] == 0 && COL[1][0][i] == 0;
  return pos;
}
std::pair<int, int> calcValid(int i) {
  bool valid1 = ROW[1][1][i] == 0 && ROW[0][0][i] == 0;
  bool valid2 = ROW[0][1][i] == 0 && ROW[1][0][i] == 0;
  if (i % 2 == 0) swap(valid1, valid2);
  return {(int)valid1, (int)valid2};
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  col_posCnt[2] = m;
  row_posCnt[2] = n;
  valid1Cnt[1] = n;
  valid2Cnt[1] = n;
  for (int i = 0; i < k; i++) {
    int r, c, t;
    cin >> r >> c >> t;
    int prevRPos = calcRPos(r);
    int prevCPos = calcCPos(c);
    std::pair<int, int> prevValid = calcValid(r);
    row_posCnt[prevRPos]--;
    col_posCnt[prevCPos]--;
    valid1Cnt[prevValid.first]--;
    valid2Cnt[prevValid.second]--;
    std::pair<int, int> p = {r, c};
    if (writtenValue.count(p) > 0) {
      int val = writtenValue[p];
      COL[r % 2][val][c]--;
      ROW[c % 2][val][r]--;
      writtenValue.erase(p);
    }
    if (t == 0 || t == 1) {
      writtenValue[p] = t;
      COL[r % 2][t][c]++;
      ROW[c % 2][t][r]++;
    }
    int curRPos = calcRPos(r);
    int curCPos = calcCPos(c);
    std::pair<int, int> curValid = calcValid(r);
    row_posCnt[curRPos]++;
    col_posCnt[curCPos]++;
    valid1Cnt[curValid.first]++;
    valid2Cnt[curValid.second]++;
    long long ansR = row_posCnt[0] == 0 ? powll(2, row_posCnt[2]) : 0;
    long long ansC = col_posCnt[0] == 0 ? powll(2, col_posCnt[2]) : 0;
    long long dup =
        (long long)(valid1Cnt[0] == 0) + (long long)(valid2Cnt[0] == 0);
    cout << AddMod(AddMod(ansR, ansC), -dup) << '\n';
  }
}
