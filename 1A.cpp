#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N; cin >> N;
    vector <int> vec(N);
    for (int i = 0; i < N; i++){
        cin >> vec.at(i);
    }

    for (int j = 0; j < N - 1; j++){
        cout << vec.at(j) << " ";
    }
    cout << vec.at(N - 1) << endl;

    for (int i = 1; i < N; i++){
        int j = i - 1;
        int v = vec.at(i);
        while(j >= 0 && vec.at(j) > v){
            vec.at(j+1) = vec.at(j);
            j--; 
        }
        vec.at(j+1) = v;
        for (int j = 0; j < N - 1; j++){
            cout << vec.at(j) << " ";
        }
        cout << vec.at(N - 1) << endl;
    }

}
