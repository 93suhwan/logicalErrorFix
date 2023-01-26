#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <fstream>
#include <bitset>
#include <cassert>
#include <cstring>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#define sec second
#define fir first
#define deb(...) deb_print(#__VA_ARGS__ , __VA_ARGS__);
using namespace std;
template <typename ...Args>
void deb_print(string s , Args&& ...arg){
    static const string limiter = "\n";
    cerr << s << " : ";
    cerr << (... , (cout << arg << ' ' , limiter));
}
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int , int>;
using ll = long long;
using ld = long double;
const int MAX = 1e9 , MIN = - MAX , MOD = 998244353;
const ll MAX_LL = 1e18 , MIN_LL = -MAX_LL;

int binpow(int num , int derajat){
    int ret = 1;
    for (int i = 1 ; i <= derajat ; i <<= 1 , num = (ll)num * num % MOD)
        if (i & derajat)
            ret = (ll)ret * num % MOD;
    return ret;
}
int main(){
    vi prime;
    bool computed[(int)1e5 + 1] = {};
    for (int i = 2 ; i <= 100000 ; ++i)
        if (!computed[i]){
           prime.push_back(i);
           if ((ll)i * i <= 100000)
                for (int j = i * i ; j <= 100000 ; j += i)
                    computed[j] = true;
        }

    int T;
    scanf("%d" , &T);
    while(T--){
        int N;
        scanf("%d" , &N);
        vi adjl[N + 1];
        bool possible[N + 1] = {};
        int par[N + 1] , depth[N + 1];

        for (int i = 1 ; i < N ; ++i){
            int a , b;
            scanf("%d%d" , &a , &b);
            adjl[a].push_back(b);
            adjl[b].push_back(a);
        }
        if (N == 2){
            puts("2 0");
            continue;
        }
        int root;
        for (int i = 1 ; i <= N ; ++i)
            if (adjl[i].size() > 1){
                root = i;
                par[i] = depth[i] = 0;
                queue<int> q;
                q.push(i);

                while(q.size()){
                    int node = q.front();
                    q.pop();

                    for (int it : adjl[node])
                        if (it != par[node]){
                            par[it] = node;
                            depth[it] = depth[node] + 1;
                            q.push(it);
                        }
                }
                break;
            }
        pii urut_node[N];
        for (int i = 0 ; i < N ; ++i)
            urut_node[i] = {depth[i + 1] , i + 1};
        sort(urut_node , urut_node + N , greater<pii>());

        for (int it : prime){
            if (it > N)
                break;
            if ((N - 1) % it == 0){
                int mini = MAX;
                int degree[N + 1];
                fill(degree + 1 , degree + N + 1 , 1);
                degree[root] = 0;
                bool sukses = true;

                for (int i = 0 ; i + 1 < N ; ++i){
                    int h_mod = degree[urut_node[i].sec] % it;
                    if (h_mod){
                        if (h_mod > 1){
                            sukses = false;
                            break;
                        }
                        ++degree[par[urut_node[i].sec]];
                        --degree[urut_node[i].sec];
                    }
                    if (degree[urut_node[i].sec])
                        mini = min(mini , degree[urut_node[i].sec]);
                }
                if (sukses && degree[root] % it == 0){
                    if (degree[root])
                        mini = min(mini , degree[root]);
                    possible[mini] = true;
                }
            }
        }

        int sum = 0;
        for (int i = 1 ; i <= N ; ++i)
            sum += possible[i];
            /*if (possible[i])
                cout << i << endl;*/

        printf("%d" , (binpow(2 , N - 1) - sum + MOD) % MOD);
        for (int i = 2 ; i <= N ; ++i){
            if (possible[i])
                printf(" 1");
            else
                printf(" 0");
        }
        puts("");
    }
}
