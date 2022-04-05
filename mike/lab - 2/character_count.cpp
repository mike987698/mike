#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"enter no of frames : ";
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter frame " <<i+1<<" : ";
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<s[i].length()<<s[i];
    }
    cout<<endl;
    return 0;
}