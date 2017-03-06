#include <sstream>
#include <UniXML.h>
#include <Exceptions.h>
#include "Controller.h"
// -----------------------------------------------------------------------------
using namespace uniset;
using namespace std;
// -----------------------------------------------------------------------------
Controller::Controller( uniset::ObjectId id, xmlNode* cnode, const string& prefix ):
	Controller_SK(id, cnode, prefix)
{
	if( cnode == NULL )
		throw Exception( myname + "(Controller): FAILED! not found confnode in confile!" );
}
// -----------------------------------------------------------------------------
Controller::~Controller()
{
}
// -----------------------------------------------------------------------------
void Controller::sensorInfo(const uniset::SensorMessage* sm)
{
	if( sm->id == OnControl_s )
	{
		if( sm->value )
		{
			myinfo << myname << "(sensorInfo): Команда начать работу.." << endl;
			if( in_Level_s > LowLevel && in_Level_s < HiLevel )
			{
				// по умолчанию "наполняем"
				out_cmdLoad_c = true;
				out_cmdUnload_c = false;
			}
			else
				processing();
		}
		else
		{
			myinfo << myname << "(sensorInfo): Команда завершить работу.." << endl;
			// сбрасываем все команды управления
			out_cmdLoad_c = false;
			out_cmdUnload_c = false;
		}
	}
	else if( sm->id == Level_s )
	{
		// если управление включено, то обрабатываем
		if( in_OnControl_s )
			processing();
	}
}

// -----------------------------------------------------------------------------
void Controller::processing()
{
	if( in_Level_s >= HiLevel )
	{
		myinfo << myname << "(sensorInfo): Достигнут верхний уровень(" << HiLevel << "). Начинаем опустошать.." << endl;
		// начинаем "опустоштать"
		out_cmdLoad_c = false;
		out_cmdUnload_c = true;
	}
	else if( in_Level_s <= LowLevel )
	{
		myinfo << myname << "(sensorInfo): Достигнут нижний уровень(" << LowLevel << "). Начинаем наполнять.." << endl;
		// начинаем "наполнять"
		out_cmdLoad_c = true;
		out_cmdUnload_c = false;
	}
}
// -----------------------------------------------------------------------------
string Controller::getMonitInfo()
{
	ostringstream s;
	s << "Hi! I`m user info..." << endl;

	return std::move(s.str());
}
// -----------------------------------------------------------------------------

