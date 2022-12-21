#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc < 2) return 0;

    std::string text = "";

    for (int i = 1; i < argc; i++) {
        text += argv[i];
        if (i != argc - 1) text += " ";
    }
    
    std::string bot_api = "";  // api of your telegram bot 
    std::string chat_id="";  // id of chat with target user


    std::string link="https://api.telegram.org/bot" + bot_api + "/sendMessage";

    std::string res_command = "curl -sSX POST " + link;
    res_command += " -H \'Content-type: application/json\'";
    res_command += " --data \'{\"chat_id\":\"" + chat_id + "\",";
    res_command += " \"text\":\"" + text + "\"}\'";

    std::cout << "Sent message is:\n" << text << "\n\n";

    system(res_command.c_str());

    return 0;
}
