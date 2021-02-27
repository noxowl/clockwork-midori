#ifndef CWMIDORI_APP_LOGIC_H_
#define CWMIDORI_APP_LOGIC_H_

#include "include/common/inputs.hpp"
#include "include/app/timer.hpp"

namespace CWMidori {
    class Logic {
        public:
            Logic();
            ~Logic();

            void onProcessing(CWMidori::Timer& timer);
            void onHold(Inputs& inputs, CWMidori::Timer& timer);
            void onPull(Inputs& inputs, CWMidori::Timer& timer);
            void onRelease(Inputs& inputs, CWMidori::Timer& timer);
            int currentHands();
            bool isHolding();
            bool isPulling();
            bool isHandling();

        private:
            static bool holding;
            static bool pulling;
            static bool handling;
            static int holdingHands;

            bool isSquareUp(Inputs& inputs);
            bool isSquareDown(Inputs& inputs);
            bool isCrossUp(Inputs& inputs);
            bool isCrossDown(Inputs& inputs);
            bool isLTriggerUp(Inputs& inputs);
            bool isLTriggerDown(Inputs& inputs);
            bool isRTriggerUp(Inputs& inputs);
            bool isRTriggerDown(Inputs& inputs);
            bool isYAxisUp(Inputs& inputs);
            bool isYAxisDown(Inputs& inputs);
            void setHold(const bool state);
            void setPull(const bool state);
            void setHandling(const bool state);
            void addHands();
            void removeHands();
    };
}

#endif