mkdir -p bin 
echo "Compiling andgate..."
g++ src/andgate.cpp src/emucirc.cpp -o bin/andgate
echo "Compiling orgate..."
g++ src/orgate.cpp src/emucirc.cpp -o bin/orgate
echo "Compiling notgate..."
g++ src/notgate.cpp src/emucirc.cpp -o bin/notgate
echo "Compiling decoder..."
g++ src/decoder.cpp src/emucirc.cpp -o bin/decoder
echo "Compiling encoder..."
g++ src/encoder.cpp src/emucirc.cpp -o bin/encoder
echo "Compiling muxer..."
g++ src/muxer.cpp src/emucirc.cpp -o bin/muxer
