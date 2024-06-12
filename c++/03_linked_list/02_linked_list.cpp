#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

class Node{
	public:
	/* node contains value and pointer*/
		int value;
		Node* next;

	/* constructor -- the same name as the class 
	 * automatically called when a class object is created */
	Node(int value){
		this->value = value; /*setting value from input param*/
		this->next = nullptr;
	}
};


class LinkedList{
	/* private by default */
	private:
		Node* head;
		Node* tail;
		int length;
	
	public:
		/* constructor -- the same name as the class 
		 * making the first node */
		LinkedList(int value){
			Node* newNode = new Node(value);
			head = newNode;
			tail = newNode;
			length = 1;
		}

		/* destructor -- called when an object is deleted */
		/* Tilde symbol ~ indicates a destructor */
		~LinkedList(){
			Node* temp = head;
			while (head){
				/* moving head one node & delete temp which points at the ori head */
				head = head->next;
				delete temp;

				/* setting the new head as temp, repeat process */
				temp=head;
			}
		}

		void printList(){
			/* create temp to iterate through the list */
			Node* temp = head;
			while(temp != nullptr){
				cout << temp->value << endl;
				temp = temp->next;
			}
		}

		void getHead(){
			if (head == nullptr){
				cout << "Head : nullptr" << endl;
			} else {
				cout << "Head : " << head->value << endl;
			}	
		}

		void getTail(){
			if (tail == nullptr){
				cout << "Tail : nullptr" << endl;
			} else {
				cout << "Tail : " << tail->value << endl;
			}
		}

		void getLength(){
			cout << "Length : " << length << endl;
		}

		void append(int value){
			/* Node* temp = tail; */

			Node* myNode = new Node(value);
			
			/* check if list is empty */
			if (head == nullptr && tail == nullptr)
			/* also : if (length == 0) */
			{
				/* if list was empty, head & tail will point to the new node */
				head = myNode;
				tail = myNode;

			} else {
				tail->next = myNode;
				tail = myNode;
			}
			length++;
		}

		void deleteLast(){
			if (length == 0){
				return;
			}
			
			Node* temp = head;
			Node* pre  = head;

			while (temp->next != nullptr){
				pre  = temp;
				temp =  temp->next;
			}
				
			tail = pre;
			tail->next =  nullptr;
			length--;
			
			/* check if length is 0 after deleting tail */
			if (length ==0){
				head = nullptr;
				tail = nullptr;
			}
			delete temp;
		}

		void prepend(int value){
			
			Node* myNode = new Node(value);
			
			if (length == 0) {
				head = myNode;
				tail = myNode;
				// tail->next = nullptr;
			} else {
				// placing new to a pointer that points to head
				myNode->next = head;

				// setting the new node as head
				head = myNode;
			}
			length++;
		}

		void deleteFirst(){
			if (length==0) return;
		
			/* setting var temp to head - target deletion */
			Node* temp = head;
			if(length==1){
				head = nullptr;
				tail = nullptr;
			} else{
				head = head->next;
			} 
			delete temp;
			length--;
		}

		Node* get(int index){
			if (index <0 || index >=length){
				return nullptr;
			}

			Node* temp = head;
			for (int i =0; i<index; i++){
				temp = temp->next;
			}
			return temp;
		}

		bool set(int index, int value){
			
			Node* temp = get(index);
			if (temp) {
				temp->value = value;
				return true;
			}
			return false;
		}

		bool insert(int index, int value){
			if (index <0 || index >length) return false;
			else if (index ==0){
				prepend(value);
				return true;
			} else 
			if (index==length){
				append(value);
				return true;
			}
			
			/*creating a new node*/
			Node* newNode = new Node(value);
			
			/* setting temp as index-1
			 * need to get to a node BEFORE the index
			 * and set it pointing to the new node
			*/

			Node* temp = get(index-1);
			newNode->next = temp->next;
			temp->next= newNode;
			length++;
			return true;
		}

		bool deleteNode(int index){
			if (index <0 || index >= length) return false;
			else if (index ==0){
				deleteFirst();
				return true;
			} else 
			if (index == length){
				deleteLast();
				return true;
			}

			Node* prev = get(index-1);
			Node* temp = prev->next; 
			
			prev->next = temp->next;
			delete temp;
			length--;
			return true;
		}

		void reverse(){
			Node* temp = head;
			head 	= tail;
			tail 	= temp;

			Node* after = temp->next;
			Node* prev = nullptr;

			for (int i =0; i < length; i++){
				after = temp->next;

				/*reverse the arrow backwards */
				temp->next = prev;

				prev = temp;
				temp = after;
			}
		}
};



int main(){
	LinkedList* myLinkedlist = new LinkedList(0);
	myLinkedlist->append(1);
	myLinkedlist->append(2);
	myLinkedlist->append(3);

	myLinkedlist->getHead();
	myLinkedlist->getTail();
	myLinkedlist->getLength();

	cout << "\nLinked List before deletion : " << endl;
	myLinkedlist->printList();

	/* DELETE LAST
	myLinkedlist->deleteLast();
        cout << "\nLinked List after first deleteLast : " << endl;
        myLinkedlist->printList();

        myLinkedlist->deleteLast();
        cout << "\nLinked List after second deleteLast : " << endl;
        myLinkedlist->printList();

        myLinkedlist->deleteLast();
        cout << "\nLinked List after third deleteLast : " << endl;
        myLinkedlist->printList();
	 */

	/* DELETE FIRST 
	cout << "\nLinked List after first deleteFirst : \n";
	myLinkedlist->deleteFirst();
	myLinkedlist->printList();

	cout << "\nLinked List after the second deleteFirst :\n";
	myLinkedlist->deleteFirst();
	myLinkedlist->printList();

	cout << "\nLinked List after the third deleteFirst :\n";
	myLinkedlist->deleteFirst();
	myLinkedlist->printList();
	*/

	cout << "\nGet node value for index no.2 : \n";
	cout << myLinkedlist->get(2)->value << endl;

	cout << "\nSet value for index 1 : \n";
	myLinkedlist->set(1,100);
	myLinkedlist->printList();

	cout << "\nInsert a new node at index 2 : \n";
	myLinkedlist->insert(2, 200);
	myLinkedlist->printList();

	cout << "\nDelete node index 2 : \n";
	myLinkedlist->deleteNode(2);
	myLinkedlist->printList();
	
	cout << "\nReversing linked list :\n";
	myLinkedlist->reverse();
	myLinkedlist->printList();

	return 0;
}
