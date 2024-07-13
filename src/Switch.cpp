#include "Switch.h"

namespace M3 {

    // Constructor. Loads the pin connected to the switch.
    Switch::Switch(int highOrLow, int pin) {
        setHighOrLow(highOrLow);
        m_switchPin = pin;
    }

    // Constructor. Loads the pin connect to the switch and the desired debounce delay.
    Switch::Switch(int highOrLow, int pin, int debounceDelay) {
        setHighOrLow(highOrLow);
        m_switchPin = pin;
        m_debounceDelay = debounceDelay;
    }

    // Function to configure the object as being a high or low activated switch.
    void Switch::setHighOrLow(int highOrLow) {
        // If we get a HIGH value then configure the object for high activation.
        if (highOrLow == HIGH) {
            m_currentState = LOW;
            m_lastState = LOW;
            m_pressedState = HIGH;

        // Otherwise, for anything else configure it for low activation.
        } else {
            m_currentState = HIGH;
            m_lastState = HIGH;
            m_pressedState = LOW;
        }
    }



    // Function used to return if the related switch is pressed or not. It contains all debounce logic.
    bool Switch::isSwitchPressed() {

        int readState = digitalRead(m_switchPin);           // Current state as of this function call.
        unsigned long currentMillis = millis();             // Current millis() counter as of this function call.
        bool ret = false;                                   // Return value

        // If the state changed then there was switch activity, so start the debounce timer.
        if (readState != m_lastState) {
            m_debounceTimer = currentMillis;
        }

        // See if the debounce delay has passed.
        if ((currentMillis - m_debounceTimer) >= m_debounceDelay) {
            // See if the switch state has changed.
            if (readState != m_currentState) {
                m_currentState = readState;
                
                // Return true only if the mode switch is still pressed.
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