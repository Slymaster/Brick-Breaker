#ifndef OBSERVER_HH
#define OBSERVER_HH

/* Class Observer:
 * It notify that the daughter class must have an update method
 * Instance of this interface have to register themselves to subject
 * and also unregister.
 */

class Observer
{
public:
    virtual ~Observer();
    virtual void update()=0;
}

#endif
// NEED OBSERVABLE