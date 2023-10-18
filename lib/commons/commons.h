/** 
 *  @brief Commons definitions and utils
 *  @author Cooked by vabarca (TT)
 */

#ifndef COMMONS_H
#define COMMONS_H

//---[ Typedefs: ]--------------------------------------------------------------

const float SEA_LEVEL_PRESSURE {1013.25};
const float ABSOLUTE_ZERO {273.15f};

typedef enum err_code_e
{   
    ERR_CODE_NONE,
    ERR_CODE_SETUP,

    ERR_CODE_MAX_NUM
}err_code_t;

class Cfip_barometer
{
public:
    Cfip_barometer()= default;
    virtual ~Cfip_barometer()= default;

    virtual void update() {};
    virtual err_code_t setup() {return ERR_CODE_SETUP;}
    virtual float get_pressure() const {return 0.0f;}
    virtual float get_temperature() const {return 0.0f;}
};

class Cfip_vario : public Cfip_barometer
{
public:
    virtual void set_altitude(float altitude) {};
    virtual float get_altitude() const {return 0.0f;}
    virtual void get_delta(float &h, float &t) {h = 0.0f; t = 0.0f;}
};

//------------------------------------------------------------------------------

#endif /* COMMONS_H */
