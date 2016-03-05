#ifndef Imitator_H_
#define Imitator_H_
// -----------------------------------------------------------------------------
#include <string>
#include "Imitator_SK.h"
// -----------------------------------------------------------------------------
/*!
    \page_Imitator Процесс имитирующий работу насоса (наполнение и опусташение цистерны)

    - \ref sec_imitator_Common

	\section sec_loadproc_Common Описание алгоритма имитатора
		По команде "наполнить"(cmdLoad_c) процесс начинает наполнять цистерну (увеличивать уровень).
		По команде "опусташить"(cmdUnload_c) процесс начинает опустошать цистерну (уменьшать уровень).
*/
class Imitator:
	public Imitator_SK
{
	public:
		Imitator( UniSetTypes::ObjectId id, xmlNode* cnode, const std::string& prefix = "" );
		virtual ~Imitator();

		enum Timers
		{
			tmStep
		};

	protected:
		virtual void sensorInfo( const UniSetTypes::SensorMessage* sm ) override;
		virtual void timerInfo( const UniSetTypes::TimerMessage* tm ) override;
		virtual std::string getMonitInfo() override;
		virtual std::string getTimerName(int id);

	private:
		unsigned int numCmdLoad = { 0 };
		unsigned int numCmdUnload = { 0 };

};
// -----------------------------------------------------------------------------
#endif // Imitator_H_
