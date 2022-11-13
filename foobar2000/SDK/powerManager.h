#pragma once

namespace fb2k {
    class powerManager : public service_base {
    public:
        enum {
            flagStrong = 1 << 0,
            flagPlayback = 1 << 1,
            
            flagDisplay = flagStrong
        };

        //! Blocks device sleep for the duration of returned object's lifetime.
        //! By default we ask politely but can be still put to sleep by the OS. Specify flagStrong to force the device into awake state (possibly at cost of keeping the screen up).
        virtual objRef makeTask(const char* name, unsigned flags) = 0;

        //! Returns whether we're running on AC power (not on battery).
        virtual bool haveACPower() = 0;

        objRef makeTaskWeak(const char* name) { return makeTask(name, 0); }
        objRef makeTaskStrong(const char* name) { return makeTask(name, flagStrong); }
        objRef makePlaybackTask() { return makeTask("Playback", flagPlayback); }

        FB2K_MAKE_SERVICE_COREAPI(powerManager)
    };
}
