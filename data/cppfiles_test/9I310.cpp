#include <bits\stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        int e= a.length();
        int k=0;
        int d=0;
        
        for(i=0;i<e;i++){
            k=k+count(a.begin(),a.end(),a[i]);
            if(k==e){
                d=1;
            }
            else{
                continue;
            }
            
        }
        if(d==1){
            cout<<1<<endl;

        }
        else{
            cout<<e/2<<endl;

        }

    }
    return 0;

}