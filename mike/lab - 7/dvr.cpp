#include <iostream>
using namespace std;
struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];
int main()
{
    cout<<"enter the number of nodes"<<endl;
    int n = 0 , count = 0;
    int costmatrix[100][100];
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>costmatrix[i][j];
            costmatrix[i][i] = 0;
            rt[i].dist[j] = costmatrix[i][j];
            rt[i].from[j] = j;
        }
    }

    do
    {
        count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(rt[i].dist[j] > costmatrix[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = costmatrix[i][k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);
    
    for(int i = 0; i < n; i++)
    {
        cout<<"For Router "<<i+1<<endl;
        for(int j = 0; j < n; j++)
        {
            cout<<"node "<<j+1<<" via "<<rt[i].from[j]+1<<" distance is "<<rt[i].dist[j]<<endl;
        }
    }
    return 0;
}