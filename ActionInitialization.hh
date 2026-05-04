#ifndef ACTIONINITIALIZATION_HH
#define ACTIONINITIALIZATION_HH

#include "G4VUserActionInitialization.hh"
#include "particle.hh"
#include "runAction.hh"

class actioninit : public G4VUserActionInitialization
{
    public:
        actioninit();
        virtual ~actioninit();

        virtual void BuildForMaster() const;
        virtual void Build() const;
};

#endif