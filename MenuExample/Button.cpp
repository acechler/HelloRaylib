#include "MenuExample\Button.h"
#include <iostream>

Button::Button(int left_x, int top_y, int w, int h, char* str_label, Color col, StateSignal sig_gen)
: x(left_x), y(top_y), w(w), h(h), c_label(str_label), txt_color(col), signal_to_send(sig_gen){
    std::cout << "Str_Label " << str_label << std::endl;
    label_width = MeasureText(c_label,20);
}

Button::Button(int left_x, int top_y, char* str_label, int font_size, Color bg_col, Color txt_col, StateSignal sig_gen) : x(left_x), y(top_y), c_label(str_label), font_size(font_size), bg_color(bg_col), txt_color(txt_col), signal_to_send(sig_gen), h(font_size + 10){
    std::cout << "Str_Label " << str_label << std::endl;

    label_width = MeasureText(c_label, 20);
    h = font_size + 10;
    w = label_width + 20;
}

Button::~Button(){}

StateSignal Button::Pressed(){
    std::cout << "Button " << c_label << " pressed." << std::endl;
    return signal_to_send;
}

void Button::DrawButton(){
    DrawRectangle(x,y,w,h,bg_color);
    DrawText(c_label, x+5, y+5, 20, txt_color);
}