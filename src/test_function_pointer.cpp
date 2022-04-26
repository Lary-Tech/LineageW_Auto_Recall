#include <iostream>
#include <vector>
using namespace std;

vector<pair<void(*)(int), int>> vec;

void func1(int i){
    cout << i << endl;
}

void func2(int i){
    cout << i+2 << endl;
}
int main(){
    vec.clear();

    vec.push_back(make_pair(func1, 10));
    vec.push_back(make_pair(func2, 20));

    for(int i=0; i<vec.size(); i++){
        void(*func)(int) = vec[i].first;
        int arg = vec[i].second;

        func(arg);
    }
}
