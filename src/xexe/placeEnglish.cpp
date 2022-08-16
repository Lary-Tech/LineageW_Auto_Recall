#include <Arduino.h>
#include "placeEnglish.h"
#include "goto_functions.h"

PlaceEnglish::PlaceEnglish(){
    n_placeEnglish = 0;

    insert_placeEnglish(&TowerOfInsolence, 0);
    insert_placeEnglish(&parkEarth, 1);
    insert_placeEnglish(&parkWind, 2);

    count_placeEnglish = 0;
    insert_placeEnglish(&TowerOfInsolence, 0);
    insert_placeEnglish(&parkEarth, 1);
    insert_placeEnglish(&parkWind, 2);

    // 指定第幾個圖要不要 wait
    need_wait[0] = false;
    need_wait[1] = false;
    need_wait[2] = false;
    need_wait[3] = false;
    need_wait[4] = false;
    need_wait[5] = false;
}

PlaceEnglish::~PlaceEnglish(){
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

void PlaceEnglish::execute(bool flag){
  int i = count_placeEnglish;
  void(*func)(int) = placeEnglish_array[i].func;
  int arg = placeEnglish_array[i].arg;
  
  func(arg);

  if(flag){
    count_placeEnglish++;
    
    if(count_placeEnglish >= n_placeEnglish){
      count_placeEnglish = 0;
    }
  }
}

void PlaceEnglish::gotoPlaceEnglish(int i){
  void(*func)(int) = placeEnglish_array[i].func;
  int arg = placeEnglish_array[i].arg;

  func(arg);
}

void PlaceEnglish::insert_placeEnglish(void(*func)(int), int arg){
  int n = n_placeEnglish;
  placeEnglish_array[n].func = func;
  placeEnglish_array[n].arg = arg;

  n_placeEnglish = n + 1;
}

bool PlaceEnglish::isWait(){
  return need_wait[count_placeEnglish];
}
