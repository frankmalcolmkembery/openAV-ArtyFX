// generated by Fast Light User Interface Designer (fluid) version 1.0300

#ifndef widget_h
#define widget_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "lv2/lv2plug.in/ns/extensions/ui/ui.h"
#include "../dsp/shared.hxx"
#include "avtk.h"
#include <stdio.h>
#include "header.c"
using namespace std;
#include <iostream>

class CaptaWidget {
public:
  void update_button(int button);
  CaptaWidget();
  Fl_Double_Window *window;
  Avtk::Image *headerImage;
private:
  void cb_headerImage_i(Avtk::Image*, void*);
  static void cb_headerImage(Avtk::Image*, void*);
public:
  Avtk::Record *graph;
private:
  void cb_graph_i(Avtk::Record*, void*);
  static void cb_graph(Avtk::Record*, void*);
public:
  Avtk::Button *rec;
private:
  void cb_rec_i(Avtk::Button*, void*);
  static void cb_rec(Avtk::Button*, void*);
public:
  LV2UI_Write_Function write_function; 
  LV2UI_Controller controller; 
  void idle();
  int getWidth();
  int getHeight();
private:
  float gain; 
  float cutoff; 
  float Q; 
public:
  void writePort(int port, float& value);
  void close_cb(Fl_Widget* o, void*);
};
#endif
