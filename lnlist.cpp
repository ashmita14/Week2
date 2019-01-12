#include<iostream>
using namespace std;

class Node{
	//Data
	public:
	int data;
	//Pointer to the next Node
	Node *next;
	//Constuctor that makes the pointer to NULL
	public:
	Node(){
		next=NULL;
	}
	
	
};

class LinkedList{
	//Head + Cirles inside linked with each other
	//Head -> Node type pointer
	public:
	Node *head;
	Node *tail; //stores last element
	//Constructor
	public:
	LinkedList(){
		head=NULL; tail= NULL;
	}

	//Circles inside linked with each other
	//Rules how circles will be linked

	//Insert
	void insert(int value){
		//For adding the first node
		Node *temp= new Node;
		//insert data in the node
		temp->data= value;
		//1st Node only. So to be executed only if head is null.
		if(head==NULL){
		head=temp;
		}
		//Any other Node. If head is not null, then it is not the first node.
		else{
		tail->next=temp;
		}
		tail=temp; //tail of the current node functions as the tail of the last node in the next turn, when the previous statement is 					executed.
	}

	//Deletion of the last element
	void del(){
		//store the tail in temp
		Node *temp=tail;
		Node *current=head;
		//before tail has to point to null, i.e. second last element
		while(current->next !=tail){
			current=current->next;
		}
		current->next=NULL;
		//update tail
		tail=current;
		//delete temp
		delete temp;
	}

	//Insertion at a point
	void InsertAt(int pos, int value){
		//Reach the place before the position
		Node *current=head;
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		if(current->next==NULL || current==NULL){
			cout<<"Linked List does not have that many elemnts."<<endl;
		}
		//create a node
		Node *temp= new Node;
		temp->data=value;
		temp->next=current->next;
		current->next=temp;
	}

	//Deletion at a point
	void DelAt(int pos){
		//Reach the place before the position
		Node *current=head;
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//create pointers for storing the address of the Node to be delete and the address of the next Node
		Node *temp=current->next;
		Node *temp1=temp->next;
		current->next=temp1;
		//Removing the required Node from the linked list
		temp->next=NULL; 
		delete temp; 
	}

	//Count the number of items in the linked list
	int countItems(){
		//counter variable
		int c=0;
		//pointer of Node type to move through the linked list
		Node *ptr=head;
		//loop to move through the linked list
		while(ptr!=NULL){
			c++;
			ptr=ptr->next;
		}
		//returning the value
		return c;
	}

	//Display
	void display(){
		Node *current=head;
		while(current!=NULL){
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<"NULL";
		cout<<endl;
		cout<<endl;
	}

};

int main(){
	//creating object
	LinkedList l1;
	//Inserting elements in the linked list and displaying
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	cout<<endl;
	cout<<"Original Linked List."<<endl;
	l1.display();
	//Counting the number of elements in the original linked List and displaying
	int cn=l1.countItems();
	cout<<"Number of elements in original Linked List = "<<cn<<endl;
	cout<<endl;
	//Deleting last element and displaying
	l1.del();
	cout<<"Linked List after deleting last element."<<endl;
	l1.display();
	//Inserting an element at the 3rd position and displaying
	l1.InsertAt(3, 6);
	cout<<"Linked List after inserting 6 at the 3rd position."<<endl;
	l1.display();
	//Deleting node from 2nd position and displaying
	l1.DelAt(2);
	cout<<"Linked list after deleting element from 2nd position."<<endl;
	l1.display();
	return 0;
}

