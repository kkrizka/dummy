#include "MNISTData.h"

int main(int argc, char* argv[])
{
  MNISTData data;
  data.load("/home/kkrizka/Projects/dummy/examples/numbers/data/train-labels-idx1-ubyte",
	    "/home/kkrizka/Projects/dummy/examples/numbers/data/train-images-idx3-ubyte");
  
  return 0;
}
