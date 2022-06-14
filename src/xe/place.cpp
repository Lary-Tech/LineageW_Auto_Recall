#include <Arduino.h>
#include "place.h"
#include "goto_functions.h"

Place::Place(){
    
    insert_place(&Favorites_Tag4, 1);
    insert_place(&Favorites_Tag3, 0);
    insert_place(&marked_locations, 0);
}

Place::~Place(){
}

void Place::execute(change_flag flag){
  int i = count_place;
  void(*func)(int) = place_array[i].func;
  int arg = place_array[i].arg;

  func(arg);

  if(flag == DO_CHANGE_PLACE){
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
