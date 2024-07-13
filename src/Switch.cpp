#include "Switch.h"

namespace M3 {

    Switch::Switch(int highOrLow, int pin) {
        setHighOrLow(highOrLow);
        m_switchPin = pin;
    }

    Switch::Switch(int highOrLow, int pin, int debounceDelay) {
        setHighOrLow(highOrLow);
        m_switchPin = pin;
        m_debounceDelay = debounceDelay;
    }

    void Switch::setHighOrLow(int highOrLow) {
        if (highOrLow == HIGH) {
            m_currentState = LOW;
            m_lastState = LOW;
            m_pressedState = HIGH;
        } else {
            m_currentState = HIGH;
            m_lastState = HIGH;
            m_pressedState = LOW;
        }
    }



    bool Switch::isSwitchPressed() {

        int readState = digitalRead(m_switchPin);           
        unsigned long currentMillis = millis();             
        bool ret = false;                                   

        // Whenever the state is changing, then the switch contacts have changed or are bouncing. 
        // As long as the state changes, keep resetting the debouce timer. We need a full debounce 
        // delay of unchanging state to occur before we move into the following logic areas.
        if (readState != m_lastState) {
            m_debounceTimer = currentMillis;
        }

        // The state is steady, so we can actually evaluate the switch.
        if ((currentMillis - m_debounceTimer) >= m_debounceDelay) {
            // A state change must have happened for us to move farther into the check. In other words if we had
            // already reported a switch press then we are not going to do it again. You would have to re-press the
            // switch to get a possible true return again. We are looking for transitions to pressed, not steady press and hold.
            if (readState != m_currentState) {
                m_currentState = readState;
                
                // Return true only if the mode switch is in whatever state we consider to be pressed.
                if (m_currentState == m_pressedState) {
                    ret = true; 
                }
            } 
        }

        // Update the m_lastState to the readState.
        m_lastState = readState;

        return ret;
    }

}