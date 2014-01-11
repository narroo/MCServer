
#include "Globals.h"  // NOTE: MSVC stupidness requires this to be the same across all modules

#include "PluginHandle.h"
#include "Plugin.h"

cPluginHandle::cPluginHandle(cPlugin * a_Plugin) : m_Plugin(a_Plugin)
{
	cPlugin::Acquire(m_Plugin);
}

cPluginHandle::cPluginHandle(const cPluginHandle & a_PluginHandle) 
{
	m_Plugin = a_PluginHandle.m_Plugin;
	cPlugin::Acquire(m_Plugin);
}

cPluginHandle::~cPluginHandle() 
{
	cPlugin::Release(m_Plugin);
}

const AString & cPluginHandle::GetName(void) const
{
	return m_Plugin->GetName();
}
