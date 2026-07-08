/*
 * Flight Master's License
 * MIT License
 */

#include "ScriptMgr.h"
#include "Chat.h"
#include "CommandScript.h"

#include "Player.h"

namespace FML
{

using namespace Acore::ChatCommands;

class FlightMastersLicenseCommandScript : public CommandScript
{
public:

    FlightMastersLicenseCommandScript()
        : CommandScript("FlightMastersLicenseCommandScript")
    {
    }


    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable commandTable =
        {
            {
                "fml",
                HandleFMLCommand,
                SEC_PLAYER,
                Console::No
            }
        };

        return commandTable;
    }


private:

    static bool HandleFMLCommand(
        ChatHandler* handler,
        char const* args)
    {
        if (!args || !*args)
        {
            handler->SendSysMessage(
                "Flight Master's License commands:"
            );

            handler->SendSysMessage(
                ".fml status"
            );

            return true;
        }


        if (strcmp(args, "status") == 0)
        {
            handler->SendSysMessage(
                "Flight Master's License module loaded."
            );

            return true;
        }


        handler->SendSysMessage(
            "Unknown Flight Master's License command."
        );

        return true;
    }
};

}


void AddFMLCommandScripts()
{
    new FML::FlightMastersLicenseCommandScript();
}
