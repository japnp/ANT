#include "AntApp.h"
#include "Moose.h"
#include "AppFactory.h"

template<>
InputParameters validParams<AntApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

AntApp::AntApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  AntApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  AntApp::associateSyntax(_syntax, _action_factory);
}

AntApp::~AntApp()
{
}

void
AntApp::registerApps()
{
  registerApp(AntApp);
}

void
AntApp::registerObjects(Factory & factory)
{
}

void
AntApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
