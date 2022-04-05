#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter no of bits"<< endl;
    cin>>n;
    int a[n],b[2*n],z[n];
    cout<<"enter bits:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k=0;
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==1)
        {
            c=c+1;
        }
        else if(a[i]==0)
        {
            c=0;
        }
        b[k]=a[i];
        k=k+1;
        if(c==5 && a[i+1]==1)
        {
            b[k]=0;
            k=k+1;
            c=0;
        }
    }
    c=0;
    cout<<"code sent :";
    for(int i=0;i<k;i++){
        cout<<b[i];
    }
    cout<<endl;
    int y=0;
    for(int i=0;i<k;i++){
        if(a[i]==1)
        {
            c=c+1;
        }
        z[y]=b[i];
        y=y+1;
        if(c==5 && b[i+2]==1){
            i=i+1;
        }

    }
    cout<<"de-stuffing:";
    for(int i=0;i<y;i++){
        cout<<z[i];
    }
    cout<<endl;
    return 0;
}