
#include "Globals.h"  // NOTE: MSVC stupidness requires this to be the same across all modules

#include "PluginHandle.h"
#include "Plugin.h"

cPluginHandle::cPluginHandle(cPlugin * a_Plugin) : m_Plugin(a_Plugin),m_PluginLoaded(true)
{
	cPlugin::Acquire(m_Plugin);
}

cPluginHandle::cPluginHandle(const cPluginHandle & a_PluginHandle) 
{
	m_Plugin = a_PluginHandle.m_Plugin;
	m_PluginLoaded =a_PluginHandle.m_PluginLoaded;
	cPlugin::Acquire(m_Plugin);
}

cPluginHandle::~cPluginHandle() 
{
	cPlugin::Release(m_Plugin);
}
