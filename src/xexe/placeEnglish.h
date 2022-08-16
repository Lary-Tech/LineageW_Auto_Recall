#ifndef PLACEEnglish_H
#define PLACEEnglish_H

struct placeEnglish_func{
    void(*func)(int);
    int arg;
};

class PlaceEnglish{
    public:
        PlaceEnglish();
        ~PlaceEnglish();
        // enum change_flag{ DO_NOT_CHANGE_PLACE, DO_CHANGE_PLACE };
        bool DO_NOT_CHANGE_PLACEEnglish = false;
        bool DO_CHANGE_PLACEEnglish = true;
        // void execute(change_flag);
        void execute(bool);
        void gotoPlaceEnglish(int);
        bool isWait();
    private:
        placeEnglish_func placeEnglish_array[10];
        int n_placeEnglish;
        int count_placeEnglish;
        bool need_wait[10];

        void insert_placeEnglish(void(*)(int), int);
};

#endif
