#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

enum Actions{
	Left,
	Right,
	suck
};

struct Node
{
		char Name;
		int State;
		int Depth;
		Node *Parent;
		double PathCost;
		Actions Action;
		Node *prev;
		Node *next;
		
		Node *Array[100]; 
		
		Node* Child_Node(Node *parent,Actions action)
		{
			Node *ChildNode = new Node;
			ChildNode->State = 1; 
			ChildNode->PathCost = Step_Cost(State,action);
			ChildNode->Parent = Parent;
			ChildNode->Action = action;
			
				if(action == Left)
				{
					cout<<"Child Created due to action : Left"<<endl;
				}
				else if(action == Right)
				{
					cout<<"Child Created due to action : Right"<<endl;
				}
				else
				{
					cout<<"Child Created due to action : Suck"<<endl;
				}
			
			cout<<"Child Parent Address :"<<ChildNode->Parent<<endl;
			cout<<"Child State :"<<ChildNode->State<<endl;
			cout<<"Child Address :"<<ChildNode<<endl;
			cout<<"Child Path Cost :"<<ChildNode->PathCost<<endl<<endl<<endl;
			
			return ChildNode;
		}
		
		double Step_Cost(int State,Actions a)
		{
				if(a == Left)
				{
					return 4;
				}
				else if(a == Right)
				{
					return 3;
				}
				else
				{
					return 7;
				}
		}
		
		Node* MAX(Node *parent,int Size)
		{
			int Min = 10;
			int Counter;
			Node *Minimum = new Node;
			Node *Temp = new Node;
			Minimum = parent->Array[0];
			Min = Minimum->PathCost;
			for(Counter = 1; Counter <= Size ; Counter ++)
			{
				Temp = parent->Array[Counter];
				if(Min > Temp->PathCost)
				{
						Minimum = parent->Array[Counter];
						Min = Minimum->PathCost;
				}
					
			}
			cout<<"\nMin Value is :"<< Min;
			return Minimum;
		}
		
	
};

int main()
{
		Node Root;
		Node Arr;
		Node *Max;
		int Counter = 0;
		for(int i = 0; i <= 2 ; i++)
 		{
			Arr.Array[Counter] = Root.Child_Node(&Root,static_cast<Actions>(i));
			Counter ++;
		}
	
		 Max = Arr.MAX(&Arr,Counter);
		 cout<<"\n\nAddress is :"<< Max;
		
		return 0;
}
