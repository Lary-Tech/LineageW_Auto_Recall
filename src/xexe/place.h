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
        void gotoPlace(int);
        bool isWait();
    private:
        place_func place_array[10];
        int n_place;
        int count_place;
        bool need_wait[10];

        void insert_place(void(*)(int), int);
};

#endif
