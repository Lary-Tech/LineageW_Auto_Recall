#ifndef PLACE_H
#define PLACE_H

struct place_func{
    void(*func)(int);
    int arg;
};

class Place{
    public:
        Place();
        ~Place();
        // enum change_flag{ DO_NOT_CHANGE_PLACE, DO_CHANGE_PLACE };
        bool DO_NOT_CHANGE_PLACE = false;
        bool DO_CHANGE_PLACE = true;
        // void execute(change_flag);
        void execute(bool);
        void execute(int);
    private:
        place_func place_array[10];
        int n_place;
        int count_place;

        void insert_place(void(*)(int), int);
};

#endif