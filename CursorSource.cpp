	#include<iostream>
	#include<iomanip>
	using namespace std;

	struct Node {
		char val; //data part
		int next; //index to next element

	};		
	#define SIZE 10
	Node cursorArray[SIZE];

	int first;
	int last;
	void initializeCursor();
	void insert(char input);
	void displayCursor();
	void deleteNode(char input);
	void viewData();
	void viewFirst();
	void viewLast();

	void main()
	{

		char input;
		do
		{
			cout<<"Press <1> for Initialize Cursor"<<endl;
			cout<<"Press <2> to Insert Data"<<endl;
			cout<<"Press <3> to Display Cursor"<<endl;
			cout<<"Press <4> to Delete Data"<<endl;
			cout<<"Press <5> for View Inserted Data"<<endl;
			cout<<"Press <6> to View First Element"<<endl;
			cout<<"Press <7> to View Last Element"<<endl;

			cout<<"Press <e> or <E> for exit \nAny other key will be considered as Invalid"<<endl<<endl;
			cout<<"Enter your task no: ";
			cin>>input;

			system("CLS");

			switch (input)
			{

			case '1':
			{
				initializeCursor();
				displayCursor();
				break;
			}
			case '2':
			{
				char ch;
				cout << "enter character you want to insert in cursor" << endl;
				fflush(stdin);
				cin >> ch;
				insert(ch);
				displayCursor();

				break;
			}
			case '3':
			{
				displayCursor();
				break;
			}
			case '4':
			{
				char ch;
				cout << "enter character you wnat to delete from cursor" << endl;
				fflush(stdin);
				cin >> ch;
				deleteNode(ch);
				displayCursor();
				break;
			}

			case '5':
			{
				viewData();
				break;
			}

			case '6':
			{
				viewFirst();
				break;
			}
			case '7':
			{

				viewLast();
				break;
			}
			case 'e':
			case 'E':
			{
				cout << "EXIT KEY PRESSED" << endl;
				exit(0);
			}

			default:
			{
				cout << "INVALID INPUT" << endl;
				break;

			}


			}

		}while(1);
	}
	void initializeCursor()
	{
		for(int i=0;i<SIZE;i++)
		{
			cursorArray[i].val='X';
			if(i==9)
				cursorArray[i].next=0;
			else
				cursorArray[i].next=i+1;
		}
		first=0;
		last=0;
	}
	void displayCursor()
	{
		cout<<"INDEX\t"<<"VALUE\t"<<"NEXT\t"<<endl;
		cout<<"----------------------"<<endl;
		for(int i=0;i<SIZE;i++)
		{
			cout<<"  "<<i<<"  \t "<<cursorArray[i].val<<"   \t "<<cursorArray[i].next<<endl;
		}
	}
	void insert(char input)
	{
		if(cursorArray[last].val!='X')
			{
				cout<<"memory full"<<endl;
				return;
		}
		if(first==last)
		{
			cursorArray[last].val=input;
			last=cursorArray[last].next;
		}
		else
		{
			cursorArray[last].val=input;
			last=cursorArray[last].next;
		}


	}
	void deleteNode(char input)
	{
		//cout<<"1"<<endl;
		int temp;
		int i=0;
		int j=12;
		for(i=0;i<SIZE;i++)
		{
			if(cursorArray[i].val=='X')
				continue;
			if(cursorArray[i].val!=input&&cursorArray[i].val!='X')
				j=i;
			if(cursorArray[i].val==input)
			{
				if(i==0)
				{
					first=cursorArray[i].next;
					cursorArray[i].next=last;
					cursorArray[i].val='X';
					cursorArray[last-1].next=i;
					last=i;
					//cursorArray[i-1].next=cursorArray[i].next;
					//cursorArray[i].next=temp;
					//last--;
					cout<<"node deleted"<<endl;
					break;

				}
				if(i==last-1)
				{
					//cout<<"last"<<endl;
					cursorArray[i].val='X';
					last=i;

				
				
					//last=i-1;
					//temp=cursorArray[i-1].next;
					//cursorArray[i-1].next=cursorArray[i].next;
					//cursorArray[i].next=temp;
					//last--;
					cout<<"node deleted"<<endl;
					break;
				}
				else 
				{
					cursorArray[j].next=cursorArray[i].next;
					cursorArray[i].val='X';
					cursorArray[i].next=last;
					cursorArray[last-1].next=i;
					last=i;
					//cout<<"middele"<<endl;
					//temp=cursorArray[i-1].next;
					//cursorArray[i-1].next=cursorArray[i].next;
					//cursorArray[i].next=temp;
					//cursorArray[i].val='X';
					//temp=cursorArray[i].next;
					//cursorArray[i].next=last;
					//last=temp;
					//last--;
					cout<<"node deleted"<<endl;
					break;
				}
			}
		}
		if(i==SIZE)
		{
			cout<<"Data not found in the cursor!!!"<<endl;
		}
	}
	void viewData()
	{
		cout<<"INDEX\t"<<"VALUE\t"<<"NEXT\t"<<endl;
		cout<<"----------------------"<<endl;
		for(int i=0;i<SIZE;i++)
		{
			if(cursorArray[i].val=='X')
				continue;
			cout<<"  "<<i<<"  \t "<<cursorArray[i].val<<"   \t "<<cursorArray[i].next<<endl;
		}
	}
	void viewFirst()
	{

		int i=first;
		if(cursorArray[i].val!='X')
			{
				cout<<"INDEX\t"<<"VALUE\t"<<"NEXT\t"<<endl;
				cout<<"  "<<i<<"  \t "<<cursorArray[i].val<<"   \t "<<cursorArray[i].next<<endl;
			}
		if(cursorArray[i].val=='X')
		{

			cout<<"Data not present in the cursor!!!"<<endl;
		}
	}
	void viewLast()
	{
		//cout<<last<<endl;
			int i=last-1;
		if(cursorArray[i].val!='X')
			{
				cout<<"INDEX\t"<<"VALUE\t"<<"NEXT\t"<<endl;
				cout<<"  "<<i<<"  \t "<<cursorArray[i].val<<"   \t "<<cursorArray[i].next<<endl;
			}
		if(cursorArray[i].val=='X')
		{

			cout<<"Data not present in the cursor!!!"<<endl;
		}
	}

