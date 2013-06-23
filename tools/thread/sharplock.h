#ifndef SHARPLOCK_H
#define SHARPLOCK_H

#include <SFML/System/Lock.hpp>

#define cslock(x) if (!(sf::Lock _l(x))); else

#endif // SHARPLOCK_H