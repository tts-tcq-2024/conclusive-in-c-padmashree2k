#include "typewise-alert.h"
#include <stdio.h>

typedef struct {
    double lowerLimit;
    double upperLimit;
} CoolingLimits;

CoolingLimits getCoolingLimits(CoolingType coolingType) {
    switch(coolingType) {
        case PASSIVE_COOLING: return {0, 35};
        case HI_ACTIVE_COOLING: return {0, 45};
        case MED_ACTIVE_COOLING: return {0, 40};
        default: return {0, 0}; // Fallback for safety
    }
}

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
    if(value < lowerLimit) {
        return TOO_LOW;
    }
    if(value > upperLimit) {
        return TOO_HIGH;
    }
    return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
    CoolingLimits limits = getCoolingLimits(coolingType);
    return inferBreach(temperatureInC, limits.lowerLimit, limits.upperLimit);
}

void sendAlert(BreachType breachType, AlertTarget alertTarget) {
    switch(alertTarget) {
        case TO_CONTROLLER:
            sendToController(breachType);
            break;
        case TO_EMAIL:
            sendToEmail(breachType);
            break;
    }
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
    sendAlert(breachType, alertTarget);
}

void sendToController(BreachType breachType) {
    const unsigned short header = 0xfeed;
    printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
    const char* recipient = "a.b@c.com";
    switch(breachType) {
        case TOO_LOW:
            printf("To: %s\n", recipient);
            printf("Hi, the temperature is too low\n");
            break;
        case TOO_HIGH:
            printf("To: %s\n", recipient);
            printf("Hi, the temperature is too high\n");
            break;
        case NORMAL:
            break;
    }
}
