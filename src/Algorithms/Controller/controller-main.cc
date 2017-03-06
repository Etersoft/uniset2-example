#include <UniSetActivator.h>
#include <UHelpers.h>
#include "UniSetExampleConfiguration.h"
#include "Controller.h"
// -----------------------------------------------------------------------------
using namespace uniset;
using namespace std;
// -----------------------------------------------------------------------------
int main( int argc, const char** argv )
{
	try
	{
		auto conf = uniset_init(argc, argv);
		auto act = UniSetActivator::Instance();

		auto cn = uniset::make_object<Controller>("Controller1", "Controller");
		act->add(cn);

		SystemMessage sm(SystemMessage::StartUp);
		act->broadcast( sm.transport_msg() );

		act->run(false);
		return 0;
	}
	catch( const uniset::Exception& ex )
	{
		cerr << "(controller): " << ex << endl;
	}
	catch( const std::exception& ex )
	{
		cerr << "(controller): " << ex.what() << endl;
	}
	catch(...)
	{
		cerr << "(controller): catch(...)" << endl;
	}

	return 1;
}
// -----------------------------------------------------------------------------
