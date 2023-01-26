//                         _
//   _ __ ___    __ _   __| |  ___
//  | '_ ` _ \  / _` | / _` | / _ \
//  | | | | | || (_| || (_| ||  __/
//  |_| |_| |_| \__,_| \__,_| \___|
//
//   _
//  | |__   _   _
//  | '_ \ | | | |
//  | |_) || |_| |
//  |_.__/  \__, |
//          |___/
//                                  _
//   _ __   _   _  _ __    ___   __| |  ___ __   __
//  | '_ \ | | | || '_ \  / __| / _` | / _ \\ \ / /
//  | |_) || |_| || |_) || (__ | (_| ||  __/ \ V /
//  | .__/  \__, || .__/  \___| \__,_| \___|  \_/
//  |_|     |___/ |_|


// --last hope--
//#pragma GCC optimize("03")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//#define int ll
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mkp make_pair
#define INF (ll)1e18
#define INF2 (ll)2e18
#define INF3 (ll)3e18
#define INF4 (ll)4e18
#define inf (signed)1e9
#define inf2 (signed)2e9
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
#define rand32 rng32
#define rand64 rng64
template<typename type,typename comp>
using aset=tree<type,null_type,comp,rb_tree_tag,tree_order_statistics_node_update>;// advanced set with order_of_key and find_by_order
// aset<int,less<int>> is set, but aset<int,less_equal<int> is multiset
const pair<int,int>DIR4[4]={{1,0},{-1,0},{0,1},{0,-1}}; // dirs for 4 ways(like in a matrix)

bool validf(int up,int left,int down,int right,int i,int ii){
    return up<=i&&i<=down&&left<=ii&&ii<=right;
}

// debug tools only
template<typename F,typename S>ostream&operator<<(ostream&output,const pair<F,S>&data){output<<"{"<<data.fi<<","<<data.se<<"}";return output;}
template<typename T>ostream&operator<<(ostream&output,const set<T>&data){if(data.empty())output<<"{}";else{output<<"{"<<*data.begin();for(auto it=next(data.begin());it!=data.end();it++)cout<<","<<*it;output<<"}";}return output;}
template<typename T>ostream&operator<<(ostream&output,const aset<T,less<T>>&data){if(data.empty())output<<"{}";else{output<<"{"<<*data.begin();for(auto it=next(data.begin());it!=data.end();it++)cout<<","<<*it;output<<"}";}return output;}
template<typename T>ostream&operator<<(ostream&output,const aset<T,greater<T>>&data){if(data.empty())output<<"{}";else{output<<"{"<<*data.begin();for(auto it=next(data.begin());it!=data.end();it++)cout<<","<<*it;output<<"}";}return output;}
template<typename T>ostream&operator<<(ostream&output,const multiset<T>&data){if(data.empty())output<<"{}";else{output<<"{"<<*data.begin();for(auto it=next(data.begin());it!=data.end();it++)cout<<","<<*it;output<<"}";}return output;}
template<typename T>ostream&operator<<(ostream&output,const vector<T>&data){if(data.empty())output<<"{}";else{output<<"{"<<*data.begin();for(auto it=next(data.begin());it!=data.end();it++)cout<<","<<*it;output<<"}";}return output;}



// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line
// safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line safe line

const int NMAX=2e5;
string s[NMAX+500];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        bool swapped=0;
        if(m%2==1){
            swap(n,m);
            k=n*m/2-k;
            swapped=1;
        }
        int cnt=n*m/2;
        k=cnt-k;
        if(k%2==1){
            cout<<"NO\n";
            continue;
        }
        int blocks=k/2;
        if(blocks>(n/2)*(m/2)){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        char mx[n+5][m+5];
        for(int i=0;i<=n+1;i++){
            for(int ii=0;ii<=m+1;ii++)mx[i][ii]=' ';
        }
        int x=1;int y=1;
        while(blocks--){
            int xpos=x*2-1;int ypos=y*2-1;

                char letter1='a';

                char letter2='a';
            for(int e=0;e<30;e++){
                if(letter1==mx[ypos][xpos-1])letter1++;
                if(letter1==mx[ypos+1][xpos-1])letter1++;
                if(letter1==mx[ypos-1][xpos])letter1++;
                if(letter1==mx[ypos+2][xpos])letter1++;
                if(letter2==mx[ypos][xpos+2]||letter1==letter2)letter2++;
                if(letter2==mx[ypos+1][xpos+2]||letter1==letter2)letter2++;
                if(letter2==mx[ypos-1][xpos+2]||letter1==letter2)letter2++;
                if(letter2==mx[ypos+2][xpos+2]||letter1==letter2)letter2++;
            }

            mx[ypos][xpos]=letter1;
            mx[ypos+1][xpos]=letter1;
            mx[ypos][xpos+1]=letter2;
            mx[ypos+1][xpos+1]=letter2;
            x++;
            if(x>m/2)x=1,y++;
        }
        int xpos=x*2-1;
        int ypos=y*2-1;
        while(ypos<=n){
            if(ypos==y*2&&xpos<=2*x-2){
                xpos+=2;
                if(xpos>m)xpos=1,ypos++;
                continue;
            }
            char letter='a';
            for(int e=0;e<30;e++){
                if(letter==mx[ypos-1][xpos])letter++;
                if(letter==mx[ypos+1][xpos])letter++;
                if(letter==mx[ypos-1][xpos+1])letter++;
                if(letter==mx[ypos+1][xpos+1])letter++;
                if(letter==mx[ypos][xpos-1])letter++;
                if(letter==mx[ypos][xpos+2])letter++;
            }
            mx[ypos][xpos]=letter;
            mx[ypos][xpos+1]=letter;
            xpos+=2;
            if(xpos>=m)xpos=1,ypos++;
        }
        if(!swapped){
            for(int i=1;i<=n;i++){
                for(int ii=1;ii<=m;ii++)cout<<mx[i][ii];cout<<"\n";
            }
        }else{
            for(int i=1;i<=m;i++){
                for(int ii=1;ii<=n;ii++)cout<<mx[ii][i];cout<<"\n";
            }
        }
    }
}
