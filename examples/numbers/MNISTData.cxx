#include "MNISTData.h"

#include <iostream>
#include <fstream>

MNISTData::MNISTData()
{ }

void MNISTData::load(const std::string& labels, const std::string& images)
{
  std::ifstream fh_labels;
  fh_labels.open(labels.c_str(),std::ios::binary);
  if(!fh_labels.is_open())
    {
      std::cerr << "Error opening labels file!" << std::endl;
      return;
    }

  std::ifstream fh_images;
  fh_images.open(images.c_str(),std::ios::binary);
  if(!fh_images.is_open())
    {
      std::cerr << "Error opening images file!" << std::endl;
      return;
    }

  //
  // Magic number
  uint32_t magic;
  fh_labels.read(reinterpret_cast<char*>(&magic), sizeof(magic));
  magic=revu32(magic);
  if(magic!=0x00000801)
    {
      std::cerr << "Wrong magic " << std::hex << magic << std::dec << " in labels file!" << std::endl;
      return;
    }

  fh_images.read(reinterpret_cast<char*>(&magic), sizeof(magic));
  magic=revu32(magic);
  if(magic!=0x00000803)
    {
      std::cerr << "Wrong magic " << std::hex << magic << std::dec << " in images file!" << std::endl;
      return;
    }

  //
  // Number of images
  uint32_t nimages_labels;
  fh_labels.read(reinterpret_cast<char*>(&nimages_labels), sizeof(nimages_labels));
  nimages_labels=revu32(nimages_labels);

  uint32_t nimages_images;
  fh_images.read(reinterpret_cast<char*>(&nimages_images), sizeof(nimages_images));
  nimages_images=revu32(nimages_images);

  if(nimages_labels!=nimages_images)
    {
      std::cout << nimages_labels << " != " << nimages_images << std::endl;
      return;
    }

  //
  // Load images

  // Rows and columns
  uint32_t nrows, ncols;
  fh_images.read(reinterpret_cast<char*>(&nrows), sizeof(nrows));
  nrows=revu32(nrows);
  fh_images.read(reinterpret_cast<char*>(&ncols), sizeof(ncols));
  ncols=revu32(ncols);
  
  // Data
  char   label;
  char** data;
  for(uint32_t idx; idx<nimages_labels; idx++)
    {
      fh_labels.read(&label,1);
      //printf("%d\n",label);

      data=new char*[nrows];
      for(uint32_t row=0;row<nrows;row++)      
	{
	  data[row]=new char[ncols];

	  data[row]=new char[ncols];
	  for(uint32_t col=0;col<ncols;col++)
	    {
	      fh_images.read(&data[row][col],1);
	    }
	}

      // Make object
      MNISTDigit digit(label, nrows, ncols, data);

    }
}

uint32_t MNISTData::revu32(uint32_t x) const
{
  return ((x>>24)&0x000000FF) | ((x>>8)&0x0000FF00) | ((x<<8)&0x00FF0000) | ((x<<24)&0xFF000000);
}
