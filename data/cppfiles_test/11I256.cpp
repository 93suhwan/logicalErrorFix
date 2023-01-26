#include <bits/stdc++.h>
using namespace std;
const int N = 201005;
struct WordA {
  int cnt[5];
  bool operator<(const WordA &a) const {
    if (cnt[0] != a.cnt[0])
      return cnt[0] > a.cnt[0];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsA[N];
struct WordB {
  int cnt[5];
  bool operator<(const WordB &a) const {
    if (cnt[1] != a.cnt[1])
      return cnt[1] > a.cnt[1];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsB[N];
struct WordC {
  int cnt[5];
  bool operator<(const WordC &a) const {
    if (cnt[2] != a.cnt[2])
      return cnt[2] > a.cnt[2];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsC[N];
struct WordD {
  int cnt[5];
  bool operator<(const WordD &a) const {
    if (cnt[3] != a.cnt[3])
      return cnt[3] > a.cnt[3];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsD[N];
struct WordE {
  int cnt[5];
  bool operator<(const WordE &a) const {
    if (cnt[4] != a.cnt[4])
      return cnt[4] > a.cnt[4];
    else {
      int sum = 0;
      int suma = 0;
      for (int i = 0; i < (int)(5); ++i) {
        sum += cnt[i];
        suma += a.cnt[i];
      }
      return sum < suma;
    }
  }
} WordsE[N];
void solve() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<string> vs(n);
    for (int i = 0; i < (int)(n); ++i) {
      cin >> vs[i];
      int tmp[5];
      for (int i = 0; i < (int)(5); ++i) tmp[i] = 0;
      for (char x : vs[i]) {
        int k = x - 'a';
        tmp[k]++;
      }
      for (int j = 0; j < (int)(5); ++j) {
        WordsA[i].cnt[j] = tmp[j];
        WordsB[i].cnt[j] = tmp[j];
        WordsC[i].cnt[j] = tmp[j];
        WordsD[i].cnt[j] = tmp[j];
        WordsE[i].cnt[j] = tmp[j];
      }
    }
    int ret = 0;
    int sum[5];
    for (int i = 0; i < (int)(5); ++i) sum[i] = 0;
    sort(WordsA, WordsA + n);
    int words = 0;
    for (int i = 0; i < (int)(n); ++i) {
      for (int j = 0; j < (int)(5); ++j) {
        sum[j] += WordsA[i].cnt[j];
      }
      if (sum[0] > sum[1] + sum[2] + sum[3] + sum[4]) {
        words++;
      } else {
        for (int j = 0; j < (int)(5); ++j) {
          sum[j] -= WordsA[i].cnt[j];
        }
      }
    }
    ret = max(ret, words);
    words = 0;
    for (int i = 0; i < (int)(5); ++i) sum[i] = 0;
    sort(WordsB, WordsB + n);
    for (int i = 0; i < (int)(n); ++i) {
      for (int j = 0; j < (int)(5); ++j) {
        sum[j] += WordsB[i].cnt[j];
      }
      if (sum[1] > sum[0] + sum[2] + sum[3] + sum[4]) {
        words++;
      } else {
        for (int j = 0; j < (int)(5); ++j) {
          sum[j] -= WordsA[i].cnt[j];
        }
      }
    }
    ret = max(ret, words);
    words = 0;
    for (int i = 0; i < (int)(5); ++i) sum[i] = 0;
    sort(WordsC, WordsC + n);
    for (int i = 0; i < (int)(n); ++i) {
      for (int j = 0; j < (int)(5); ++j) {
        sum[j] += WordsC[i].cnt[j];
      }
      if (sum[2] > sum[0] + sum[1] + sum[3] + sum[4]) {
        words++;
      } else {
        for (int j = 0; j < (int)(5); ++j) {
          sum[j] -= WordsA[i].cnt[j];
        }
      }
    }
    ret = max(ret, words);
    words = 0;
    for (int i = 0; i < (int)(5); ++i) sum[i] = 0;
    sort(WordsD, WordsD + n);
    for (int i = 0; i < (int)(n); ++i) {
      for (int j = 0; j < (int)(5); ++j) {
        sum[j] += WordsD[i].cnt[j];
      }
      if (sum[3] > sum[0] + sum[1] + sum[2] + sum[4]) {
        words++;
      } else {
        for (int j = 0; j < (int)(5); ++j) {
          sum[j] -= WordsA[i].cnt[j];
        }
      }
    }
    ret = max(ret, words);
    words = 0;
    for (int i = 0; i < (int)(5); ++i) sum[i] = 0;
    sort(WordsE, WordsE + n);
    for (int i = 0; i < (int)(n); ++i) {
      for (int j = 0; j < (int)(5); ++j) {
        sum[j] += WordsE[i].cnt[j];
      }
      if (sum[4] > sum[0] + sum[1] + sum[2] + sum[3]) {
        words++;
      } else {
        for (int j = 0; j < (int)(5); ++j) {
          sum[j] -= WordsA[i].cnt[j];
        }
      }
    }
    ret = max(ret, words);
    cout << ret << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(13);
  solve();
  return 0;
}
