#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "MenuExample\State.h"

class Button {
private:
    int x,y;
    int w,h;

    const char* c_label;
    int label_width;
    int font_size;

    Color bg_color;
    Color txt_color;

    StateSignal signal_to_send;

public:
    Button(int left_x, int top_y, int w, int h, char* str_label, Color bg_col, StateSignal sig_gen);
    Button(int left_x, int top_y, char* str_label, int font_size, Color bg_col, Color txt_col, StateSignal sig_gen);
    ~Button();

    StateSignal Pressed();
    void DrawButton();

    int GetX() {return x;}
    int GetY() {return y;}
    int GetW() {return w;}
    int GetH() {return h;}

};

#endif