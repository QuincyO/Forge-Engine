#include "Forge.h"


PerGameSettings* PerGameSettings::inst;


PerGameSettings::PerGameSettings()
{
	inst = this;

	wcscpy_s(this->m_GameName, L"undefined");
	wcscpy_s(this->m_ShortName, L"undefined");
	wcscpy_s(this->m_BootTime, Time::GetDateTimeString(TRUE).c_str());
}

PerGameSettings::~PerGameSettings()
{

}
