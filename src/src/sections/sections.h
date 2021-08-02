#include <Arduino.h>

const byte relaySect0 = 7;
const byte relaySect1 = 6;
const byte relaySect2 = 8;
const byte relaySect3 = 9;
const byte relayPump = 4;
const byte relayCommonWire = 5;

const byte sectionCont = 4;

bool isRelayInverted(byte relayPin);
void setRelay(byte relayPin, bool state);

void initSections();
int getSectionPinNumber(byte sectionNumber);
void setActiveSection(byte sectionNumber);
void disableAllSections();