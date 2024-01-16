
/** 
 *  @brief Commons definitions and utils
 *  @author Cooked by vabarca (TT)
 */

#ifndef COMMONS_H
#define COMMONS_H

//---[ Includes: ]--------------------------------------------------------------

#include <sstream>

//---[ Typedefs: ]--------------------------------------------------------------

const float DEFAULT_SEA_LEVEL_PRESSURE {1013.25};
const float ABSOLUTE_ZERO {273.15f};

typedef enum err_code_e
{   
    ERR_CODE_NONE,
    ERR_CODE_SETUP,

    ERR_CODE_MAX_NUM
}err_code_t;

class Cfip_obj
{
public:
    Cfip_obj()= default;
    virtual ~Cfip_obj()= default;

    virtual void update() {};
    virtual err_code_t setup() {return ERR_CODE_SETUP;}
};

class Cfip_barometer: public Cfip_obj
{
public:
    Cfip_barometer()= default;
    virtual ~Cfip_barometer()= default;

    virtual float get_pressure() const {return 0.0f;}
    virtual float get_temperature() const {return 0.0f;}
    virtual void print(std::stringstream& ss) const {}
};

class Cfip_vario : public Cfip_barometer
{
public:
    virtual void set_altitude(float altitude) {};
    virtual float get_altitude() const {return 0.0f;}
    virtual float get_vario() const {return 0.0f;}
};

class Cfip_sound : public Cfip_obj
{
public:
    virtual void set_vario(float vario) {};
};

class Cfip_visualizer : public Cfip_obj
{
public:
    virtual void set_vario(float vario) {};
};

//------------------------------------------------------------------------------

#endif /* COMMONS_H */
