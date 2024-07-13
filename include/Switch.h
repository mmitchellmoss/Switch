
#ifndef Switch_897273787246_H
#define Switch_897273787246_H



#include "Arduino.h"

namespace M3 {

    class Switch {
    public:
        // Constructors.
        Switch(int highOrLow, int pin);
        Switch(int highOrLow, int pin, int debounceDelay);

        // Methods.
        bool isSwitchPressed();

    
    private:
        // Private members.
        int m_switchPin { 0 };
        int m_debounceDelay { 50 };
        unsigned long m_debounceTimer { 0ul };
        int m_currentState { LOW };
        int m_lastState { LOW };
        int m_pressedState { HIGH };

        // Private methods
        void setHighOrLow(int highOrLow);

    };

}


#endif