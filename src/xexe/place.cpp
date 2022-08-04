#include <Arduino.h>
#include "place.h"
#include "goto_functions.h"

Place::Place(){
    n_place = 0;

    insert_place(&Favorites_Tag2, 0);
    insert_place(&Favorites_Tag2, 1);
    insert_place(&Favorites_Tag2, 2);


    count_place = 0;
    insert_place(&Favorites_Tag2, 0);
    insert_place(&Favorites_Tag2, 1);
    insert_place(&Favorites_Tag2, 2);

    // 指定第幾個圖要不要 wait
    need_wait[0] = false;
    need_wait[1] = false;
    need_wait[2] = false;
    need_wait[3] = false;
    need_wait[4] = false;
    need_wait[5] = false;
}

Place::~Place(){
}

// void Place::execute(change_flag flag){
//   int i = count_place;
//   void(*func)(int) = place_array[i].func;
//   int arg = place_array[i].arg;

//   func(arg);

//   if(flag == DO_CHANGE_PLACE){
//     count_place++;
    
//     if(count_place >= n_place){
//       count_place = 0;
//     }
//   }
// }

void Place::execute(bool flag){
  int i = count_place;
  void(*func)(int) = place_array[i].func;
  int arg = place_array[i].arg;
  
  func(arg);

  if(flag){
    count_place++;
    
    if(count_place >= n_place){
      count_place = 0;
    }
  }
}

void Place::execute(int i){
  void(*func)(int) = place_array[i].func;
  int arg = place_array[i].arg;

  func(arg);
}

void Place::insert_place(void(*func)(int), int arg){
  int n = n_place;
  place_array[n].func = func;
  place_array[n].arg = arg;

  n_place = n + 1;
}

bool Place::isWait(){
  return need_wait[count_place];
}