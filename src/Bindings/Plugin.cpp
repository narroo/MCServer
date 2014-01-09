
#include "Globals.h"  // NOTE: MSVC stupidness requires this to be the same across all modules

#include "Plugin.h"





cPlugin::cPlugin(const AString & a_PluginDirectory) :
	m_Language(E_CPP),
	m_Name(a_PluginDirectory),
	m_Version(0),
	m_Directory(a_PluginDirectory)
{
}





cPlugin::~cPlugin()
{
	LOGD("Destroying plugin \"%s\".", m_Name.c_str());
}





AString cPlugin::GetLocalFolder(void) const
{
	return std::string("Plugins/") + m_Directory;
}

void cPlugin::Acquire(cPlugin * a_Plugin) {
	cCSLock Lock(a_Plugin->m_CS);
	a_Plugin->m_References++;
}

void cPlugin::Release(cPlugin *& a_Plugin) {
	cCSLock Lock(a_Plugin->m_CS);
	a_Plugin->m_References--;
	if (a_Plugin->m_References == 0 && !a_Plugin->m_UserLoaded) {
		delete a_Plugin;
		a_Plugin = NULL;
	}
}



