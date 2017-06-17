#include "Config.hpp"
#include <EEPROM.h>
#include <string.h>

//#define ADDR_SSID 0
//#define ADDR_PASS (ADDR_SSID+MAX_SSID_SIZE)

Config Config::conf;

Config::Config()
{
  EEPROM.begin(sizeof(Config));
  EEPROM.get(0, *this);
}

Config::~Config()
{
  persist();
}

void Config::persist() const 
{
  EEPROM.put(0,*this);
  EEPROM.commit();
}

void Config::setSsid(const char * ssid) 
{
  size_t size = strlen(ssid);
  if (size>0 && size<MAX_SSID_SIZE)
  {
    strcpy(mSsid, ssid);
  }
}

void Config::setPassword(const char * password)
{
  size_t size = strlen(password);
  if (size>0 && size<MAX_PASS_SIZE)
  {
    strcpy(mPassword, password);
  }
}



