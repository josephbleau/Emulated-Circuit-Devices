/* COSC 221 : Proj. 1, Emulated Circuits

   Author: Joseph Bleau
   Date: October 3rd, 2012
   Details: Using vector<bool> as our transport type we emulate the
            functionality of variably sized decoders, encoders, and muxers.
            The size of the output is automatically and appropriately 
            determined by the width of the input.
*/

#ifndef EMUCIRC
#define EMUCIRC

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <math.h>

#define device_t vector<bool>(*)(const vector<bool>&) 

std::vector<bool> converge(const std::vector<bool>& a, 
                           const std::vector<bool>& b);
                           
std::vector<bool> notgate(const std::vector<bool>& in);
std::vector<bool> orgate(const std::vector<bool>& in);
std::vector<bool> andgate(const std::vector<bool>& in);
std::vector<bool> encoder(const std::vector<bool>& in);
std::vector<bool> decoder(const std::vector<bool>& in);
std::vector<bool> mux(const std::vector<bool>& in, const std::vector<bool>& sw);

unsigned most_sig_dig(const std::vector<bool>& in);

template<class T>
void reverse_print_vector(const std::vector<T>& vec)
{
  for(int i = vec.size()-1; i >= 0; i--)
  {
	  std::cout << (int) vec[i];
  }
}

template <typename Ret, typename In>
int standalone_device_main(int argc, char* argv[],
                           int reqparams, 
                           const char usage[],
                           Ret (*transform)(const In&))
{	 
	if(argc-1 == reqparams)
	{
		std::vector<std::vector<bool> > bits_in;

		for(unsigned v = 0; v < reqparams; v++)
		{
			bits_in.push_back(std::vector<bool>());
			for(int i = strlen(argv[v+1])-1; i >= 0; i--)
			{
				if(argv[v+1][i] != '0' && argv[v+1][i] != '1')
				{
					std::cout << usage << std::endl;	
					return 2;
				}
				else
				{
					bits_in[v].push_back(argv[v+1][i] == '1');
				}
			}
		}
			 
		switch(reqparams)
		{
			case 1:
			{
				reverse_print_vector(transform(bits_in[0]));
				break;
			}
			case 2:
			{
				Ret (*tptr)(const In&, const In&) = (Ret (*)(const In&, const In&)) transform;	 
				reverse_print_vector(tptr(bits_in[0], bits_in[1]));
				break;
			}
			case 3:
			{
				Ret (*tptr)(const In&, const In&, const In&) = (Ret (*)(const In&, const In&, const In&)) transform;	 
				reverse_print_vector(tptr(bits_in[0], bits_in[1], bits_in[2]));
				break;
			}
			case 4:
			{
				Ret (*tptr)(const In&, const In&, const In&, const In&) = (Ret (*)(const In&, const In&, const In&, const In&)) transform;	 
				reverse_print_vector(tptr(bits_in[0], bits_in[1], bits_in[2], bits_in[3]));
				break;
			}
			default:
			{
				break;
			}
		}
		
		std::cout << std::endl;
	}
	else
	{
		std::cout << usage << std::endl;
		return 1;
	}

	return 0;
}

#endif
