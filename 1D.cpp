#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> R(n);
    for (int i = 0; i < n; i++){
        cin >> R.at(i);
    }
    int maxv = R.at(n - 1) - R.at(0);
    int minv = R.at(0);
    for (int i = 1; i < n; i++){
        maxv = max(maxv, R.at(i) - minv);
        minv = min(minv, R.at(i));
    }
    cout << maxv << endl;
}