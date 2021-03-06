// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "widget.h"

void VihdaWidget::cb_headerImage_i(Avtk::Image*, void*) {
  //system("xdg-open http://www.openavproductions.com/artyfx#ducka");
}
void VihdaWidget::cb_headerImage(Avtk::Image* o, void* v) {
  ((VihdaWidget*)(o->parent()->user_data()))->cb_headerImage_i(o,v);
}

void VihdaWidget::cb_graph_i(Avtk::Widener* o, void*) {
  float tmp = o->value();
width->value( tmp );
writePort(VIHDA_WIDTH, tmp);

//volume->value( o->getVolume() );

float a = o->getActive();
writePort(VIHDA_ACTIVE, a);
//printf("active %f\n", a );
}
void VihdaWidget::cb_graph(Avtk::Widener* o, void* v) {
  ((VihdaWidget*)(o->parent()->user_data()))->cb_graph_i(o,v);
}

void VihdaWidget::cb_width_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->value( tmp );
writePort(VIHDA_WIDTH, tmp);
}
void VihdaWidget::cb_width(Avtk::Dial* o, void* v) {
  ((VihdaWidget*)(o->parent()->user_data()))->cb_width_i(o,v);
}

void VihdaWidget::cb_invert_i(Avtk::Button* o, void*) {
  float tmp = o->value();
graph->setInvert( tmp );
writePort(VIHDA_INVERT, tmp);
printf("button %f\n", tmp );
}
void VihdaWidget::cb_invert(Avtk::Button* o, void* v) {
  ((VihdaWidget*)(o->parent()->user_data()))->cb_invert_i(o,v);
}

/**
   if the type of filter changes, this function will highlight the right button
*/
void VihdaWidget::update_button(int button) {
}

VihdaWidget::VihdaWidget() {
  { Fl_Double_Window* o = window = new Fl_Double_Window(160, 220);
    window->user_data((void*)(this));
    { headerImage = new Avtk::Image(0, 0, 160, 29, "header.png");
      headerImage->box(FL_NO_BOX);
      headerImage->color(FL_BACKGROUND_COLOR);
      headerImage->selection_color(FL_BACKGROUND_COLOR);
      headerImage->labeltype(FL_NORMAL_LABEL);
      headerImage->labelfont(0);
      headerImage->labelsize(14);
      headerImage->labelcolor((Fl_Color)20);
      headerImage->callback((Fl_Callback*)cb_headerImage);
      headerImage->align(Fl_Align(FL_ALIGN_CENTER));
      headerImage->when(FL_WHEN_RELEASE_ALWAYS);
      headerImage->setPixbuf(header.pixel_data,4);
    } // Avtk::Image* headerImage
    { graph = new Avtk::Widener(5, 36, 150, 126, "graph");
      graph->box(FL_UP_BOX);
      graph->color((Fl_Color)179);
      graph->selection_color(FL_INACTIVE_COLOR);
      graph->labeltype(FL_NO_LABEL);
      graph->labelfont(0);
      graph->labelsize(14);
      graph->labelcolor(FL_FOREGROUND_COLOR);
      graph->callback((Fl_Callback*)cb_graph);
      graph->align(Fl_Align(FL_ALIGN_BOTTOM));
      graph->when(FL_WHEN_CHANGED);
    } // Avtk::Widener* graph
    { width = new Avtk::Dial(29, 167, 41, 40, "Width");
      width->box(FL_NO_BOX);
      width->color((Fl_Color)90);
      width->selection_color(FL_INACTIVE_COLOR);
      width->labeltype(FL_NORMAL_LABEL);
      width->labelfont(0);
      width->labelsize(10);
      width->labelcolor(FL_FOREGROUND_COLOR);
      width->callback((Fl_Callback*)cb_width);
      width->align(Fl_Align(FL_ALIGN_BOTTOM));
      width->when(FL_WHEN_CHANGED);
    } // Avtk::Dial* width
    { invert = new Avtk::Button(85, 167, 40, 40, "Invert");
      invert->box(FL_NO_BOX);
      invert->color((Fl_Color)90);
      invert->selection_color(FL_INACTIVE_COLOR);
      invert->labeltype(FL_NORMAL_LABEL);
      invert->labelfont(0);
      invert->labelsize(10);
      invert->labelcolor(FL_FOREGROUND_COLOR);
      invert->callback((Fl_Callback*)cb_invert);
      invert->align(Fl_Align(FL_ALIGN_BOTTOM));
      invert->when(FL_WHEN_CHANGED);
      invert->label("Invert");
    } // Avtk::Button* invert
    window->color( fl_rgb_color( 17, 17, 17) );
    close_cb( o, 0 );
    window->end();
  } // Fl_Double_Window* window
}

void VihdaWidget::idle() {
  Fl::check();
  Fl::flush();
}

int VihdaWidget::getWidth() {
  return window->w();
}

int VihdaWidget::getHeight() {
  return window->h();
}

void VihdaWidget::writePort(int port, float& value) {
  //cout << "port " << port << " value " << value << endl;
  write_function(controller, port, sizeof(float), 0, &value);
}

void VihdaWidget::close_cb(Fl_Widget* o, void*) {
  if ((Fl::event() == FL_KEYDOWN || Fl::event() == FL_SHORTCUT) && Fl::event_key() == FL_Escape)
    {
      return; // ignore ESC
    }
    else
    {
      o->hide();
    }
}
