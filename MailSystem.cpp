#include <bits/stdc++.h>
using namespace std;

class Email{
    private:
        string sender;
        string reciever;
        vector<string> mail;

    public:
        Email(string sender,string reciever,const vector<string>& mail)
            {
                this -> sender = sender;
                this -> reciever = reciever;
                this -> mail = mail;
            }

        void print()
            {
                cout << sender << " sent to " << reciever << " perfectly" << endl;
                return;
            }

        void getReciever()
            {
                cout << this -> reciever << "  -> " ;
                return;
            }

        void getSender()
            {
                cout << this -> sender << "  -> " ;
                return;
            }

        void getMail()
            {
                for(string M : mail) 
                    {
                        cout << M;
                    }
                cout << endl;
                return;
            }
};


class Person{
    private:
        string email;
        string name;
        string password;
        string number;
        vector<Email> SentMailBox;
        vector<Email> RecieveMailBox;

    
    public:
    Person(string email,string name,string password,string number)
        {
            this -> email = email;
            this -> name = name;
            this -> password = password;
            this -> number = number;
        }

    
    void sendMail(Person* reciever,const vector<string>& Mail)
        {
             Email newMail(this -> email,reciever -> email,Mail);
             newMail.print();
             this -> SentMailBox.push_back(newMail);
             reciever -> RecieveMailBox.push_back(newMail);
        }

    void ShowMailBox()
        {
            string password;
            do
            {
                cout << "Enter the password : " ;
                cin >> password ;
            } while (password != this -> password);

            int send = 0 , recieved = 0,count = 1;

            cout << "Recieved form " << endl;
            for(Email mail : RecieveMailBox)
                {
                    cout << count << " -> " ;
                    mail.getSender() ;
                    mail.getMail();
                    recieved++;
                    count++;
                }
            cout << endl << endl;


            cout << "Send to  " << endl;
            count = 1;
            for(Email mail : SentMailBox)
                {
                    cout << count << " -> ";
                    mail.getReciever();
                    mail.getMail();
                    send++;
                    count++;
                }
            cout << endl << "Total    : " << send + recieved << endl;
            cout << "Sended   : " << send << endl;
            cout << "Recieved : " << recieved << endl;
            return;
        }


        void DeleteEmail()
            {
                ShowMailBox();
                string choice;
                do
                {
                    cout << "Enter recieve or sent ";
                    cin >> choice;
                } while (choice != "recieve" && choice != "sent");
                
                int target;
                cout << "Enter which one you want to delete ";
                cin >> target;

                if(choice == "recieve")
                    {
                       RecieveMailBox.erase(RecieveMailBox.begin() + target - 1);
                    }
                else
                    {
                        SentMailBox.erase(SentMailBox.begin() + target - 1);
                    }
                cout << choice << " " << target << " deleted succesfully" << endl;
                return;
            }


        

        void ChangePassword()
            {
                string number;
                do
                {
                   cout << "Enter Number ";
                   cin >> number;
                } while (number != this -> number);
                
                int randomNumber = rand() % 9999 + 1000;
                cout << "The OTP is " << randomNumber ;
                cout << endl << "Enter the OTP ";
                int myNumber;
                do
                {
                    cin >> myNumber;
                } while (myNumber != randomNumber);
                string newPassword1,newPassword2;
                do
                {
                    cout << "Enter the new Password " ;
                    cin >> newPassword1;
                    cout << "Enter the password again ";
                    cin >> newPassword2 ;
                } while (newPassword1 != newPassword2);
                this -> password = newPassword1;
                cout << "Password changed Succesfull " << endl;
                return;
            }
}; 





int main()
{
    // Email* e = new Email("bsse1527@iit.du.ac.bd","sakibSir@iit.du.ac.bd",{"buibvsd"});
    // e -> print();
    Person* Nafish = new Person("bsse1527@iit.du.ac.bd","nafish","iit123","0152179");
    Person* Sir = new Person("sir@iit.du.ac.bd","Sir","iit1234","0186321");
    Nafish -> sendMail(Sir,{"Sir assalmualakum"});
    Person* Kamal = new Person("bsse1627@iit.du.ac.bd","Kamal","123iit","01521765");
    Sir -> sendMail(Kamal,{"Kalke exam"});
    Sir -> sendMail(Nafish,{"Walaikum Salam"});
    //Sir -> ShowMailBox();
    Sir -> DeleteEmail();
    Sir -> ShowMailBox();
    //Nafish -> ChangePassword();

    return 0;
}