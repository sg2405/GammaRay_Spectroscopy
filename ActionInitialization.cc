#include "ActionInitialization.hh"

actioninit::actioninit()
{

}

actioninit::~actioninit()
{

}

void actioninit::BuildForMaster() const
{
    runAction *runaction = new runAction();
    SetUserAction(runaction);
}

void actioninit::Build() const 
{
    generator *gen = new generator();
    SetUserAction(gen);

    runAction *runaction = new runAction();
    SetUserAction(runaction);
}