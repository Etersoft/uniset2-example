#ifndef UniSetExampleConfiguration_H_
#define UniSetExampleConfiguration_H_
// -------------------------------------------------------------------------
#include <memory>
#include <UniSetTypes.h>
#include <Configuration.h>
// -------------------------------------------------------------------------
namespace UniSetExample
{
	// Шаблон для "универсальной инициализации объекта(процесса)".
	// Использование:
	// auto m = make_object<MyClass>("ObjectId","secname");
	// --
	// Где MyClass должен содержать конструктор MyClass( const ObjetctId id, xmlNode* cnode, ...any args.. );
	// ---------------
	// Если secname задан, то ищется: <secname name="ObjectId" ....>
	// Если secname не задан, то: <idname name="idname" ...>
	//----------------
	template<typename T, typename... _Args>
	std::shared_ptr<T> make_object( const std::string& idname, const std::string& secname, _Args&&... __args )
	{
		auto conf = UniSetTypes::uniset_conf();
		UniSetTypes::ObjectId id = conf->getObjectID(idname);

		if( id == UniSetTypes::DefaultObjectId )
			throw UniSetTypes::SystemError("(make_object<" + string(typeid(T).name()) + ">): Not found ID for '" + idname + "'");

		auto xml = conf->getConfXML();
		std::string s( (secname.empty() ? idname : secname) );
		xmlNode* cnode = conf->findNode(xml->getFirstNode(),s,idname);

		if( cnode == 0 )
			throw UniSetTypes::SystemError("(make_object<" + string(typeid(T).name()) + ">): Not found xmlnode <" + s + " name='" + idname + "' ... >");

		std::shared_ptr<T> obj =std::make_shared<T>(id,cnode,std::forward<_Args>(__args)...);
		if (obj == nullptr)
			 throw UniSetTypes::SystemError("(make_object<T>  == nullptr" + string(typeid(T).name()));
		return obj;
	}
};
// -------------------------------------------------------------------------
#endif // UniSetExampleConfiguration_H_
