#pragma once

#include <WString.h>
#include <map>
#include <FS.h>

#include "Language.h"
#include "../../utility/FileUtility.h"

#define SETTINGS_FILE_NAME "/settings.json"

using namespace Utility;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class Settings
        {
        private:
            String _deviceName;
            String _wifiSSID;
            String _wifiPassword;
            Language _language;
            void deserialize(String jsonString);

        public:
            Settings() {}
            Settings(String jsonString);

            static Settings *fromFile(fs::FS &fs, const char *fileName);
            void save(fs::FS &fs, const char *fileName);

            String getDeviceName();
            void setDeviceName(String deviceName);
            String getWifiSSID();
            void setWifiSSID(String wifiSSID);
            String getWifiPassword();
            void setWifiPassword(String wifiPassword);
            Language getLanguage();
            void setLanguage(Language language);

            String serialize();
        };
    }
#ifdef __cplusplus
}
#endif