#include "emucirc.h"

int main(int argc, char* argv[])
{
	standalone_device_main(argc, argv, 1, "Usage: andgate BITS", andgate); 
}
