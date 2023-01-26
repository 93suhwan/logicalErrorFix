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
const int MAX = 1e9 , MIN = - MAX , MOD =   998244353;
const ll MAX_LL = 1e18 , MIN_LL = -MAX_LL;
int binpow(int num , int derajat){
    int ret = 1;
    for (int i = 1 ; i <= derajat ; i <<= 1 , num = (ll)num * num % MOD)
        if (i & derajat)
            ret = (ll)ret * num % MOD;
    return ret;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vi adjl[N + 1];
        for (int i = 1 ; i < N ; ++i){
            int a , b;
            cin >> a >> b;
            adjl[a].push_back(b);
            adjl[b].push_back(a);
        }

        int root;
        for (int i = 1 ; i <= N ; ++i)
            if (adjl[i].size() == 1)
                root = i;

        int all_gcd = 0;
        queue<tuple<int , int , bool>> q; //node , par , state
        q.push(make_tuple(root , 0 , false));
        while(q.size()){
            int node = get<0>(q.front());
            int par = get<1>(q.front());
            bool state = get<2>(q.front());
            q.pop();

            if (state)
                all_gcd = __gcd((int)adjl[node].size() , all_gcd);
            for (int it : adjl[node])
                if (it != par)
                    q.push(make_tuple(it , node , !state));
        }

        int ans = binpow(2 , N - 1);
        if (all_gcd != 1)
            if (--ans < 0)
                ans = MOD - 1;

        cout << ans;
        for (int i = 2 ; i <= N ; ++i){
            if (all_gcd == i)
                cout << " 1";
            else
                cout << " 0";
        }
        cout << '\n';
    }
}
