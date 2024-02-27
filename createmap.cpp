//screen redraw function
//put a pointer that need to draw to stak
//querus easygeo doumentation !!easy to read
draw_main_canas(ezgl::renderer *g){
  - g->set_color(ezgl::BLACK);
  - g->set_color(0,0,0,255); //255 mean opaque draw twice the faster
  - g->set_line_width (3); //3 pixels wide
  //stiky, stay until you change them
  - g->set_line_dash (ezgl::line_dash::asymmetric_5_3);
}

//Draw primitives
- g->draw_line (point1, point2); //from ezgl example program

//sample ezgl function
//the redrawfunction will basically call helper functions
//redraw functions is being called all the time

//0 is black and 255 is broght blue, last parameter to control how transparent the line is
//set pixel width probably
//since called at last, the blue line will on top of all other figures
g->set_line_width(100)
g->set_color(0,0,120,125);
g->draw_line({0,0}, {1000,1050});
