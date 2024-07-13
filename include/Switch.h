
#ifndef Switch_897273787246_H
#define Switch_897273787246_H



#include "Arduino.h"

namespace M3 {
    
    class Switch {
    public:
        // Constructors.

        /**
         * @brief  Simple constructor that sets the switch object's high or low type and microcontroller pin.
         * @note   
         * @param  highOrLow: HIGH or LOW switch type.
         * @param  pin: Microcontroller pin that the switch is connected to.
         * @retval None
         */
        Switch(int highOrLow, int pin);

        /**
         * @brief  Constructor that sets the switch object's high or low type, microcontroller pin, and debounce delay.
         * @note   
         * @param  highOrLow: HIGH or LOW switch type.
         * @param  pin: Microcontroller pin that the switch is connected to.
         * @param  debounceDelay: Time in millis to allow the switch to debounce.
         * @retval None
         */
        Switch(int highOrLow, int pin, int debounceDelay);




        // Methods.

        /**
         * @brief  Check to see if the switch is pressed.
         * @note   
         * @retval true or false if the switch is pressed.
         */
        bool isSwitchPressed();

    
    private:
        // Private members.
        int m_switchPin { 0 };                  ///< Microcontroller pin that the switch is connected to.
        int m_debounceDelay { 50 };             ///< Time to let the switch settle in millis.
        unsigned long m_debounceTimer { 0ul };  ///< Value to track how long we have been waiting for the switch to debounce.
        int m_currentState { LOW };             ///< State that the switch is currently in.
        int m_lastState { LOW };                ///< State that the switch was in the last time we checked it.
        int m_pressedState { HIGH };            ///< What state should the switch be in to be considered pressed.




        // Private methods.

        /**
         * @brief  Configures the object as being a high or low activated switch.
         * @note   
         * @param  highOrLow: HIGH or LOW
         * @retval None
         */
        void setHighOrLow(int highOrLow);

    };

}


#endif