#include <sstream>
#include <UniXML.h>
#include <Exceptions.h>
#include "Imitator.h"
// -----------------------------------------------------------------------------
using namespace UniSetTypes;
using namespace std;
// -----------------------------------------------------------------------------
Imitator::Imitator( UniSetTypes::ObjectId id, xmlNode* cnode, const string& prefix ):
	Imitator_SK(id, cnode, prefix)
{
	if( cnode == NULL )
		throw Exception( myname + "(Imitator): FAILED! not found confnode in confile!" );
}
// -----------------------------------------------------------------------------
Imitator::~Imitator()
{
}
// -----------------------------------------------------------------------------
void Imitator::sensorInfo( const UniSetTypes::SensorMessage* sm )
{
	if( sm->id == cmdLoad_c )
	{
		if( sm->value )
		{
			myinfo << myname << "(sensorInfo): команда на 'наполнение'..." << endl;
			askTimer(tmStep,stepTime); // запускаем таймер в работу
		}
	}
	else if( sm->id == cmdUnload_c )
	{
		if( sm->value )
		{
			myinfo << myname << "(sensorInfo): команда на 'опустошение'..." << endl;
			askTimer(tmStep,stepTime); // запускаем таймер в работу
		}
	}
}
// -----------------------------------------------------------------------------
void Imitator::timerInfo( const UniSetTypes::TimerMessage* tm )
{
	if( tm->id == tmStep )
	{
		if( in_cmdLoad_c ) // значит наполняем..
		{
			out_Level_s += stepVal;
			if( out_Level_s >= maxLevel )
			{
				out_Level_s = maxLevel;
				askTimer(tmStep,0); // останавливаем таймер (и работу)
			}
			return;
		}

		if( in_cmdUnload_c ) // значит опустошаем
		{
			out_Level_s -= stepVal;
			if( out_Level_s <= minLevel )
			{
				out_Level_s = minLevel;
				askTimer(tmStep,0); // останавливаем таймер (и работу)
			}
			return;
		}
	}
}
// -----------------------------------------------------------------------------
string Imitator::getMonitInfo()
{
	ostringstream s;

	s << "Текущий режим работы: " ;

	if( in_cmdLoad_c )
		s << " наполяем.." << endl;
	else if( in_cmdUnload_c )
		s << " опустошаем.." << endl;

	return std::move(s.str());
}
// -----------------------------------------------------------------------------

