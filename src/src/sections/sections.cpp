#include "sections.h"

bool isRelayInverted(byte relayPin)
{
    switch (relayPin)
    {
    case 1:
    case 13:
    case 2:
        return true;
    }
    return false;
}

void setRelay(byte relayPin, bool state)
{
    if(isRelayInverted(relayPin)) state = !state;

    digitalWrite(relayPin, state);
}

void initSections()
{
    pinMode(relaySect0, OUTPUT);
    pinMode(relaySect1, OUTPUT);
    pinMode(relaySect2, OUTPUT);
    pinMode(relaySect3, OUTPUT);
    pinMode(relayPump, OUTPUT);
    pinMode(relayCommonWire, OUTPUT);

    disableAllSections();
}

int getSectionPinNumber(byte sectionNumber)
{
    switch (sectionNumber)
    {
    case 0:
        return relaySect0;
    case 1:
        return relaySect1;
    case 2:
        return relaySect2;
    case 3:
        return relaySect3;
    }

    // @error verification
    return -1;
}


void setActiveSection(byte sectionNumber)
{
    if(sectionNumber >= sectionCont) {
        // @error verification
        return;
    }

    disableAllSections();

    setRelay(relayCommonWire, HIGH);
    setRelay(getSectionPinNumber(sectionNumber), HIGH);
    setRelay(relayPump, HIGH);
}

void disableAllSections()
{
    setRelay(relayCommonWire, LOW);
    setRelay(relaySect0, LOW);
    setRelay(relaySect1, LOW);
    setRelay(relaySect2, LOW);
    setRelay(relaySect3, LOW);
    setRelay(relayPump, LOW);
}