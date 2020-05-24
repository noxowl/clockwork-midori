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
            void onHold(Inputs& inputs);
            void onPull(Inputs& inputs, CWMidori::Timer& timer);
            void onRelease(Inputs& inputs);
            int currentHands();
            bool isHolding();
            bool isPulling();

        private:
            static bool holding;
            static bool pulling;
            static bool main_hand;
            static int holding_hands;

            bool isSquareDown(Inputs& inputs);
            bool isLTriggerDown(Inputs& inputs);
            bool isRTriggerDown(Inputs& inputs);
            bool isYAxisDown(Inputs& inputs);
            bool isSquareUp(Inputs& inputs);
            bool isLTriggerUp(Inputs& inputs);
            bool isRTriggerUp(Inputs& inputs);
            bool isYAxisUp(Inputs& inputs);
            void setHold(const bool state);
            void setPull(const bool state);
            void setMainHand(const bool state);
            void addHands();
            void removeHands();
    };
}

#endif