#include "MNISTDigit.h"

#include <fstream>

MNISTDigit::MNISTDigit()
  : m_label(0), m_nrows(0), m_ncols(0), m_data(0)
{ }

MNISTDigit::MNISTDigit(uint8_t label, uint32_t nrows, uint32_t ncols, char** data)
  : m_label(0), m_nrows(nrows), m_ncols(ncols), m_data(data)
{ }

MNISTDigit::~MNISTDigit()
{
  if(m_data!=0)
    {
      for(uint32_t row=0;row<m_nrows;row++)      
      	delete[] m_data[row];
      delete[] m_data;  
    }
}

void MNISTDigit::save(const std::string& path) const
{
  //
  // Write out image
  std::ofstream fh(path.c_str());

  fh << "P2" << std::endl;
  fh << m_nrows << " " << m_ncols << std::endl;
  fh << 0xFF << std::endl;

  for(uint32_t row=0;row<m_nrows;row++)      
    {
      for(uint32_t col=0;col<m_ncols;col++)
	fh << (static_cast<unsigned int>(m_data[row][col])&0xFF) << " ";
      fh << std::endl;
    }
  fh.close();
}
