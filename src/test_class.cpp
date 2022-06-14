#include <iostream>

using namespace std;

class Place{
public:
    Place();
    ~Place();
    void execute(bool);
    void insert_place();
    void printprint();
private:
    int count_place;
    int n_place;
};

Place::Place(){
    n_place = 0;
    insert_place();
    insert_place();
}

Place::~Place(){}

void Place::execute(bool flag){
  if(flag){
    count_place++;
    if(count_place >= n_place){
      count_place = 0;
    }
  }
}

void Place::insert_place(){
  int n = n_place;
  n_place = n + 1;
}

void Place::printprint(){
    cout << count_place << endl;
    cout << n_place << endl;
}

int main(){
    Place p;
    p.execute(true);
    p.printprint();
    p.execute(true);
    p.printprint();
    p.execute(false);
    p.printprint();
    p.execute(true);
    p.printprint();
}