#include <iostream>
#include <vector>

#include "emucirc.h"
 
int main()
{
  // 8 to 3 encoder test (using vec<bool>)
  std::vector<bool> vb_in(8,0);
  vb_in[4] = true; // 10000
  std::vector<bool> vb_out = encoder(vb_in);
  reverse_print_vector(vb_in);
  std::cout << " --> [encoder] --> ";
  reverse_print_vector(vb_out);
  std::cout << "\n\n";

  // 3 to 8 decoder test (using vec<bool>)
  std::vector<bool> vb_out2 = decoder(vb_out); // using output from encoder from last test
  reverse_print_vector(vb_out);
  std::cout << " --> [decoder] --> ";
  reverse_print_vector(vb_out2);
  std::cout << "\n\n";

  // 8 to 1 muxer test, using input from 8 to 3 encoder test
  std::vector<bool> sw(3,0); // switch input for muxer, set to 100
  sw[2] = true;

  std::vector<bool> muxer_out = mux(vb_in, sw);
  reverse_print_vector(vb_in);
  std::cout << " --- > +-----+ " << "\n";
  std::cout << "               | mux | --> "; 
  reverse_print_vector(muxer_out);
  std::cout << "\n";
  reverse_print_vector(sw);
  std::cout << "      --- > +-----+\n";
}
