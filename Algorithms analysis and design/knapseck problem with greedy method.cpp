// knapseck problem with greedy method
#include<bits/stdc++.h>
using namespace std;
struct Item{
    int weight,profit;
};
bool compare(Item a, Item b)
{
    double r1 = (double)a.profit/a.weight;
    double r2 =(double)b.profit / b.weight;
    return r1>r2;
}
int main()
{
    int n, capacity;
    cout<<"Enter the number of items : ";
    cin>>n;
    Item item[n];
    cout<<"enter the weight and profit of each item : \n";
    for(int i=0;i<n;i++)
    {
        cin>>item[i].weight>>item[i].profit;
    }
    cout<<"Enter the capacity : ";
    cin>>capacity;
    sort(item,item+n,compare);
    double totalprofit =0.0;
    for(int i=0;i<n;i++)
    {
        if(capacity >= item[i].weight){
            capacity -=item[i].weight;
            totalprofit += item[i].profit;
        }else
        {
            totalprofit += (double)item[i].profit * capacity / item[i].weight;
            break;
        }
    }
    cout<<"Max profit is : "<<totalprofit<<endl;
    return 0;
}
