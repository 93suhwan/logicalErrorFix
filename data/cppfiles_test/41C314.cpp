#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 1;
long long modi(long long numberToMod) {
  numberToMod += mod;
  numberToMod %= mod;
  return numberToMod;
}
long long powerWithMod(long long numberToPower, long long myPower) {
  if (!myPower) return long long(1);
  long long recursive = powerWithMod(numberToPower, myPower / long long(2));
  if (myPower % 2) return modi(modi(recursive * recursive) * numberToPower);
  return modi(recursive * recursive);
}
long long power(long long numberToPower, long long myPower) {
  if (!myPower) return long long(1);
  long long recursive = powerWithMod(numberToPower, myPower / long long(2));
  if (myPower % 2) return recursive * recursive * numberToPower;
  return recursive * recursive;
}
long long gcd(long long numberOne, long long numberTwo) {
  if (numberTwo == 0) return numberOne;
  return gcd(numberTwo, numberOne % numberTwo);
}
vector<long long> compute_pi(string pattern) {
  vector<long long> result(pattern.size());
  result[0] = 0;
  for (unsigned int i = 1; i < pattern.size(); i++) {
    result[i] = 0;
    int KMP_count = result[i - 1];
    while (KMP_count > 0 && pattern[KMP_count] != pattern[i])
      KMP_count = result[KMP_count - 1];
    if (pattern[KMP_count] == pattern[i]) result[i] = KMP_count + 1;
  }
  return result;
}
struct TrieNode {
  struct TrieNode *children[26];
  bool isEndOfWord;
};
struct TrieNode *getNode(void) {
  struct TrieNode *pNode = new TrieNode;
  pNode->isEndOfWord = false;
  for (int i = 0; i < 26; i++) pNode->children[i] = NULL;
  return pNode;
}
void insertTrie(struct TrieNode *root, string key) {
  struct TrieNode *pCrawl = root;
  for (unsigned int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if (!pCrawl->children[index]) pCrawl->children[index] = getNode();
    pCrawl = pCrawl->children[index];
  }
  pCrawl->isEndOfWord = true;
}
bool searchTrie(struct TrieNode *root, string key) {
  struct TrieNode *pCrawl = root;
  for (unsigned int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if (!pCrawl->children[index]) return false;
    pCrawl = pCrawl->children[index];
  }
  return (pCrawl->isEndOfWord);
}
const int maxn = 2e5 + 10;
long long n, m, l, r, sum[10][maxn], last;
string s, save[6];
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> s;
  save[0] = "abc";
  save[1] = "acb";
  save[2] = "bac";
  save[3] = "bca";
  save[4] = "cab";
  save[5] = "cba";
  for (int i = 0; i < n; i++) {
    for (int i2 = 0; i2 < 6; i2++) {
      if (s[i] != save[i2][i % 3]) sum[i2][i] = 1;
    }
    if (i) {
      for (int i2 = 0; i2 < 6; i2++) sum[i2][i] += sum[i2][i - 1];
    }
  }
  while (m--) {
    cin >> l >> r;
    l--;
    r--;
    v.clear();
    if (l == 0) {
      for (int i = 0; i < 6; i++) v.push_back(sum[i][r]);
    } else {
      for (int i = 0; i < 6; i++) v.push_back(sum[i][r] - sum[i][l - 1]);
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
  }
  return 0;
}
