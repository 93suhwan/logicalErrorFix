#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int lim;
const int N=2e5;
struct point{
    int x,y,v;
}p[N],q[N];
int n;
int d[N];
int l[5][5][N];
//1 -> left 
//2 -> under
inline bool c1(int *c,int way,int x){
    int *L=l[c[1]][way];
    int d1=lower_bound(L+1,L+n+1,x)-L;
    if(L[d1]<x) return 0;
    L=l[c[2]][way];
    int d2=lower_bound(L+1,L+n+1,x+L[d1])-L;
    if(L[d2]<x+L[d1]) return 0;
    L=l[c[3]][way];
    int d3=lower_bound(L+1,L+n+1,x+L[d2])-L;
    if(L[d3]<x+L[d2]) return 0;
    return 1;
}
vector<pair<int,int>>row[N],line[N];
/*          |
            |--
            |            */
inline bool c2(int *c,int x){
    int d1=0;
    int *L=l[c[1]][1];
    d1=lower_bound(L+1,L+n+1,x)-L;
    if(L[d1]<x) return 0;
    int cl[4];memset(cl,0,sizeof(cl));
    for(int y=1;y<=n;y++){
        for(auto [p,v]:line[y]){
            if(p>d1) cl[v]++;
            if(cl[c[2]]>=x) break;
        }
            if(cl[c[2]]>=x) break;
        
    }
    if(cl[c[2]]<x) return 0;
    if(n/3-cl[c[3]]-l[c[3]][1][d1]<x) return 0;
    return 1;
}
/*          |
          --|
            |            */
inline bool c3(int *c,int x){
    int d1=0;
    int *L=l[c[1]][3];
    d1=upper_bound(L+1,L+n+1,x,greater<int>())-L-1;
    if(L[d1]<x) return 0;
    int cl[4];memset(cl,0,sizeof(cl));
    for(int y=1;y<=n;y++){
        for(auto [p,v]:line[y]){
            if(p<d1) cl[v]++;
            if(cl[c[2]]>=x) break;
        }
            if(cl[c[2]]>=x) break;

    }
    if(cl[c[2]]<x) return 0;
    if(n/3-cl[c[3]]-l[c[3]][3][d1]<x) return 0;
    return 1;
}
/*          
            |
           ---            */
inline bool c4(int *c,int x){
    int d1=0;
    int *L=l[c[1]][2];
    d1=lower_bound(L+1,L+n+1,x)-L;
    if(L[d1]<x) return 0;
    int cl[4];memset(cl,0,sizeof(cl));
    for(int X=1;X<=n;X++){
        for(auto [p,v]:row[X]){
            if(p>d1) cl[v]++;
            if(cl[c[2]]>=x) break;
        }
            if(cl[c[2]]>=x) break;

    }
    if(cl[c[2]]<x) return 0;
    if(n/3-cl[c[3]]-l[c[3]][2][d1]<x) return 0;
    return 1;
}
/*          
          ----
           |            */
inline bool c5(int *c,int x){
    int d1=0;
    int *L=l[c[1]][4];
    d1=upper_bound(L+1,L+n+1,x,greater<int>())-L-1;
    if(L[d1]<x) return 0;
    int cl[4];memset(cl,0,sizeof(cl));
    for(int X=1;X<=n;X++){
        for(auto [p,v]:row[X]){
            if(p<d1) cl[v]++;
            if(cl[c[2]]>=x) break;
        }
            if(cl[c[2]]>=x) break;

    }
    if(cl[c[2]]<x) return 0;
    if(n/3-cl[c[3]]-l[c[3]][4][d1]<x) return 0;
    return 1;
}
/////////////////////////////////////////////
#define YES(s) {if(f)printf("%s",s);return 1;}
inline bool solve(int *c,int x,int f){
    //| | |
    if(c1(c,1,x)) YES("line")
    if(c1(c,2,x)) YES("row")
    if(c2(c,x)) YES("2")
    if(c3(c,x)) YES("3")
    if(c4(c,x)) YES("4")
    if(c5(c,x)) YES("5")
    return 0;
}
inline bool chk(int x,int f=0){
    static int p[4];
    for(int i=1;i<=3;i++) p[i]=i;
    if(solve(p,x,f))return 1;
    while(next_permutation(p+1,p+1+3)){
        if(solve(p,x,f))return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y>>p[i].v;
    }
    p[0]={-int(2e9),-int(2e9),0};
    p[n+1]={n,n,0};

    sort(p+1,p+1+n,[](auto a,auto b){
        if(a.x==b.x)return a.y<b.y;
        return a.x<b.x;
    });
    for(int i=1;i<=n;i++){
        d[i]=d[i-1];
        if(p[i].x!=p[i-1].x) d[i]++;
    }
    for(int i=1;i<=n;i++) p[i].x=d[i];
    sort(p+1,p+1+n,[](auto a,auto b){
        if(a.y==b.y)return a.x<b.x;
        return a.y<b.y;
    });
    for(int i=1;i<=n;i++){
        d[i]=d[i-1];
        if(p[i].y!=p[i-1].y) d[i]++;
    }
    for(int i=1;i<=n;i++) p[i].y=d[i];
//////////////////////////////////////////////////////
    sort(p+1,p+1+n,[](auto a,auto b){
        if(a.x==b.x)return a.y<b.y;
        return a.x<b.x;
    });
    for(int c=1;c<=3;c++)for(int i=1;i<=n+1;i++){
        for(int j=max(1,p[i-1].x+1);j<=p[i].x;j++) l[c][1][j]=l[c][1][j-1];
        if(p[i].v==c) l[c][1][p[i].x]++;
    }
    sort(p+1,p+1+n,[](auto a,auto b){
        if(a.y==b.y)return a.x<b.x;
        return a.y<b.y;
    });;
    for(int c=1;c<=3;c++)for(int i=1;i<=n+1;i++){
        for(int j=max(1,p[i-1].y+1);j<=p[i].y;j++) l[c][2][j]=l[c][2][j-1];
        if(p[i].v==c) l[c][2][p[i].y]++;
    }
//////////////////////////////////////////////////////
    for(int c=1;c<=3;c++)for(int i=1;i<=n;i++){
        l[c][3][i]=n/3-l[c][1][i-1];
        l[c][4][i]=n/3-l[c][2][i-1];
    }
    for(int i=1;i<=n;i++) {
        row[p[i].x].push_back(make_pair(p[i].y,p[i].v));
        line[p[i].y].push_back(make_pair(p[i].x,p[i].v));
    }
////////////////////////////////////////////////////////

    int l=1,r=n/3,ret=0;
    
    while(l<=r){
        int mid=l+r>>1;
        if(chk(mid)) l=mid+1,ret=mid;
        else r=mid-1;
    }
    cout<<ret*3;
    int f;
    if(99999==n&&ret==33465/3){
f=chk(ret,1);
    }
    /////////////////////////////////////

}