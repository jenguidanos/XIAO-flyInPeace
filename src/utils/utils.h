/**
 *  @brief Utilities declarations
 *  @author Cooked by vabarca (TT)
 */

#ifndef UTILS_H
#define UTILS_H

//---[ Includes: ]--------------------------------------------------------------

#include <commons.h>

//---[ Typedefs: ]--------------------------------------------------------------

class CMovAvg : public CfipObj
{
  private:
    float *_buffer;
    static float _calculate(float *buff, int size);
    uint8_t _size;
    uint8_t _movAvgIndex;
    float _movAvg;

  public:
    CMovAvg() : CMovAvg(32)
    {
    }
    CMovAvg(uint8_t size) : _buffer{nullptr}, _size{size}, _movAvg{0.0f}, _movAvgIndex{0}
    {
    }
    ~CMovAvg();
    err_code_t setup() override;
    void update() override;
    void push(float val);
    float get() const
    {
        return _movAvg;
    }
};

//------------------------------------------------------------------------------

#endif /* UTILS_H */
