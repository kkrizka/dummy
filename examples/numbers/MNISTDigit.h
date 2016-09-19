#ifndef MNISTDIGIT_H_
#define MNISTDIGIT_H_

#include <stdint.h>

#include <string>

class MNISTDigit
{
public:
  MNISTDigit();
  MNISTDigit(uint8_t label, uint32_t nrows, uint32_t ncols, char** data);
  ~MNISTDigit();

  void save(const std::string& path) const;

private:
  uint32_t m_label;

  uint32_t m_nrows, m_ncols;
  char **m_data;
};

#endif // MNISTDIGIT_H_
