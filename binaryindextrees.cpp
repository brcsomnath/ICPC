#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getSum(ll BITree[], ll n, ll index)
{
    ll sum = 0;
    index++;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(ll *BITree, ll n, int index, int val)
{
    index++;
    while (index <= n)
    {
       BITree[index] += val;
       index += index & (-index);
    }
}
ll *constructBITree(ll arr[],ll n)
{
    ll *BITree = new ll[n+1];
    for (ll i=1; i<=n; i++)
        BITree[i] = 0;
    for (ll i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
    return BITree;
}
int main()
{
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = constructBITree(freq, n);
    cout << "Sum of elements in arr[0..5] is "
         << getSum(BITree, n, 5);
    freq[3] += 6;
    updateBIT(BITree, n, 3, 6);
 
    cout << "\nSum of elements in arr[0..5] after update is "<< getSum(BITree, n, 5);
    return 0;
}
