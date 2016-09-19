#ifndef MNISTDATA_H_
#define MNISTDATA_H_

#include <stdint.h>

#include <string>
#include <vector>

#include "MNISTDigit.h"

class MNISTData
{
public:
  MNISTData();

  void load(const std::string& labels, const std::string& images);

private:
  uint32_t revu32(uint32_t x) const;

  std::vector<MNISTDigit> m_digits;
};

#endif // MNISTDATA_H_
