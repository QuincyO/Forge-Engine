#pragma once
#include <string>

namespace Time {

	/* Get current time in string format */
	std::wstring FORGE_API GetTime(BOOL stripped = FALSE);

	/* Get Current date in string format */
	std::wstring FORGE_API GetDate(BOOL stripped = FALSE);

	/* Get Current date and time in string format */
	std::wstring FORGE_API GetDateTimeString(BOOL stripped = FALSE);


}