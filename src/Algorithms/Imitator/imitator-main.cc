#include <UniSetActivator.h>
#include <UHelpers.h>
#include "UniSetExampleConfiguration.h"
#include "Imitator.h"
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

		// Управление СЭС
		auto im = uniset::make_object<Imitator>("Imitator1", "Imitator");
		act->add(im);

		SystemMessage sm(SystemMessage::StartUp);
		act->broadcast( sm.transport_msg() );

		act->run(false);
		return 0;
	}
	catch( const uniset::Exception& ex )
	{
		cerr << "(imitator): " << ex << endl;
	}
	catch( const std::exception& ex )
	{
		cerr << "(imitator): " << ex.what() << endl;
	}
	catch(...)
	{
		cerr << "(imitator): catch(...)" << endl;
	}

	return 1;
}
// -----------------------------------------------------------------------------
