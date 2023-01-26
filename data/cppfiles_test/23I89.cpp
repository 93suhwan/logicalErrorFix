#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXSONG = 100;
const int MAXFRIEND = 100;
const int MOD = 998244353;
int nsong, nfriend;
vector<int> like[MAXFRIEND];
const int PERM = 0;
const int ORDERED = 1;
const int LEAF = 2;
struct Node {
  int kind;
  vector<Node*> childs;
  vector<int> leafs;
};
Node* concat(vector<Node*> lst, int kind = PERM) {
  vector<Node*> nlst;
  for (Node* ch : lst)
    if (ch != NULL) nlst.push_back(ch);
  lst = nlst;
  if (((int)(lst).size()) == 0) return NULL;
  if (((int)(lst).size()) == 1) return lst[0];
  auto ret = new Node();
  ret->kind = kind;
  for (Node* ch : lst) {
    ret->childs.push_back(ch);
    for (int x : ch->leafs) ret->leafs.push_back(x);
  }
  return ret;
}
void print(Node* at) {
  if (at->kind == LEAF) {
    printf("%d", at->leafs[0] + 1);
    return;
  }
  printf("%c", at->kind == PERM ? '(' : '[');
  for (int i = (0); i < (((int)(at->childs).size())); ++i) {
    if (i != 0) printf(",");
    print(at->childs[i]);
  }
  printf("%c", at->kind == PERM ? ')' : ']');
}
Node* process(Node* at, set<int> like, bool mustprefix) {
  if (at->kind == LEAF) {
    assert(((int)(at->leafs).size()) == 1 && ((int)(like).size()) == 1 &&
           like.count(at->leafs[0]) == 1);
    return at;
  }
  vector<Node*> none;
  vector<Node*> all;
  vector<int> partial;
  vector<set<int>> to(((int)(at->childs).size()));
  int fst = INT_MAX, lst = INT_MIN;
  for (int i = (0); i < (((int)(at->childs).size())); ++i) {
    for (int x : at->childs[i]->leafs)
      if (like.count(x)) to[i].insert(x);
    if (((int)(to[i]).size()) != 0) fst = min(fst, i), lst = max(lst, i);
    if (((int)(to[i]).size()) == 0)
      none.push_back(at->childs[i]);
    else if (((int)(to[i]).size()) == ((int)(at->childs[i]->leafs).size()))
      all.push_back(at->childs[i]);
    else
      partial.push_back(i);
  }
  if (((int)(all).size()) == ((int)(at->childs).size())) return at;
  assert(((int)(all).size()) + ((int)(partial).size()) >= 1);
  if (((int)(partial).size()) >= 3) return NULL;
  if (mustprefix && ((int)(partial).size()) >= 2) return NULL;
  bool partialprefix =
      mustprefix || ((int)(partial).size()) >= 2 || ((int)(all).size()) >= 1;
  vector<Node*> partialnodes;
  for (int idx : partial) {
    Node* cur = process(at->childs[idx], to[idx], partialprefix);
    if (cur == NULL) return NULL;
    partialnodes.push_back(cur);
  }
  Node* ret;
  if (at->kind == PERM) {
    Node* allnode = concat(all);
    if (mustprefix) {
      Node* nonenode = concat(none);
      vector<Node*> lst;
      lst.push_back(allnode);
      if (((int)(partial).size()) == 1)
        for (auto x : partialnodes[0]->childs) lst.push_back(x);
      lst.push_back(nonenode);
      ret = concat(lst, ORDERED);
    } else {
      if (((int)(partial).size()) >= 2)
        reverse(partialnodes[0]->childs.begin(), partialnodes[0]->childs.end());
      vector<Node*> withlst;
      Node* with;
      if (partialprefix) {
        if (((int)(partial).size()) >= 2)
          for (auto x : partialnodes[0]->childs) withlst.push_back(x);
        withlst.push_back(allnode);
        if (((int)(partial).size()) >= 1)
          for (auto x :
               partialnodes[((int)(partial).size()) >= 2 ? 1 : 0]->childs)
            withlst.push_back(x);
        with = concat(withlst, ORDERED);
      } else {
        assert(((int)(partial).size()) == 1 && ((int)(all).size()) == 0);
        with = partialnodes[0];
      }
      vector<Node*> lst;
      lst.push_back(with);
      for (auto x : none) lst.push_back(x);
      ret = concat(lst);
    }
  } else {
    assert(at->kind == ORDERED);
    if (((int)(all).size()) + ((int)(partial).size()) != lst - fst + 1)
      return NULL;
    for (int i = (0); i < (((int)(partial).size())); ++i)
      if (partial[i] != fst && partial[i] != lst) return NULL;
    if (mustprefix) {
      assert(((int)(partial).size()) <= 1);
      if (fst != 0 || ((int)(partial).size()) == 1 &&
                          ((int)(all).size()) >= 1 && partial[0] == 0) {
        fst = ((int)(at->childs).size()) - 1 - fst,
        lst = ((int)(at->childs).size()) - 1 - lst, swap(fst, lst);
        reverse(none.begin(), none.end());
        reverse(all.begin(), all.end());
        reverse(partial.begin(), partial.end());
        for (int i = (0); i < (((int)(partial).size())); ++i)
          partial[i] = ((int)(at->childs).size()) - 1 - partial[i];
        reverse(to.begin(), to.end());
        reverse(at->childs.begin(), at->childs.end());
      }
      if (fst != 0 || ((int)(partial).size()) == 1 &&
                          ((int)(all).size()) >= 1 && partial[0] == 0)
        return NULL;
    }
    if (((int)(partial).size()) == 0) {
      ret = at;
    } else {
      for (int i = (0); i < (((int)(partial).size())); ++i)
        if (partial[i] != lst && partial[i] == fst)
          reverse(partialnodes[i]->childs.begin(),
                  partialnodes[i]->childs.end());
      vector<Node*> lst;
      for (int i = (0); i < (((int)(at->childs).size())); ++i) {
        bool done = false;
        for (int j = (0); j < (((int)(partial).size())); ++j)
          if (!done && i == partial[j]) {
            done = true;
            for (auto x : partialnodes[j]->childs) lst.push_back(x);
          }
        if (!done) lst.push_back(at->childs[i]);
      }
      ret = concat(lst, ORDERED);
    }
  }
  return ret;
}
int fac[MAXSONG + 1];
int calc(Node* at) {
  int ret = 1;
  for (Node* ch : at->childs) ret = (long long)ret * calc(ch) % MOD;
  if (at->kind == ORDERED) ret = (long long)ret * 2 % MOD;
  if (at->kind == PERM)
    ret = (long long)ret * fac[((int)(at->childs).size())] % MOD;
  return ret;
}
int solve() {
  fac[0] = 1;
  for (int i = (1); i <= (nsong); ++i) fac[i] = (long long)fac[i - 1] * i % MOD;
  Node* root = new Node();
  root->kind = PERM;
  for (int i = (0); i < (nsong); ++i) {
    Node* leaf = new Node();
    leaf->kind = LEAF;
    leaf->leafs.push_back(i);
    root->childs.push_back(leaf);
    root->leafs.push_back(i);
  }
  for (int i = (0); i < (nfriend); ++i) {
    set<int> likeset(like[i].begin(), like[i].end());
    root = process(root, likeset, false);
    if (root == NULL) return 0;
  }
  return calc(root);
}
void run() {
  scanf("%d%d", &nsong, &nfriend);
  for (int i = (0); i < (nfriend); ++i) {
    int cnt;
    scanf("%d", &cnt);
    like[i] = vector<int>(cnt);
    for (int j = (0); j < (cnt); ++j) scanf("%d", &like[i][j]), --like[i][j];
  }
  printf("%d\n", solve());
}
int main() {
  run();
  return 0;
}
