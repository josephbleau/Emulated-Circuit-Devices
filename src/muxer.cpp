#include "emucirc.h"

using namespace std;

int main(int argc, char* argv[])
{
	standalone_device_main(argc, argv, 2, "Usage: muxer BITS SWITCH", (device_t) mux); 
}
