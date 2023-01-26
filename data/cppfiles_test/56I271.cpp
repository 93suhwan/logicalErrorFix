//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pii pair<int, int>
#define pb push_back
#define ll int
#define S second
#define ull unsigned long long
#define F first
#define ld long double
//#define int ll
#define sqr(x) (x)*(x)
#define all(x) (x).begin(),(x).end()

using namespace std;
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 gen(chrono::high_resolution_clock().now().time_since_epoch().count());


const int MOD = 998244353;
#ifdef LOCAL
const int inf = 1e3 + 7;
const int N = (1 << 10);
#else
const int inf = 1e6 + 7;
const int N = (1 << 21);
#endif // LOCAL
int can[10][10]; /// start here
int x = 3, y = 3;
int dx = 0, dy = 0;
map < string, pii > mp;
ll kol = 0;
int uk = 0;

vector < string > a;
void xod(int dx1, int dy1){
    x+=dx1;
    y+=dy1;
    cout <<x  << " " << y <<"\n";
    cout.flush();
    string s = "";
    cin >> s;
    if(s == "Done") exit(0);
    dx+=mp[s].F;
    dy+=mp[s].S;
    kol = 0;
    for(int i = 0;i < 8; i++)
        for(int j = 0;j < 8; j++){
            if(i + dx > 7 || i + dx <0 || j + dy > 7 || j + dy < 0){
                can[i][j] = 1;
            }
            int xd = abs(x - i);
            int yd = abs(y - j);
            if(xd == yd || xd == 0 || yd == 0){
                if(i - dx >= 0 && i - dx < 8)
                    if(j - dy >= 0 && j - dy < 8)
                    can[i - dx][j - dy] = 1;
            }
        }
    return;
}
void solve(){
    xod(0, 0);
    int kol1 = 0;
        for(int i = 0;i < 8; i++)
        for(int j = 0;j < 8; j++)
            if(can[i][j] == 0)
            kol1++;


    kol = 0;
//    if(dy == 1){
        xod(0, -2);
////        cerr << kol << " " ;
        xod(0, 2);
//        cerr << kol << " " ;
        xod(0, 2);
//        cerr << kol << " " ;
        xod(0, 2);
//        cerr << kol << " " ;
        xod(-2, 0);
//        cerr << kol << " " ;
        xod(2,  0);
//        cerr << kol << " " ;
        xod(2  ,0);
        xod(-1  ,-1);
        xod(-1  ,-1);
        xod(-1  ,-1);
        xod(-1  ,-1);
        xod(-1  ,-1);
        xod(-1  ,-1);
        xod(-1  ,-1);
        xod(7  ,0);
        xod(-1  ,1);
        xod(-1  ,1);
        xod(-1  ,1);
        xod(-1  ,1);
        xod(-1  ,1);
        xod(-1  ,1);
        xod(-1  ,1);
kol = 0;
    for(int i = 0;i < 8; i++)
        for(int j = 0;j < 8; j++)
            if(can[i][j] == 0)
            kol++;
        if(kol > kol1 ){
            cout << "WHATT\n";
            cout << kol << " " << kol1 <<"\n";

        }

}
int go(int dx, int dy){
    x+=dx;
    y+=dy;
    cout << 1 + x << " "<< y + 1 << "\n";
    cout.flush();
    string s;
    cin >> s;
    if(s == "Done") exit(0);
    dx+=mp[s].F;
    dy+=mp[s].S;
}
int check(int x, int y, int x1, int y1){
    int xd = abs(x - x1);
    int yd = abs(y - y1);
    if(xd == yd) return 0;
    if(x1 < 0) return 0;
    if(y1 < 0) return 0;
    if(x1 == 7) return 0;
    if(y1 == 7) return 0;
    return 1;
}
void mate(int x1, int y1){
    int Now_x = x1 + dx;
    int Now_y = y1 + dy;
    if(x == Now_x && y1 == Now_y) return;
    if(x == Now_x){
        if((x > 3 || x == 0) && x != 7){
            go(1,0);
        }else go(-1, 0);
        Now_x = x1 + dx;
        Now_y = y1 + dy;
    }
    if(y == Now_y){
        if((y > 3 || y == 0) && y != 7){
            go(1,0);
        }else go(-1, 0);
        Now_x = x1 + dx;
        Now_y = y1 + dy;
    }
    while(check(x, y, Now_x, Now_y)){
        if(x > Now_x + 1){
            go(Now_x + 1 - x, 0);
            Now_x = x1 + dx;
            Now_y = y1 + dy;
        }else
        if(y > Now_y + 1){
            go(0, Now_y + 1 - y);
            Now_x = x1 + dx;
            Now_y = y1 + dy;
        }else
        if(x < Now_x - 1){
            go(Now_x - 1 - x, 0);
            Now_x = x1 + dx;
            Now_y = y1 + dy;
        }else
        if(y < Now_y - 1){
            go(0, Now_y - 1 - y);
            Now_x = x1 + dx;
            Now_y = y1 + dy;
        }
    }
}
main() {

//#ifdef LOCAL
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//#else
////    freopen("trie.in","r",stdin);
////    freopen("trie.out","w",stdout);
//#endif LOCAL

//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    mp[""] = {0, 0};
mp["Right"] = {1, 0};
mp["Left"] = {-1, 0};
mp["Up"] = {0, 1};
mp["Down"] = {0, -1};

mp["Down-Right"] = {1, -1};
mp["Down-Left"] = {-1, -1};
mp["Up-Left"] = {-1, 1};
mp["Up-Right"] = {1, 1};
solve();
cerr << "OK\n";
return 0;
for(int i = 0;i < 8; i++)
    for(int j = 0;j < 8 ; j++)
    if(!can[i][j]) mate(i, j);
//    cout << ans <<"\n";
    return 0;
}
