
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Node{
    public:
    string data;
    Node*next;Node* back;
    Node(string data1,Node*next1=nullptr,Node*back1=nullptr){
        data=data1;
        next=next1;
        back=back1;
    }
};


class BrowserHistory
{
    public:
        Node*currentPage;
        Node* head;
    BrowserHistory(string homepage)
    {
        head=new Node(homepage);
        currentPage=head;

    }

    void visit(string url)
    {
        Node* newNode=new Node(url);
        newNode->back=currentPage;
        currentPage->next=newNode;
        currentPage=newNode;
    }

    string back(int steps)
    {
            while(steps){
            if(currentPage->back)currentPage=currentPage->back;
            else break;
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
            while(steps){
            if(currentPage->next)currentPage=currentPage->next;
            else break;
            steps--;
        }
        return currentPage->data;
    }

    void displayCurrentPage(){
        cout<<"You are on "<<currentPage->data<<endl;
    }
    void displayHistory() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << (temp == currentPage ? " <- current" : "") << endl;
            temp = temp->next;
        }
    }
    void deleteList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
        currentPage = nullptr;
    }


    void saveSession(){
        ofstream outf("session.txt");
        Node* temp=head;
        while(temp){
            outf<<temp->data<<endl;
            temp=temp->next;
        }
        outf.close();
    }

    void loadSession(){

        deleteList();//deleting the previous list before calling...
        ifstream inf("session.txt");
         Node* temp = nullptr;
        string url;

        while (inf >> url) {  // Reads one word at a time, avoiding the use of eof()
            if (temp == nullptr) {
                head = new Node(url);
                temp = head;
            } else {
                Node* newNode = new Node(url);
                temp->next = newNode;
                newNode->back = temp;
                temp = newNode;
            }
        }
        currentPage = temp;  // Set current to the last node
        inf.close();

        // If the file was empty, reset to an empty state
        if (head == nullptr) {
            head = new Node("homepage.com");
            currentPage = head;
        }
    }

};


int main(){
    BrowserHistory browser("Homepage.com");
    string command;
    while(true){
        cout << "\nCommands: visit [url], back [steps], forward [steps], display, history, save, load, exit" << std::endl;
        cin>>command;

        if(command=="visit"){
            string url;
            cout<<"enter your url"<<endl;
            cin>>url;
            browser.visit(url);
        }
        else if(command=="back"){
            int steps;
            cout<<"enter the steps to move back"<<endl;
            cin>>steps;
            cout<<browser.back(steps)<<endl;  
        }
        else if(command=="forward"){
            int steps;
            cout<<"enter the steps to move forward";
            cin>>steps;
            cout<<browser.forward(steps)<<endl;
        }
        else if(command=="display"){
            browser.displayCurrentPage();
        }
        else if(command=="history"){
            browser.displayHistory();
        }
        else if(command=="save"){
            browser.saveSession();
            cout<<"saved.";
        }
        else if(command=="load"){
             browser.loadSession();
            cout << "Session loaded." << std::endl;
        }
        else if(command=="exit"){
            break;
        }
        else{
            cout<<"Invalid command"<<endl;
        }
        
    }
}