#ifndef PHG4Hit_H__
#define PHG4Hit_H__

#include <phool/PHObject.h>
#include <cmath>
#include <climits>

class PHG4Hit: public PHObject
{
 public:
  PHG4Hit() {}
  virtual ~PHG4Hit() {}

  virtual void identify(std::ostream& os = std::cout) const;
  virtual void Copy(PHG4Hit const &g4hit);
  friend ostream &operator<<(ostream & stream, const PHG4Hit * hit);

  // The indices here represent the entry and exit points of the particle
  virtual float get_x(const int i) const {return NAN;}
  virtual float get_y(const int i) const {return NAN;}
  virtual float get_z(const int i) const {return NAN;}
  virtual float get_px(const int i) const {return NAN;}
  virtual float get_py(const int i) const {return NAN;}
  virtual float get_pz(const int i) const {return NAN;}
  virtual float get_t(const int i) const {return NAN;}
  virtual float get_edep() const {return NAN;}
  virtual float get_eion() const {return NAN;}
  virtual float get_light_yield() const {return NAN;}
  virtual float get_path_length() const {return NAN;}
  virtual unsigned int get_layer() const {return UINT_MAX;}
  virtual unsigned long long get_hit_id() const {return ULONG_LONG_MAX;}
  virtual int get_scint_id() const {return INT_MIN;}
  virtual int get_trkid() const {return INT_MIN;}
  virtual int get_strip_z_index() const {return INT_MIN;}
  virtual int get_strip_y_index() const {return INT_MIN;}
  virtual int get_ladder_z_index() const {return INT_MIN;}
  virtual int get_ladder_phi_index() const {return INT_MIN;}
  virtual int get_index_i() const {return INT_MIN;}
  virtual int get_index_j() const {return INT_MIN;}
  virtual int get_index_k() const {return INT_MIN;}
  virtual int get_index_l() const {return INT_MIN;}

  virtual void set_x(const int i, const float f) {return;}
  virtual void set_y(const int i, const float f) {return;}
  virtual void set_z(const int i, const float f) {return;}
  virtual void set_px(const int i, const float f) {return;}
  virtual void set_py(const int i, const float f) {return;}
  virtual void set_pz(const int i, const float f) {return;}
  virtual void set_t(const int i, const float f) {return;}
  virtual void set_edep(const float f) {return;}
  virtual void set_eion(const float f) {return;}
  virtual void set_light_yield(const float lightYield){return;}
  virtual void set_path_length(const float pathLength){return;}
  virtual void set_layer(const unsigned int i) {return;}
  virtual void set_hit_id(const unsigned long long i) {return;}
  virtual void set_scint_id(const int i) {return;}
  virtual void set_trkid(const int i) {return;}
  virtual void set_strip_z_index(const int i) {return;}
  virtual void set_strip_y_index(const int i) {return;}
  virtual void set_ladder_z_index(const int i) {return;}
  virtual void set_ladder_phi_index(const int i) {return;}
  virtual void set_index_i(const int i) {return;}
  virtual void set_index_j(const int i) {return;}
  virtual void set_index_k(const int i) {return;}
  virtual void set_index_l(const int i) {return;}

  virtual float get_avg_x() const;
  virtual float get_avg_y() const;
  virtual float get_avg_z() const;
  virtual float get_avg_t() const;

  virtual void print() const {std::cout<<"PHG4Hit base class - print() not implemented"<<std::endl;}


  //! add a short name to PHG4Hit::get_property_name
  enum PROPERTY {//

    //-- hit properties: 1 - 10  --
    //! ionizing energy loss
    prop_eion = 1,

    //! for scintillation detectors, the amount of light produced
    prop_light_yield = 2,

    //-- event properties: 10 - 20  --

    //! momentum
    prop_px = 10,
    prop_py ,
    prop_pz ,

    //! pathlength
    prop_path_length = 15,

    //-- detector specific IDs: 100+ --

    //! layer ID
    prop_layer = 101,
    //! scintillator ID
    prop_scint_id = 102,

    //! SVX stuff
    prop_strip_z_index = 110,
    prop_strip_y_index,
    prop_ladder_z_index,
    prop_ladder_phi_index,

    //! generic indexes
    prop_index_i = 121,
    prop_index_j ,
    prop_index_k ,
    prop_index_l ,



    //! max limit in order to fit into 8 bit unsigned number
    prop_MAX_NUMBER = UCHAR_MAX
  };

  enum PROPERTY_TYPE 
{//
    type_int = 1,
    type_uint = 2,
    type_float = 3,
    type_unknown = -1
};

  virtual bool  has_property(const PROPERTY prop_id) const {return false;}
  virtual float get_property_float(const PROPERTY prop_id) const {return NAN;}
  virtual int   get_property_int(const PROPERTY prop_id) const {return INT_MIN;}
  virtual unsigned int   get_property_uint(const PROPERTY prop_id) const {return UINT_MAX;}
  virtual void  set_property(const PROPERTY prop_id, const float value) {return;}
  virtual void  set_property(const PROPERTY prop_id, const int value) {return;}
  virtual void  set_property(const PROPERTY prop_id, const unsigned int value) {return;}
  static std::pair<const std::string,PROPERTY_TYPE> get_property_info(PROPERTY prop_id);
  static bool check_property(const PROPERTY prop_id, const PROPERTY_TYPE prop_type);
  static std::string get_property_type(const PROPERTY_TYPE prop_type);

 protected:
  ClassDef(PHG4Hit,1)
};


inline float PHG4Hit::get_avg_x() const { return 0.5*(get_x(0)+get_x(1)); }
inline float PHG4Hit::get_avg_y() const { return 0.5*(get_y(0)+get_y(1)); }
inline float PHG4Hit::get_avg_z() const { return 0.5*(get_z(0)+get_z(1)); }
inline float PHG4Hit::get_avg_t() const { return 0.5*(get_t(0)+get_t(1)); }


#endif
