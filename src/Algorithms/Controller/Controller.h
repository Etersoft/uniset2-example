#ifndef Controller_H_
#define Controller_H_
// -----------------------------------------------------------------------------
#include <string>
#include "Controller_SK.h"
// -----------------------------------------------------------------------------
/*!
    \page_Controller Процесс наполнения цистерны

	- \ref sec_controller_Common

	\section sec_controller_Common Описание алгоритма наполнения цистерны
		Процесс запускается по команде OnControl_s=1 и работает пока не наполнит цистерну, до уровня
	задаваемого в настройках параметром HiLevel. После этого начинает "опустошать" цистерну до уровня
	задаваемого в настройках параметров LowLoevel. И так по кругу. Если приходит команда OnControl_s=0,
	процесс управления останавливается
*/
class Controller:
	public Controller_SK
{
	public:
		Controller( UniSetTypes::ObjectId id, xmlNode* cnode, const std::string& prefix = "" );
		virtual ~Controller();

	protected:
		virtual void sensorInfo( const UniSetTypes::SensorMessage* sm ) override;
		virtual std::string getMonitInfo() override;

		// обработка (реализация логики)
		void processing();

	private:

};
// -----------------------------------------------------------------------------
#endif // Controller_H_
