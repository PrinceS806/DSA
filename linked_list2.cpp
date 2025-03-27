#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class LinkedList{
    Node *start;
    public:
    LinkedList(){
        start=NULL;
    }
    void insert(int data){
        if(start==NULL){
            start=new Node;
            start->data=data;
            start->next=NULL;
        }
        else{
            Node *temp=start;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            Node *newnode=new Node;
            newnode->data=data;
            newnode->next=NULL;
            temp->next=newnode;

        }
    }
    void clear(){
        Node *temp;
        while(start!=NULL){
            temp=start;
            start=start->next;
            delete temp;
        }
        start = NULL;
    }
    LinkedList merge(LinkedList &L2){
        LinkedList L3;
        Node *temp1=start;
        Node *temp2=L2.start;

        while(temp1!=NULL){
            L3.insert(temp1->data);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            L3.insert(temp2->data);
            temp2=temp2->next;
        }
        return L3;
    }
    LinkedList Union(LinkedList &L2){
        LinkedList L3;
        Node *temp1=start;
        Node *temp2=L2.start;

        while(temp1!=NULL){
            L3.insert(temp1->data);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            Node *temp3=L3.start;
            bool found = 0;
            while(temp3!=NULL){
                if(temp3->data==temp2->data){
                    found=1;
                    break;
                }
                temp3=temp3->next;
            }
            if(found==0){
                L3.insert(temp2->data);
            }
            temp2 = temp2->next;
        }
        return L3;
    }
    LinkedList intersection(LinkedList &L2){
        LinkedList L3;
        Node *temp1=start;
        
        while(temp1!=NULL){
            Node *temp2=L2.start;
            while(temp2!=NULL){
                if(temp1->data==temp2->data){
                    L3.insert(temp1->data);
                    break;
                }
                temp2=temp2->next;
            }
        temp1=temp1->next;
        }

        return L3;
    }

    void display(){
        Node *temp=start;
        while(temp!=NULL){
            cout<<temp->data;
            if(temp->next!=NULL) cout<<",";
                temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList L1,L2,L3;
    int ch,data;
    do{
        cout<<"\n--Main Menu--"<<endl;
        cout<<"1: Insert in LinkedList 1\n2: Insert in LinkedList 2\n3: Display LinkedList 1\n4: Display LinkedList 2\n5: Display Merged LinkedList\n6: Display Union LinkedList\n7: Display Intersection LinkedList\n8: Exit\n\n";
        cout<<"Choose Menu Options: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter data in LinkedList 1: ";
                cin>>data;
                L1.insert(data);
                break;
            case 2:
                cout<<"Enter data in LinkedList 2: ";
                cin>>data;
                L2.insert(data);
                break;
            case 3:
                cout<<"Displaying LinkedList 1: ";
                L1.display();
                break;
            case 4:
                cout<<"Displaying LinkedList 2: ";
                L2.display();
                break;
            case 5:
                L3.clear();
                L3=L1.merge(L2);
                cout<<"Merging both LinkedList: ";
                L3.display();
                break;
            case 6:
                L3=L1.Union(L2);
                cout<<"Union of LinkedList: ";
                L3.display();
                break;
            case 7:
                L3=L1.intersection(L2);
                cout<<"Intersection of LinkedList: ";
                L3.display();
                break;
            case 8:
                cout<<"Exiting the Program..."<<endl;
                break;
            default:
                cout<<"Invalid Choice! Try again."<<endl;
        }

    }
    while(ch!=8);
    return 0;
}