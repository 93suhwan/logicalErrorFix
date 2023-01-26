/// Zengy Manga
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;

#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

using ll = long long;
using ii = pair<int, int>;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define F first
#define S second
#define f(i, a, b)  for(int i = a; i < b; i++)
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) (int)(x).size()
#define mp make_pair
#define popCnt(x) (__builtin_popcountll(x))

const int N = 3e5+5, LG = log2(N) + 1, MOD = 998244353;
const double PI = acos(-1);
int pwr[33];
int level[6];
int k, A, h;
int players[6][32];
int cntLevel[6];
int pos[32];
vector<int> go;
map<int,int> mask;
void bt(int level, int ind, int curSum = 0) {
    if(level == 0) {
        curSum = (curSum + 1ll * players[0][1] * pwr[1]) % MOD;
        pos[players[0][1]] = 1;
        if(curSum == h) {
            for(int i = 1; i <= (1 << k); i++) {
                cout << pos[i] << " ";
            }
            exit(0);
        }
        return;
    }
    if(ind > (1 << level)) {    ///I am done with this list
        bt(level - 1, 1,curSum);
        return;
    }

    ///if the left one loses
    players[level-1][ind/2+1] = players[level][ind+1];  ///this one wins
    pos[players[level][ind]] = ::level[level];
    bt(level, ind + 2, (curSum + 1ll * players[level][ind] * pwr[pos[players[level][ind]]]) % MOD);
    players[level-1][ind/2+1] = players[level][ind];  ///this one wins
    pos[players[level][ind+1]] = ::level[level];
    bt(level, ind + 2, (curSum + 1ll * players[level][ind+1] * pwr[pos[players[level][ind+1]]]) % MOD);
}
void bt2(int level, int ind, int curSum = 0) {
    if(level == 0) {
        curSum = (curSum + 1ll * players[0][1] * pwr[1]) % MOD;
        pos[players[0][1]] = 1;
        if(mask.count((h-curSum) + MOD) % MOD) {    ///found it
            int m = mask[((h-curSum) + MOD) % MOD];
            vector<ii> v;
            for(int j = 1; j <= 32; j+=1) {
                if(j%2==1)
                    v.push_back({pos[j],j});
                else {
                    pos[j] = ::level[5];
                }
            }
            sort(v.begin(),v.end());
            for(int x = 0; x < 16; x++)
            if(m>>x&1) {
                swap(pos[v[x].second],pos[v[x].second+1]);
            }
            for(int i = 1; i <= 32; i++)cout << pos[i] << " ";
            exit(0);
        }
        return;
    }
    if(ind > (1 << level)) {    ///I am done with this list
        bt2(level - 1, 1,curSum);
        return;
    }

    ///if the left one loses
    players[level-1][ind/2+1] = players[level][ind+1];  ///this one wins
    pos[players[level][ind]] = ::level[level];
    bt2(level, ind + 2, (curSum + 1ll * players[level][ind] * pwr[pos[players[level][ind]]]) % MOD);
    players[level-1][ind/2+1] = players[level][ind];  ///this one wins
    pos[players[level][ind+1]] = ::level[level];
    bt2(level, ind + 2, (curSum + 1ll * players[level][ind+1] * pwr[pos[players[level][ind+1]]]) % MOD);
}
void doWork() {
    cin >> k >> A >> h;
    level[0] = 1;
    level[1] = 2;
    level[2] = 3;
    level[3] = 5;
    level[4] = 9;
    level[5] = 17;

    pwr[0] = 1;
    for(int i = 1; i <= 20; i++) {
        pwr[i] = pwr[i-1] * 1ll * A % MOD;
    }

    if(k <= 4) {
        for(int i = 1; i <= (1 << k); i++) {
            players[k][i] = i;
        }
        bt(k,1);
        cout << "-1\n";
    }   else {
        go.push_back(1);
        go.push_back(2);
        go.push_back(3);
        go.push_back(3);
        go.push_back(5);
        go.push_back(5);
        go.push_back(5);
        go.push_back(5);
        go.push_back(9);
        go.push_back(9);
        go.push_back(9);
        go.push_back(9);
        go.push_back(9);
        go.push_back(9);
        go.push_back(9);
        go.push_back(9);
        int sum = 0;
        for(int i = 1; i < 32; i+=2)sum = (sum + 1ll * i * pwr[level[5]]) % MOD;
        for(int i = 0; i < (1 << 16); i++) {
            int val = 0;
            for(int j = 0; j < 16; j++) {
                if(i>>j&1) {
                    val = (val + pwr[go[j]]);
                }   else {
                    val = (val + pwr[level[5]]);
                }
                if(val >= MOD)val -= MOD;
            }
            mask[val] = i;
        }
        for(int i = 1; i <= (1 << k); i++) {
            players[4][i] = i * 2 - 1;
        }
        bt(4,1,sum);
        cout << "-1\n";
    }

}
int32_t main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif // ONLINE_JUDGE
    int t = 1;
//    cin >> t;
    while (t--) {
        doWork();
    }
    return 0;
}
