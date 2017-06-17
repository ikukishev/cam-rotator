#ifndef ESP_CONFIG_HPP
#define ESP_CONFIG_HPP

#include <Servo.h>

class ServoEngine
{
public:
  ServoEngine() : msMin(0), msMax(0), msMid(0), pin(-1), used(false) { }
  ServoEngine(int amin, int amax, int amid, int apin) 
    : msMin(amin), msMax(amax), msMid(amid), pin(apin), used(true)
  { }

  int getMin() const { return msMin; }
  int getMax() const { return msMax; }
  int getMid() const { return msMid; }
  int getPin() const { return pin; }
  bool getUsing() const { return used; }
  
  void setMin(int val) { msMin = val; }
  void setMax(int val) { msMax = val; }
  void setMid(int val) { msMid = val; }
  void setPin(int val) { pin = val; }
  void setUsing(bool val) { used = val; }

private:
  int msMin;
  int msMax;
  int msMid;
  int pin;
  bool used;
};


#define MAX_PASS_SIZE 32
#define MAX_SSID_SIZE 32

class Config
{
private:
  Config();
  
public:
  
  ~Config();
  static Config& get() {
    return conf;
  }

  static void save() {
    conf.persist();
  }
  
  

  const char* getSsid() const {
    return mSsid;
  }

  const char* getPassword() const {
    return mSsid;
  }

  void setSsid(const char * ssid);
  void setPassword(const char * password);

  ServoEngine& getServoLong() { return mLongitudeServo; }
  ServoEngine& getServoLat() { return mLatitudeServo; }
  ServoEngine& getServoZoom() { return mZoomServo; }
  

private:
  void persist() const ;
  
  char mSsid[ MAX_SSID_SIZE ];
  char mPassword[ MAX_PASS_SIZE ];
  ServoEngine mLongitudeServo;
  ServoEngine mLatitudeServo;
  ServoEngine mZoomServo;

  static Config conf;
};

#endif
