
/**
 *  @brief Commons definitions and utils
 *  @author Cooked by vabarca (TT)
 */

#ifndef COMMONS_H
#define COMMONS_H

//---[ Includes: ]--------------------------------------------------------------

#include <sstream>

//---[ Typedefs: ]--------------------------------------------------------------

const float DEFAULT_SEA_LEVEL_PRESSURE{1013.25};
const float ABSOLUTE_ZERO{273.15f};

typedef enum err_code_e
{
    ERR_CODE_NONE,
    ERR_CODE_SETUP,

    ERR_CODE_MAX_NUM
} err_code_t;

class CfipObj
{
  public:
    CfipObj() = default;
    virtual ~CfipObj() = default;

    virtual void update(){};
    virtual err_code_t setup()
    {
        return ERR_CODE_SETUP;
    }
};

class CfipBarometer : public CfipObj
{
  public:
    CfipBarometer() = default;
    virtual ~CfipBarometer() = default;

    virtual float get_pressure() const
    {
        return 0.0f;
    }
    virtual float get_temperature() const
    {
        return 0.0f;
    }
    virtual void print(std::stringstream &ss) const
    {
    }
};

class CfipVario : public CfipBarometer
{
  public:
    virtual void set_altitude(float altitude){};
    virtual float get_altitude() const
    {
        return 0.0f;
    }
    virtual float get_vario() const
    {
        return 0.0f;
    }
};

class CfipSound : public CfipObj
{
  public:
    virtual void set_vario(float vario){};
};

class CfipVisualizer : public CfipObj
{
  public:
    virtual void set_vario(float vario){};
};

//------------------------------------------------------------------------------

#endif /* COMMONS_H */
