
/**
 *  @brief Commons definitions and utils
 *  @author Cooked by vabarca (TT)
 */

#ifndef COMMONS_H
#define COMMONS_H

//---[ Includes: ]--------------------------------------------------------------

#include <sstream>
#include <iomanip>

//---[ Typedefs: ]--------------------------------------------------------------

namespace vaf::fip
{

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

    virtual const char *objType()
    {
        return "CfipObj";
    };
    virtual void update(){};
    virtual void update(float value){};
    virtual err_code_t setup()
    {
        return ERR_CODE_SETUP;
    }
    virtual void print(std::stringstream &ss) const
    {
    }
};

class CfipBarometer : public CfipObj
{
  public:
    CfipBarometer() = default;
    virtual ~CfipBarometer() = default;

    const char *objType() override
    {
        return "CfipBarometer";
    };
    virtual float get_pressure() const
    {
        return 0.0f;
    }
    virtual float get_temperature() const
    {
        return 0.0f;
    }
};

class CfipVario : public CfipBarometer
{
  private:
    float max_value_;

  protected:
    float get_max_value() const
    {
        return max_value_;
    }

  public:
    CfipVario() : max_value_(10.0f)
    {
    }
    CfipVario(float max_value) : max_value_(max_value)
    {
        if (max_value_ <= 0)
            max_value_ = 10.0f;
    }
    virtual ~CfipVario() = default;
    const char *objType() override
    {
        return "CfipVario";
    };
    virtual void set_altitude(float altitude){};
    virtual float get_altitude() const
    {
        return 0.0f;
    }
    virtual float get() const
    {
        return 0.0f;
    }
    virtual float get_norm() const
    {
        return 0.0f;
    }
};

class CfipSound : public CfipObj
{
  public:
    virtual ~CfipSound() = default;
    const char *objType() override
    {
        return "CfipSound";
    };
};

class CfipVisualizer : public CfipObj
{
  public:
    virtual ~CfipVisualizer() = default;
    const char *objType() override
    {
        return "CfipVisualizer";
    };
};

class CfipCurve : public CfipObj
{
  private:
    float computed_value_;

  protected:
    void set_value_(float value)
    {
        computed_value_ = value;
    }
    float get_value_() const
    {
        return computed_value_;
    }

  public:
    virtual ~CfipCurve() = default;
    err_code_t setup() override
    {
        return ERR_CODE_NONE;
    }
    const char *objType() override
    {
        return "CfipCurve";
    };
    virtual float get() const
    {
        return get_value_();
    };
    virtual void print(std::stringstream &ss) const
    {
        ss << " Curve: " << std::setw(6) << std::fixed << std::setprecision(2) << get();
    }
};

class CfipButton : public CfipObj
{
  public:
    virtual ~CfipButton() = default;
    const char *objType() override
    {
        return "CfipButton";
    };
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* COMMONS_H */
