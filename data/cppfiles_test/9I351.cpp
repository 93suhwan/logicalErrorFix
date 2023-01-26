#include <bits\stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    while(n--){
        string a;
        cin>>a;
        int k=0;
        int d=0;
        int c=0;
        for(i=0;i<a.length();i++){
            k= k +  count(a.begin(),a.end(),a[i]);
            if(k==1){
                c++;
            }
            else if(k==a.length()){
                d=1;

            }
            else{
                continue;
            }
        }
        if(c==a.length()){
            cout<<c/2;
        }

        else if(a.length()==1){
            cout<<0<<endl;
        }
        else{
            cout<<(a.length())/2<<endl;
        }
    }
}